//#include "Wave.h"
//
//
//
//Wave::Wave()
//{
//}
//
//Wave::~Wave()
//{
//}
//
//void Wave::infoLog(GLuint object, PFNGLGETSHADERIVPROC glGet__iv, PFNGLGETSHADERINFOLOGPROC glGet__InfoLog)
//{
//	GLint log_length;
//	char *log;
//
//	glGet__iv(object, GL_INFO_LOG_LENGTH, &log_length);
//	log = (char *)malloc(log_length);
//	glGet__InfoLog(object, log_length, NULL, log);
//	fprintf(stderr, "%s", log);
//	free(log);
//}
//
//void Wave::InitShader(QString vertexShaderPath, QString fragmentShaderPath)
//{
//	// Create Shader
//	names.shaderProgram = new QOpenGLShaderProgram();
//	QFileInfo  vertexShaderFile(vertexShaderPath);
//	if (vertexShaderFile.exists())
//	{
//		names.vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
//		if (names.vertexShader->compileSourceFile(vertexShaderPath))
//			names.shaderProgram->addShader(names.vertexShader);
//		else
//			qWarning() << "Vertex Shader Error " << names.vertexShader->log();
//	}
//	else
//		qDebug() << vertexShaderFile.filePath() << " can't be found";
//
//	QFileInfo  fragmentShaderFile(fragmentShaderPath);
//	if (fragmentShaderFile.exists())
//	{
//		names.fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
//		if (names.fragmentShader->compileSourceFile(fragmentShaderPath))
//			names.shaderProgram->addShader(names.fragmentShader);
//		else
//			qWarning() << "fragment Shader Error " << names.fragmentShader->log();
//	}
//	else
//		qDebug() << fragmentShaderFile.filePath() << " can't be found";
//	names.shaderProgram->link();
//}
//
//static GLuint initTexture(const char *filename)
//{
//	int width, height;
//	void *pixels = read_tga(filename, &width, &height);
//	GLuint texture;
//
//	if (!pixels)
//		return 0;
//
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
//
//	free(pixels);
//	return texture;
//}
//
//void Wave::initWave(void)
//{
//	//Initialize values{}
//	values.time = 0.0;
//	for (int w = 0; w < WAVE_COUNT; w++)
//	{
//		values.wave_length[w] = wave_para[w][0];
//		values.wave_height[w] = wave_para[w][1];
//		values.wave_dir[w] = wave_para[w][2];
//		values.wave_speed[w] = wave_para[w][3];
//		values.wave_start[w * 2] = wave_para[w][4];
//		values.wave_start[w * 2 + 1] = wave_para[w][5];
//	}
//
//	//Initialize pt_strip[]
//	int index = 0;
//	for (int i = 0; i < STRIP_COUNT; i++)
//	{
//		for (int j = 0; j < STRIP_LENGTH; j++)
//		{
//			pt_strip[index] = START_X + i * LENGTH_X;
//			pt_strip[index + 1] = START_Y + j * LENGTH_Y;
//			index += 3;
//		}
//	}
//}
//
//float Wave::gerstnerZ(float w_length, float w_height, float x_in, const GLfloat gerstner[22])
//{
//	x_in = x_in * 400.0 / w_length;
//
//	while (x_in < 0.0)
//		x_in += 400.0;
//	while (x_in > 400.0)
//		x_in -= 400.0;
//	if (x_in > 200.0)
//		x_in = 400.0 - x_in;
//
//	int i = 0;
//	float yScale = w_height / 50.0;
//	while (i < 18 && (x_in < gerstner[i] || x_in >= gerstner[i + 2]))
//		i += 2;
//	if (x_in == gerstner[i])
//		return gerstner[i + 1] * yScale;
//	if (x_in > gerstner[i])
//		return ((gerstner[i + 3] - gerstner[i + 1]) * (x_in - gerstner[i]) / (gerstner[i + 2] - gerstner[i]) + gerstner[i + 3]) * yScale;
//}
//
//int Wave::normalizeF(float in[], float out[], int count)
//{
//	int t = 0;
//	float l = 0.0;
//
//	if (count <= 0.0) {
//		printf("normalizeF(): Number of dimensions should be larger than zero.\n");
//		return 1;
//	}
//	while (t < count && in[t]<0.0000001 && in[t]>-0.0000001) {
//		t++;
//	}
//	if (t == count) {
//		printf("normalizeF(): The input vector is too small.\n");
//		return 1;
//	}
//	for (t = 0; t < count; t++)
//		l += in[t] * in[t];
//	if (l < 0.0000001) {
//		l = 0.0;
//		for (t = 0; t < count; t++)
//			in[t] *= 10000.0;
//		for (t = 0; t < count; t++)
//			l += in[t] * in[t];
//	}
//	l = sqrt(l);
//	for (t = 0; t < count; t++)
//		out[t] /= l;
//
//	return 0;
//}
//
//void Wave::calcuWave(void)
//{
//	//Calculate pt_strip[z], poly_normal[] and pt_normal[]
//	int index = 0;
//	float d, wave;
//	for (int i = 0; i < STRIP_COUNT; i++)
//	{
//		for (int j = 0; j < STRIP_LENGTH; j++)
//		{
//			wave = 0.0;
//			for (int w = 0; w < WAVE_COUNT; w++) {
//				d = (pt_strip[index] - values.wave_start[w * 2] + (pt_strip[index + 1] - values.wave_start[w * 2 + 1]) * tan(values.wave_dir[w])) * cos(values.wave_dir[w]);
//				if (gerstner_sort[w] == 1) {
//					wave += values.wave_height[w] - gerstnerZ(values.wave_length[w], values.wave_height[w], d + values.wave_speed[w] * values.time, gerstner_pt_a);
//				}
//				else {
//					wave += values.wave_height[w] - gerstnerZ(values.wave_length[w], values.wave_height[w], d + values.wave_speed[w] * values.time, gerstner_pt_b);
//				}
//			}
//			pt_strip[index + 2] = START_Z + wave * HEIGHT_SCALE;
//			index += 3;
//		}
//	}
//
//	index = 0;
//	for (int i = 0; i < STRIP_COUNT; i++)
//	{
//		for (int j = 0; j < STRIP_LENGTH; j++)
//		{
//			int p0 = index - STRIP_LENGTH * 3, p1 = index + 3, p2 = index + STRIP_LENGTH * 3, p3 = index - 3;
//			float xa, ya, za, xb, yb, zb;
//			if (i > 0) {
//				if (j > 0) {
//					xa = pt_strip[p0] - pt_strip[index], ya = pt_strip[p0 + 1] - pt_strip[index + 1], za = pt_strip[p0 + 2] - pt_strip[index + 2];
//					xb = pt_strip[p3] - pt_strip[index], yb = pt_strip[p3 + 1] - pt_strip[index + 1], zb = pt_strip[p3 + 2] - pt_strip[index + 2];
//					pt_normal[index] += ya * zb - yb * za;
//					pt_normal[index + 1] += xb * za - xa * zb;
//					pt_normal[index + 2] += xa * yb - xb * ya;
//				}
//				if (j < STRIP_LENGTH - 1) {
//					xa = pt_strip[p1] - pt_strip[index], ya = pt_strip[p1 + 1] - pt_strip[index + 1], za = pt_strip[p1 + 2] - pt_strip[index + 2];
//					xb = pt_strip[p0] - pt_strip[index], yb = pt_strip[p0 + 1] - pt_strip[index + 1], zb = pt_strip[p0 + 2] - pt_strip[index + 2];
//					pt_normal[index] += ya * zb - yb * za;
//					pt_normal[index + 1] += xb * za - xa * zb;
//					pt_normal[index + 2] += xa * yb - xb * ya;
//				}
//			}
//			if (i < STRIP_COUNT - 1) {
//				if (j > 0) {
//					xa = pt_strip[p3] - pt_strip[index], ya = pt_strip[p3 + 1] - pt_strip[index + 1], za = pt_strip[p3 + 2] - pt_strip[index + 2];
//					xb = pt_strip[p2] - pt_strip[index], yb = pt_strip[p2 + 1] - pt_strip[index + 1], zb = pt_strip[p2 + 2] - pt_strip[index + 2];
//					pt_normal[index] += ya * zb - yb * za;
//					pt_normal[index + 1] += xb * za - xa * zb;
//					pt_normal[index + 2] += xa * yb - xb * ya;
//				}
//				if (j < STRIP_LENGTH - 1) {
//					xa = pt_strip[p2] - pt_strip[index], ya = pt_strip[p2 + 1] - pt_strip[index + 1], za = pt_strip[p2 + 2] - pt_strip[index + 2];
//					xb = pt_strip[p1] - pt_strip[index], yb = pt_strip[p1 + 1] - pt_strip[index + 1], zb = pt_strip[p1 + 2] - pt_strip[index + 2];
//					pt_normal[index] += ya * zb - yb * za;
//					pt_normal[index + 1] += xb * za - xa * zb;
//					pt_normal[index + 2] += xa * yb - xb * ya;
//				}
//			}
//			if (normalizeF(&pt_normal[index], &pt_normal[index], 3))
//				printf("%d\t%d\n", index / 3 / STRIP_LENGTH, (index / 3) % STRIP_LENGTH);
//
//			index += 3;
//		}
//	}
//
//	//Calculate vertex_data[] according to pt_strip[], and normal_data[] according to pt_normal[]
//	int pt;
//	for (int c = 0; c < (STRIP_COUNT - 1); c++)
//	{
//		for (int l = 0; l < 2 * STRIP_LENGTH; l++)
//		{
//			if (l % 2 == 1) {
//				pt = c * STRIP_LENGTH + l / 2;
//			}
//			else {
//				pt = c * STRIP_LENGTH + l / 2 + STRIP_LENGTH;
//			}
//			index = STRIP_LENGTH * 2 * c + l;
//			for (int i = 0; i < 3; i++) {
//				vertex_data[index * 3 + i] = pt_strip[pt * 3 + i];
//				normal_data[index * 3 + i] = pt_normal[pt * 3 + i];
//			}
//		}
//	}
//}
//
//void Wave::idleFunc(void)
//{
//	values.time += 0.05;
//	glutPostRedisplay();
//}
//
//void Wave::initGL(void)
//{
//	//glClearColor(0.0, 0.0, 0.0, 1.0);
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	names.shaderProgram->setUniformValue("materAmbient", 0.1, 0.1, 0.3, 1.0);
//	names.shaderProgram->setUniformValue("materSpecular", 0.8, 0.8, 0.9, 1.0);
//	names.shaderProgram->setUniformValue("lightDiffuse", 0.7, 0.7, 0.8, 1.0);
//	names.shaderProgram->setUniformValue("lightAmbient", 0.0, 0.0, 0.0, 1.0);
//	names.shaderProgram->setUniformValue("lightSpecular", 1.0, 1.0, 1.0, 1.0);
//	names.shaderProgram->setUniformValue("envirAmbient", 0.1, 0.1, 0.3, 1.0);
//
//	names.vao.create();
//	names.vao.bind();
//
//	// Create Buffer for position
//	names.vvbo.create();
//	// Bind the buffer so that it is the current active buffer
//	names.vvbo.bind();
//	// Since we will never change the data that we are about to pass the Buffer, we will say that the Usage Pattern is StaticDraw
//	names.vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
//	// Allocate and initialize the information
//	names.vvbo.allocate(vertex_data, DATA_LENGTH * 3 * sizeof(QVector3D));
//
//	names.attributes.position = names.shaderProgram->attributeLocation("position");
//	glGenBuffers(1, &names.vertex_buffer);
//
//	names.attributes.normal = names.shaderProgram->attributeLocation("normal");
//	glGenBuffers(1, &names.normal_buffer);
//
//	/*names.diffuse_texture = initTexture("water-texture-2.tga");
//	names.uniforms.diffuse_texture = glGetUniformLocation(names.shaderProgram, "textures[0]");
//	glUniform1i(names.uniforms.diffuse_texture, 0);
//
//	names.normal_texture = initTexture("water-texture-2-normal.tga");
//	names.uniforms.normal_texture = glGetUniformLocation(names.shaderProgram, "textures[1]");
//	glUniform1i(names.uniforms.normal_texture, 1);*/
//
//	glm::mat4 Projection = glm::perspective(45.0f, (float)(SCREEN_WIDTH / SCREEN_HEIGHT), 1.0f, 100.f);
//	glm::mat4 viewTransMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.5f));
//	glm::mat4 viewRotateMat = glm::rotate(viewTransMat, -45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
//	glm::mat4 ModelViewMat = glm::scale(viewRotateMat, glm::vec3(1.0f, 1.0f, 1.0f));
//	glm::mat3 NormalMat = glm::transpose(glm::inverse(glm::mat3(ModelViewMat)));
//	glUniformMatrix4fv(glGetUniformLocation(names.program, "modelViewMat"), 1, GL_FALSE, glm::value_ptr(ModelViewMat));
//	glUniformMatrix4fv(glGetUniformLocation(names.program, "perspProjMat"), 1, GL_FALSE, glm::value_ptr(Projection));
//	glUniformMatrix3fv(glGetUniformLocation(names.program, "normalMat"), 1, GL_FALSE, glm::value_ptr(NormalMat));
//}
//
//void Wave::displayFunc(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	calcuWave();
//
//	glUniform1f(glGetUniformLocation(names.shaderProgram, "time"), values.time);
//
//	glBindBuffer(GL_ARRAY_BUFFER, names.vertex_buffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
//	glVertexAttribPointer(names.attributes.position, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
//	glEnableVertexAttribArray(names.attributes.position);
//
//	glBindBuffer(GL_ARRAY_BUFFER, names.normal_buffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(normal_data), normal_data, GL_STATIC_DRAW);
//	glVertexAttribPointer(names.attributes.normal, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
//	glEnableVertexAttribArray(names.attributes.normal);
//
//	for (int c = 0; c < (STRIP_COUNT - 1); c++)
//		glDrawArrays(GL_TRIANGLE_STRIP, STRIP_LENGTH * 2 * c, STRIP_LENGTH * 2);
//
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, names.normal_texture);
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, names.diffuse_texture);
//
//	glutSwapBuffers();
//}