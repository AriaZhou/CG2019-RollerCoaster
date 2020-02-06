#ifndef TRAINVIEW_H  
#define TRAINVIEW_H  
#include <QGLWidget> 
#include <QtGui>  
#include <QtOpenGL>  
#include <GL/GLU.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#include "Utilities/ArcBallCam.H"
#include "Utilities/3DUtils.H"
#include "Track.H"
#include "Triangle.h"
#include "Square.h"
#include "WaterSurface.h"
#include "Wheel.h"
#include "Model.h"
#include "Skybox.h"
#include "Floor.h"


class AppMain;
class CTrack;

//#######################################################################
// TODO
// You might change the TrainView in order to add different objects to
// be drawn, or adjust the lighting, or ...
//#######################################################################


class TrainView : public QGLWidget, protected QOpenGLFunctions_4_3_Core
{  
	Q_OBJECT  
public:  
	explicit TrainView(QWidget *parent = 0); 
	~TrainView();  

public:
	// overrides of important window things
	//virtual int handle(int);
	virtual void paintGL();

	// all of the actual drawing happens in this routine
	// it has to be encapsulated, since we draw differently if
	// we're drawing shadows (no colors, for example)
	void drawStuff(bool doingShadows=false);

	// setup the projection - assuming that the projection stack has been
	// cleared for you
	void setProjection();

	// Reset the Arc ball control
	void resetArcball();

	// pick a point (for when the mouse goes down)
	void doPick(int mx, int my);

	void initializeGL();
	void initializeTexture();


public:
	ArcBallCam		arcball;			// keep an ArcBall for the UI
	int				selectedCube;  // simple - just remember which cube is selected

	CTrack*			m_pTrack;		// The track of the entire scene

	Square*			m_train;

	WaterSurface*   m_waterSurface;

	Wheel*			m_wheel;

	Skybox*			m_skybox;

	Floor*			m_floor;

	int camera;
	int curve;
	int track;
	int style;
	glm::vec3 qt0, qt1, qt, orient_t, trackHDir, trackDir;
	glm::vec3 preP, preTrackHDir, firstP, firstTrackHDir;
	glm::vec3 carPos, carDir, carUp;
	//glm::vec3 trainHeadPos;
	bool isrun;

	size_t lastClock;

	void drawCarShader(glm::vec3, glm::vec3, glm::vec3, int);
	void drawTrack(bool);
	void drawSleepler(glm::vec3, glm::vec3, glm::vec3, bool);
	void drawCar(glm::vec3, glm::vec3, glm::vec3, int); 
	void drawCarHead(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows);
	void drawCarTail(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows);
	void drawDogOnCar(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows);
	void drawTrackPillar(glm::vec3 pos, glm::vec3 dir, bool doingShadows);
	void drawWheel(glm::vec3, glm::vec3, glm::vec3);
	void findWheelPos(float currentTrainU, float drawedDistance, int k);
	void drawCylinder(float height, float r, bool doingShadows, glm::vec3 color);
	void findCarPos(bool, float);
	bool convertAxis(glm::vec3, glm::vec3);

	Square* square;
	Model *trainHead, *trainTail, *tree, *tree1, *dog;
	GLfloat ProjectionMatrex[16];
	GLfloat ModelViewMatrex[16];
	glm::mat4 RotationMatrix;
	glm::mat4 TransformMatrix;
	QVector<QOpenGLTexture*> Textures;
	unsigned int floorTextureid;

};  
#endif // TRAINVIEW_H  