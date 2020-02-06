#include "Skybox.h"

Skybox::Skybox()
{
}


Skybox::~Skybox()
{
}

void Skybox::DimensionTransformation(GLfloat source[], GLfloat target[][4])
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
void Skybox::DimensionTransformation(glm::mat4 source, GLfloat target[][4])
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
void Skybox::Begin()
{
	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();
}
void Skybox::Paint(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	GLfloat P[4][4];
	GLfloat MV[4][4];
	DimensionTransformation(ProjectionMatrix, P);
	DimensionTransformation(ModelViewMatrix, MV);

	//pass projection matrix to shader
	shaderProgram->setUniformValue("ProjectionMatrix", P);
	//pass modelview matrix to shader
	shaderProgram->setUniformValue("ModelViewMatrix", MV);

	texture->bind();
	shaderProgram->setUniformValue("skybox", 0);

	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Enable Attribute 0
	shaderProgram->enableAttributeArray(0);
	// Set Attribute 0 to be position
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	vvbo.release();

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
void Skybox::End()
{
	//Disable Attribute 0&1
	shaderProgram->disableAttributeArray(0);
	//shaderProgram->disableAttributeArray(1);

	vao.release();
	shaderProgram->release();
}

void Skybox::Init()
{
	InitShader("./Shader/Skybox.vs", "./Shader/Skybox.fs");
	InitVAO();
	InitVBO();
	InitTexture();
}
void Skybox::InitVAO()
{
	// Create Vertex Array Object
	vao.create();
	// Bind the VAO so it is the current active VAO
	vao.bind();
}
void Skybox::InitVBO()
{
	vertices
		<< QVector3D(-1.0f, 1.0f, -1.0f)
		<< QVector3D(-1.0f, -1.0f, -1.0f)
		<< QVector3D(1.0f, -1.0f, -1.0f)
		<< QVector3D(1.0f, -1.0f, -1.0f)
		<< QVector3D(1.0f, 1.0f, -1.0f)
		<< QVector3D(-1.0f, 1.0f, -1.0f)

		<< QVector3D(-1.0f, -1.0f, 1.0f)
		<< QVector3D(-1.0f, -1.0f, -1.0f)
		<< QVector3D(-1.0f, 1.0f, -1.0f)
		<< QVector3D(-1.0f, 1.0f, -1.0f)
		<< QVector3D(-1.0f, 1.0f, 1.0f)
		<< QVector3D(-1.0f, -1.0f, 1.0f)

		<< QVector3D(1.0f, -1.0f, -1.0f)
		<< QVector3D(1.0f, -1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, -1.0f)
		<< QVector3D(1.0f, -1.0f, -1.0f)

		<< QVector3D(-1.0f, -1.0f, 1.0f)
		<< QVector3D(-1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, -1.0f, 1.0f)
		<< QVector3D(-1.0f, -1.0f, 1.0f)

		<< QVector3D(-1.0f, 1.0f, -1.0f)
		<< QVector3D(1.0f, 1.0f, -1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(1.0f, 1.0f, 1.0f)
		<< QVector3D(-1.0f, 1.0f, 1.0f)
		<< QVector3D(-1.0f, 1.0f, -1.0f)

		<< QVector3D(-1.0f, -1.0f, -1.0f)
		<< QVector3D(-1.0f, -1.0f, 1.0f)
		<< QVector3D(1.0f, -1.0f, -1.0f)
		<< QVector3D(1.0f, -1.0f, -1.0f)
		<< QVector3D(-1.0f, -1.0f, 1.0f)
		<< QVector3D(1.0f, -1.0f, 1.0f);

	// Create Buffer for position
	vvbo.create();
	// Bind the buffer so that it is the current active buffer
	vvbo.bind();
	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
	vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	// Allocate and initialize the information
	vvbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector3D));

}
void Skybox::InitShader(QString vertexShaderPath, QString fragmentShaderPath)
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
void Skybox::InitTexture() {
	QVector<QString> faces;
	faces
		/*<< QString("./Textures/skybox/right.jpg")
		<< QString("./Textures/skybox/left.jpg")
		<< QString("./Textures/skybox/top.jpg")
		<< QString("./Textures/skybox/bottom.jpg")
		<< QString("./Textures/skybox/front.jpg")
		<< QString("./Textures/skybox/back.jpg");*/

		<< QString("./Textures/ely_cloudtop/cloudtop_bk.png")
		<< QString("./Textures/ely_cloudtop/cloudtop_ft.png")
		<< QString("./Textures/ely_cloudtop/cloudtop_up.png")
		<< QString("./Textures/ely_cloudtop/cloudtop_dn.png")
		<< QString("./Textures/ely_cloudtop/cloudtop_lf.png")
		<< QString("./Textures/ely_cloudtop/cloudtop_rt.png");

		/*<< QString("./Textures/sunny/sunny_bk.png")
		<< QString("./Textures/sunny/sunny_ft.png")
		<< QString("./Textures/sunny/sunny_up.png")
		<< QString("./Textures/sunny/sunny_dn.png")
		<< QString("./Textures/sunny/sunny_lf.png")
		<< QString("./Textures/sunny/sunny_rt.png");*/

	loadCubemap(faces);
}
void Skybox::loadCubemap(QVector<QString> faces)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	QImage imgpx = QImage(faces[0]).convertToFormat(QImage::Format_RGBA8888);
	QImage imgnx = QImage(faces[1]).convertToFormat(QImage::Format_RGBA8888);
	QImage imgpy = QImage(faces[2]).convertToFormat(QImage::Format_RGBA8888);
	QImage imgny = QImage(faces[3]).convertToFormat(QImage::Format_RGBA8888);
	QImage imgpz = QImage(faces[4]).convertToFormat(QImage::Format_RGBA8888);
	QImage imgnz = QImage(faces[5]).convertToFormat(QImage::Format_RGBA8888);

	texture = new QOpenGLTexture(QOpenGLTexture::TargetCubeMap);
	texture->create();
	texture->setSize(imgpx.width(), imgpx.height(), imgpx.depth());
	texture->setFormat(QOpenGLTexture::RGBA8_UNorm);
	texture->allocateStorage();

	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveX, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgpx.constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeX, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgnx.constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveY, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgpy.constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeY, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgny.constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveZ, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgpz.constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeZ, QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)imgnz.constBits(), 0);

	texture->setWrapMode(QOpenGLTexture::ClampToEdge);
	texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);

	for (unsigned int i = 0; i < faces.size(); i++)
	{
		//QImage img = QImage(faces[i]).mirrored().convertToFormat(QImage::Format_RGBA8888);
		//unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		QImage img = QImage(faces[i]);
		if (!img.isNull())
		{
			//texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveX, QOpenGLTexture::RGB, QOpenGLTexture::UInt8, (const void*)img.constBits(), 0);
			//glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, texture->width(), texture->height(), 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
			//stbi_image_free(data);
		}
		else
		{
			qDebug() << "Cubemap texture failed to load at path: " << faces[i];
			//stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}