#include "Square.h"

Square::Square()
{
}
void Square::DimensionTransformation(GLfloat source[],GLfloat target[][4])
{
	//for uniform value, transfer 1 dimension to 2 dimension
	int i = 0;
	for(int j=0;j<4;j++)
		for(int k=0;k<4;k++)
		{
			target[j][k] = source[i];
			i++;
		}
}
void Square::DimensionTransformation(glm::mat4 source, GLfloat target[][4])
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
void Square::Begin()
{
	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();
}
void Square::Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix, glm::mat4 RotateMatrix, glm::mat4 TransformMatrix, int k)
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
	shaderProgram->setAttributeArray(0,GL_FLOAT,0,3,NULL);
	//unbind buffer
	vvbo.release();

	// Bind the buffer so that it is the current active buffer
	uvbo.bind();
	// Enable Attribute 1
	shaderProgram->enableAttributeArray(1);

	shaderProgram->setAttributeArray(1,GL_FLOAT,0,2,NULL);
	uvbo.release();

	// Bind the buffer so that it is the current active buffer
	nvbo.bind();
	// Enable Attribute 0
	shaderProgram->enableAttributeArray(2);
	// Set Attribute 0 to be position
	shaderProgram->setAttributeArray(2, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	nvbo.release();

	//Draw triangles with 4 indices starting from the 0th index
	glDrawArrays(GL_QUADS,0,vertices.size());
}
void Square::End()
{
	//Disable Attribute 0&1
	shaderProgram->disableAttributeArray(0);
	shaderProgram->disableAttributeArray(1);
	shaderProgram->disableAttributeArray(2);

	vao.release();
	shaderProgram->release();
}

void Square::Init()
{
	InitShader("./Shader/Square.vs","./Shader/Square.fs");
	InitVAO();
	InitVBO();
	//InitTexture();
}
void Square::InitVAO()
{
	 // Create Vertex Array Object
	vao.create();
	// Bind the VAO so it is the current active VAO
	vao.bind();
}
void Square::InitVBO()
{
	QVector<glm::vec3> carPosP;
	carPos = glm::vec3(0, 0, 0);
	carUp = glm::vec3(0, 1, 0);
	carDir = glm::vec3(1, 0, 0);
	glm::vec3 carHDir = glm::normalize(glm::cross(carUp, carDir));
	carPosP << (carPos + carHDir * width - carDir * len + carUp * 2.6f)
		<< (carPos + carHDir * width + carDir * len + carUp * 2.6f)
		<< (carPos - carHDir * width + carDir * len + carUp * 2.6f)
		<< (carPos - carHDir * width - carDir * len + carUp * 2.6f)
		<< (carPos + carHDir * width - carDir * len + carUp * 2.6f + carUp * height)
		<< (carPos + carHDir * width + carDir * len + carUp * 2.6f + carUp * height)
		<< (carPos - carHDir * width + carDir * len + carUp * 2.6f + carUp * height)
		<< (carPos - carHDir * width - carDir * len + carUp * 2.6f + carUp * height);

	//Set each vertex's position
	vertices 
		<< QVector3D(carPosP[2].x, carPosP[2].y, carPosP[2].z)
		<< QVector3D(carPosP[1].x, carPosP[1].y, carPosP[1].z)
		<< QVector3D(carPosP[0].x, carPosP[0].y, carPosP[0].z)
		<< QVector3D(carPosP[3].x, carPosP[3].y, carPosP[3].z)
		
		<< QVector3D(carPosP[6].x, carPosP[6].y, carPosP[6].z)
		<< QVector3D(carPosP[5].x, carPosP[5].y, carPosP[5].z)
		<< QVector3D(carPosP[4].x, carPosP[4].y, carPosP[4].z)
		<< QVector3D(carPosP[7].x, carPosP[7].y, carPosP[7].z)
		
		<< QVector3D(carPosP[2].x, carPosP[2].y, carPosP[2].z)
		<< QVector3D(carPosP[6].x, carPosP[6].y, carPosP[6].z)
		<< QVector3D(carPosP[5].x, carPosP[5].y, carPosP[5].z)
		<< QVector3D(carPosP[1].x, carPosP[1].y, carPosP[1].z)

		<< QVector3D(carPosP[4].x, carPosP[4].y, carPosP[4].z)
		<< QVector3D(carPosP[0].x, carPosP[0].y, carPosP[0].z)
		<< QVector3D(carPosP[3].x, carPosP[3].y, carPosP[3].z)
		<< QVector3D(carPosP[7].x, carPosP[7].y, carPosP[7].z)

		<< QVector3D(carPosP[5].x, carPosP[5].y, carPosP[5].z)
		<< QVector3D(carPosP[1].x, carPosP[1].y, carPosP[1].z)
		<< QVector3D(carPosP[0].x, carPosP[0].y, carPosP[0].z)
		<< QVector3D(carPosP[4].x, carPosP[4].y, carPosP[4].z)

		<< QVector3D(carPosP[7].x, carPosP[7].y, carPosP[7].z)
		<< QVector3D(carPosP[3].x, carPosP[3].y, carPosP[3].z)
		<< QVector3D(carPosP[2].x, carPosP[2].y, carPosP[2].z)
		<< QVector3D(carPosP[6].x, carPosP[6].y, carPosP[6].z);

	// Create Buffer for position
	vvbo.create();
	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	vvbo.allocate(vertices.constData(),vertices.size() * sizeof(QVector3D));

	//set each vertex's normal
	normals
		<< QVector3D(-carUp.x, -carUp.y, -carUp.z)
		<< QVector3D(-carUp.x, -carUp.y, -carUp.z)
		<< QVector3D(-carUp.x, -carUp.y, -carUp.z)
		<< QVector3D(-carUp.x, -carUp.y, -carUp.z)
		
		<< QVector3D(carUp.x, carUp.y, carUp.z)
		<< QVector3D(carUp.x, carUp.y, carUp.z)
		<< QVector3D(carUp.x, carUp.y, carUp.z)
		<< QVector3D(carUp.x, carUp.y, carUp.z)

		<< QVector3D(-carDir.x, -carDir.y, -carDir.z)
		<< QVector3D(-carDir.x, -carDir.y, -carDir.z)
		<< QVector3D(-carDir.x, -carDir.y, -carDir.z)
		<< QVector3D(-carDir.x, -carDir.y, -carDir.z)

		<< QVector3D(carDir.x, carDir.y, carDir.z)
		<< QVector3D(carDir.x, carDir.y, carDir.z)
		<< QVector3D(carDir.x, carDir.y, carDir.z)
		<< QVector3D(carDir.x, carDir.y, carDir.z)

		<< QVector3D(carHDir.x, carHDir.y, carHDir.z)
		<< QVector3D(carHDir.x, carHDir.y, carHDir.z)
		<< QVector3D(carHDir.x, carHDir.y, carHDir.z)
		<< QVector3D(carHDir.x, carHDir.y, carHDir.z)

		<< QVector3D(-carHDir.x, -carHDir.y, -carHDir.z)
		<< QVector3D(-carHDir.x, -carHDir.y, -carHDir.z)
		<< QVector3D(-carHDir.x, -carHDir.y, -carHDir.z)
		<< QVector3D(-carHDir.x, -carHDir.y, -carHDir.z);

		// Create Buffer for position
	nvbo.create();
	// Bind the buffer so that it is the current active buffer
	nvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	nvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	nvbo.allocate(normals.constData(), normals.size() * sizeof(QVector3D));

	//Set each vertex's uv
	uvs<<QVector2D(0.0f,1.0f)
		<<QVector2D(0.0f,0.0f)
		<<QVector2D(1.0f,.0f)
		<<QVector2D(1.0f,1.0f)

		<< QVector2D(0.0f, 1.0f)
		<< QVector2D(0.0f, 0.0f)
		<< QVector2D(1.0f, .0f)
		<< QVector2D(1.0f, 1.0f)
		
		<< QVector2D(0.0f, 1.0f)
		<< QVector2D(0.0f, 0.0f)
		<< QVector2D(1.0f, .0f)
		<< QVector2D(1.0f, 1.0f)
		
		<< QVector2D(0.0f, 1.0f)
		<< QVector2D(0.0f, 0.0f)
		<< QVector2D(1.0f, .0f)
		<< QVector2D(1.0f, 1.0f)
		
		<< QVector2D(0.0f, 1.0f)
		<< QVector2D(0.0f, 0.0f)
		<< QVector2D(1.0f, .0f)
		<< QVector2D(1.0f, 1.0f)
		
		<< QVector2D(0.0f, 1.0f)
		<< QVector2D(0.0f, 0.0f)
		<< QVector2D(1.0f, .0f)
		<< QVector2D(1.0f, 1.0f);
	// Create Buffer for uv
	uvbo.create();
	// Bind the buffer so that it is the current active buffer
	uvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	uvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	uvbo.allocate(uvs.constData(),uvs.size() * sizeof(QVector2D));

}
void Square::InitShader(QString vertexShaderPath,QString fragmentShaderPath)
{
	// Create Shader
	shaderProgram = new QOpenGLShaderProgram();
	QFileInfo  vertexShaderFile(vertexShaderPath);
	if(vertexShaderFile.exists())
	{
		vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
		if(vertexShader->compileSourceFile(vertexShaderPath))
			shaderProgram->addShader(vertexShader);
		else
			qWarning() << "Vertex Shader Error " << vertexShader->log();
	}
	else
		qDebug()<<vertexShaderFile.filePath()<<" can't be found";

	QFileInfo  fragmentShaderFile(fragmentShaderPath);
	if(fragmentShaderFile.exists())
	{
		fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
		if(fragmentShader->compileSourceFile(fragmentShaderPath))
			shaderProgram->addShader(fragmentShader);
		else
			qWarning() << "fragment Shader Error " << fragmentShader->log();
	}
	else
		qDebug()<<fragmentShaderFile.filePath()<<" can't be found";
	shaderProgram->link();
}