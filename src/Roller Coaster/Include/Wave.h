#pragma once
#include <QtOpenGL>  
#include <QtGui/QOpenGLFunctions_4_3_Core>
#include <gl/glut.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600

#define START_X		-4.0
#define START_Y		-2.5
#define START_Z		0
#define LENGTH_X	0.1
#define LENGTH_Y	0.1

#define HEIGHT_SCALE	1.6

#define WAVE_COUNT		6

#define STRIP_COUNT		80
#define STRIP_LENGTH	50
#define DATA_LENGTH		STRIP_LENGTH*2*(STRIP_COUNT-1)

static GLfloat pt_strip[STRIP_COUNT*STRIP_LENGTH * 3] = { 0 };
static GLfloat pt_normal[STRIP_COUNT*STRIP_LENGTH * 3] = { 0 };
static GLfloat vertex_data[DATA_LENGTH * 3] = { 0 };
static GLfloat normal_data[DATA_LENGTH * 3] = { 0 };

//wave_length, wave_height, wave_dir, wave_speed, wave_start.x, wave_start.y
static const GLfloat wave_para[6][6] = {
	{	1.6,	0.12,	0.9,	0.06,	0.0,	0.0	},
	{	1.3,	0.1,	1.14,	0.09,	0.0,	0.0	},
	{	0.2,	0.01,	0.8,	0.08,	0.0,	0.0	},
	{	0.18,	0.008,	1.05,	0.1,	0.0,	0.0	},
	{	0.23,	0.005,	1.15,	0.09,	0.0,	0.0	},
	{	0.12,	0.003,	0.97,	0.14,	0.0,	0.0	}
};


//两种波形
static const GLfloat gerstner_pt_a[22] = {
	0.0,0.0, 41.8,1.4, 77.5,5.2, 107.6,10.9,
	132.4,17.7, 152.3,25.0, 167.9,32.4, 179.8,39.2,
	188.6,44.8, 195.0,48.5, 200.0,50.0
};
static const GLfloat gerstner_pt_b[22] = {
	0.0,0.0, 27.7,1.4, 52.9,5.2, 75.9,10.8,
	97.2,17.6, 116.8,25.0, 135.1,32.4, 152.4,39.2,
	168.8,44.8, 184.6,48.5, 200.0,50.0
};

static const GLint gerstner_sort[6] = {
	0, 0, 1, 1, 1, 1
};

static struct {
	QOpenGLVertexArrayObject vao;
	QOpenGLBuffer vvbo, nvbo;
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLShader* vertexShader;
	QOpenGLShader* fragmentShader;
	GLuint diffuse_texture, normal_texture;

	struct {
		GLint diffuse_texture, normal_texture;
	} uniforms;

	struct {
		GLint position;
		GLint normal;
	} attributes;
} names;

//水波的一些信息
static struct {
	GLfloat time;
	GLfloat wave_length[WAVE_COUNT],
		wave_height[WAVE_COUNT],
		wave_dir[WAVE_COUNT],
		wave_speed[WAVE_COUNT],
		wave_start[WAVE_COUNT * 2];
} values;

class Wave
{
public:
	Wave();
	~Wave();

	static void infoLog(GLuint, PFNGLGETSHADERIVPROC, PFNGLGETSHADERINFOLOGPROC);
	void *readShader(const char *, GLint *);
	static void InitShader(QString vertexShaderPath, QString fragmentShaderPath);
	static void installShaders(void);
	static void idleFunc(void);
	static void calcuGerstnerGradient(const GLfloat *, GLfloat *);
	static void initWave(void);
	static float gerstnerZ(float, float, float, const GLfloat *);  //线性内插函数
	static int normalizeF(float *, float *, int);  //计算法向量
	static void calcuWave(void);  //计算网格点的z值
	static void initGL(void);
	static void displayFunc(void);
};

