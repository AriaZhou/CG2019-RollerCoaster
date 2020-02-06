#include "Wheel.h"
#include <QVector3D>
#include <QVector2D>
#include <vector>

Wheel::Wheel()
{

}

Wheel::Wheel(float rr, float hh)
{
	r = rr;
	height = hh;
}

Wheel::~Wheel()
{}

void Wheel::DimensionTransformation(GLfloat source[], GLfloat target[][4])
{
	//for uniform value, transfer 1 dimension to 2 dimension
	int i = 0;
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			target[j][k] = source[i];
			i++;
		}
}
void Wheel::DimensionTransformation(glm::mat4 source, GLfloat target[][4])
{
	const float* ss = (const float*)glm::value_ptr(source);

	//for uniform value, transfer 1 dimension to 2 dimension
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			//qDebug() << ss[j * 4 + k];
			target[j][k] = ss[j * 4 + k];
		}
}
void Wheel::Begin()
{
	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();
}
void Wheel::Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix, glm::mat4 RotateMatrix, glm::mat4 TransformMatrix)
{
	GLfloat P[4][4];
	GLfloat MV[4][4];
	GLfloat R[4][4];
	GLfloat T[4][4];
	DimensionTransformation(ProjectionMatrix, P);
	DimensionTransformation(ModelViewMatrix, MV);
	DimensionTransformation(RotateMatrix, R);
	DimensionTransformation(TransformMatrix, T);

	//pass projection matrix to shader
	shaderProgram->setUniformValue("ProjectionMatrix", P);
	//pass modelview matrix to shader
	shaderProgram->setUniformValue("ModelViewMatrix", MV);
	shaderProgram->setUniformValue("RotationMatrix", R);
	shaderProgram->setUniformValue("TransformMatrix", T);

	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Enable Attribute 0
	shaderProgram->enableAttributeArray(0);
	// Set Attribute 0 to be position
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	vvbo.release();

	//// Bind the buffer so that it is the current active buffer
	//uvbo.bind();
	//// Enable Attribute 1
	//shaderProgram->enableAttributeArray(1);

	//shaderProgram->setAttributeArray(1, GL_FLOAT, 0, 2, NULL);
	//uvbo.release();

	//Draw triangles with 4 indices starting from the 0th index
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
void Wheel::End()
{
	//Disable Attribute 0&1
	shaderProgram->disableAttributeArray(0);
	//shaderProgram->disableAttributeArray(1);

	vao.release();
	shaderProgram->release();
}

void Wheel::Init()
{
	InitShader("./Shader/Wheel.vs", "./Shader/Wheel.fs");
	InitVAO();
	InitVBO();
	//InitTexture();
}
void Wheel::InitVAO()
{
	// Create Vertex Array Object
	vao.create();
	// Bind the VAO so it is the current active VAO
	vao.bind();
}
void Wheel::InitVBO()
{
	QVector<glm::vec3> wheelPosP;
	wheelPos = glm::vec3(0, 0, 0);
	wheelUp = glm::vec3(0, 0.8, 0);
	wheelDir = glm::vec3(1, 0, 0);
	glm::vec3 wheelHDir = glm::normalize(glm::cross(wheelUp, wheelDir));

	//Set each vertex's position
	wheelPosP << (wheelPos + wheelHDir * 2.5f + wheelUp * r)
			  << (wheelPos - wheelHDir * 2.5f + wheelUp * r);

	for (int i = 0; i < wheelPosP.size(); i++)
	{
		for (int j = 0; j < 360; j += 15)
		{
			float p1 = j * 3.14 / 180;
			float p2 = (j + 15) * 3.14 / 180;
			glm::vec3 nextPos1 = glm::normalize(glm::vec3(sin(p1), cos(p1), 0.0f))*r + wheelPosP[i];
			glm::vec3 nextPos2 = glm::normalize(glm::vec3(sin(p2), cos(p2), 0.0f))*r + wheelPosP[i];

			glm::vec3 a = nextPos1 + glm::vec3(0, 0, height);
			glm::vec3 b = nextPos1 + glm::vec3(0, 0, -height);
			glm::vec3 c = nextPos2 + glm::vec3(0, 0, height);
			glm::vec3 d = nextPos2 + glm::vec3(0, 0, -height);

			vertices << QVector3D(wheelPosP[i].x, wheelPosP[i].y, wheelPosP[i].z + height)
					<< QVector3D(nextPos1.x, nextPos1.y, nextPos1.z + height)
					<< QVector3D(nextPos2.x, nextPos2.y, nextPos2.z + height)
					<< QVector3D(wheelPosP[i].x, wheelPosP[i].y, wheelPosP[i].z - height)
					<< QVector3D(nextPos1.x, nextPos1.y, nextPos1.z - height)
					<< QVector3D(nextPos2.x, nextPos2.y, nextPos2.z - height)
					<< QVector3D(a.x, a.y, a.z)
					<< QVector3D(b.x, b.y, b.z)
					<< QVector3D(c.x, c.y, c.z)
					<< QVector3D(c.x, c.y, c.z)
					<< QVector3D(b.x, b.y, b.z)
					<< QVector3D(d.x, d.y, d.z);
		}
	}

	// Create Buffer for position
	vvbo.create();
	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	vvbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector3D));

	////Set each vertex's uv
	//uvs << QVector2D(0.0f, .0f)
	//	<< QVector2D(1.0f, 0.0f)
	//	<< QVector2D(1.0f, 1.0f)
	//	<< QVector2D(1.0f, 1.0f)
	//	<< QVector2D(0.0f, 1.0f)
	//	<< QVector2D(0.0f, .0f);

	//// Create Buffer for uv
	//uvbo.create();
	//// Bind the buffer so that it is the current active buffer
	//uvbo.bind();
	//// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	//uvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	//// Allocate and initialize the information
	//uvbo.allocate(uvs.constData(), uvs.size() * sizeof(QVector2D));

}
void Wheel::InitShader(QString vertexShaderPath, QString fragmentShaderPath)
{
	// Create Shader
	shaderProgram = new QOpenGLShaderProgram();
	QFileInfo  vertexShaderFile(vertexShaderPath);
	if (vertexShaderFile.exists())
	{
		vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
		if (vertexShader->compileSourceFile(vertexShaderPath))
			shaderProgram->addShader(vertexShader);
		else
			qWarning() << "Vertex Shader Error " << vertexShader->log();
	}
	else
		qDebug() << vertexShaderFile.filePath() << " can't be found";

	QFileInfo  fragmentShaderFile(fragmentShaderPath);
	if (fragmentShaderFile.exists())
	{
		fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
		if (fragmentShader->compileSourceFile(fragmentShaderPath))
			shaderProgram->addShader(fragmentShader);
		else
			qWarning() << "fragment Shader Error " << fragmentShader->log();
	}
	else
		qDebug() << fragmentShaderFile.filePath() << " can't be found";
	shaderProgram->link();
}