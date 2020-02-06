#include "Floor.h"



Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::DimensionTransformation(GLfloat source[], GLfloat target[][4])
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
void Floor::Begin()
{
	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();
}
void Floor::Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	GLfloat P[4][4];
	GLfloat MV[4][4];
	DimensionTransformation(ProjectionMatrix, P);
	DimensionTransformation(ModelViewMatrix, MV);

	//pass projection matrix to shader
	shaderProgram->setUniformValue("ProjectionMatrix", P);
	//pass modelview matrix to shader
	shaderProgram->setUniformValue("ModelViewMatrix", MV);

	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Enable Attribute 0
	shaderProgram->enableAttributeArray(0);
	// Set Attribute 0 to be position
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	vvbo.release();

	// Bind the buffer so that it is the current active buffer
	uvbo.bind();
	// Enable Attribute 1
	shaderProgram->enableAttributeArray(1);

	shaderProgram->setAttributeArray(1, GL_FLOAT, 0, 2, NULL);
	uvbo.release();

	//Draw triangles with 4 indices starting from the 0th index
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
void Floor::End()
{
	//Disable Attribute 0&1
	shaderProgram->disableAttributeArray(0);
	shaderProgram->disableAttributeArray(1);

	vao.release();
	shaderProgram->release();
}

void Floor::Init()
{
	InitShader("./Shader/floor.vs", "./Shader/floor.fs");
	InitVAO();
	InitVBO();
	//InitTexture();
}
void Floor::InitVAO()
{
	// Create Vertex Array Object
	vao.create();
	// Bind the VAO so it is the current active VAO
	vao.bind();
}
void Floor::InitVBO()
{
	//// parameters:
	//float maxX = 160 / 2, maxY = 160 / 2;
	//float minX = -160 / 2, minY = -160 / 2;

	//int x, y, v[3], i;
	//float xp, yp, xd, yd;
	//v[2] = 0;
	//xd = (maxX - minX) / ((float)16);
	//yd = (maxY - minY) / ((float)16);
	//
	//for (x = 0, xp = minX; x < 16; x++, xp += xd) {
	//	for (y = 0, yp = minY, i = x; y < 16; y++, i++, yp += yd) {
	//		uvs << QVector2D(0.0f, 0.0f)
	//			<< QVector2D(0.0f, 1.0f)
	//			<< QVector2D(1.0f, 1.0f)
	//			<< QVector2D(1.0f, 0.0f);

	//		vertices
	//			<< QVector3D(xp, 0.f, yp)
	//			<< QVector3D(xp, 0.f, yp + yd)
	//			<< QVector3D(xp + xd, 0.f, yp + yd)
	//			<< QVector3D(xp + xd, 0.f, yp);

	//	} // end of for j
	//}// end of for i

	QImage image("./Textures/floor_heightmap.jpg");

	for (int i = 0; i < image.height() - 1; i++)   // 0 1 2 |0| 3 4 5 |1|
	{
		for (int k = 0; k < image.width() - 1; k++)
		{
			// 生成顶点数组, 坐标按照三角网格处理 GL_TRIGANLES
			glm::vec3 v1(k + 0 - image.width() / 2.0, QColor(image.pixel(k + 0, i + 0)).red(), i + 0 - image.height() / 2.0);
			glm::vec3 v2(k + 0 - image.width() / 2.0, QColor(image.pixel(k + 0, i + 1)).red(), i + 1 - image.height() / 2.0);
			glm::vec3 v3(k + 1 - image.width() / 2.0, QColor(image.pixel(k + 1, i + 1)).red(), i + 1 - image.height() / 2.0);
			glm::vec3 v4(k + 1 - image.width() / 2.0, QColor(image.pixel(k + 1, i + 0)).red(), i + 0 - image.height() / 2.0);

			vertices
				<< QVector3D(v1.x, v1.y, v1.z)
				<< QVector3D(v2.x, v2.y, v2.z)
				<< QVector3D(v3.x, v3.y, v3.z)
				<< QVector3D(v1.x, v1.y, v1.z)
				<< QVector3D(v3.x, v3.y, v3.z)
				<< QVector3D(v4.x, v4.y, v4.z);
		}
	}

	// 生成纹理坐标
	for (int i = 0; i < vertices.size(); i++)
	{
		glm::vec2 tmp((vertices[i].x() + image.width() / 2) / image.width(), (vertices[i].z() + image.height() / 2) / image.height());
		uvs << QVector2D(tmp.x, tmp.y);
	}

	// Create Buffer for position
	vvbo.create();
	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	vvbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector3D));

	// Create Buffer for uv
	uvbo.create();
	// Bind the buffer so that it is the current active buffer
	uvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	uvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	uvbo.allocate(uvs.constData(), uvs.size() * sizeof(QVector2D));

}
void Floor::InitShader(QString vertexShaderPath, QString fragmentShaderPath)
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
