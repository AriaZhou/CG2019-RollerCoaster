#include "TrainView.h"  

TrainView::TrainView(QWidget *parent) :
	QGLWidget(parent)
{
	resetArcball();

}
TrainView::~TrainView()
{}
void TrainView::initializeGL()
{
	initializeOpenGLFunctions();

	m_train = new Square();
	m_train->Init();

	m_wheel = new Wheel(1.5f, 0.5f);
	m_wheel->Init();

	m_skybox = new Skybox();
	m_skybox->Init();

	m_waterSurface = new WaterSurface();
	m_waterSurface->Init();

	m_floor = new Floor();
	m_floor->Init();

	trainHead = new Model("./model/trainHead/trainHead.obj", 17, glm::vec3(0, 0, 0));
	trainTail = new Model("./model/trainTail/trainTail.obj", 14, glm::vec3(0, 0, 0));
	tree = new Model("./model/tree/tree.obj", 30, glm::vec3(0, 0, 0));
	tree1 = new Model("./model/tree/tree.obj", 60, glm::vec3(0, 0, 0));
	dog = new Model("./model/dog/dog.obj", 9, glm::vec3(0, 0, 0));

	//Initialize texture 
	initializeTexture();

}
void TrainView::initializeTexture()
{
	//Load and create a texture for square;'stexture
	QOpenGLTexture* texture = new QOpenGLTexture(QImage("./Textures/sand1.jpg"));
	texture->setWrapMode(QOpenGLTexture::ClampToEdge);
	texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	Textures.push_back(texture);

	QOpenGLTexture* textureCar = new QOpenGLTexture(QImage("./Textures/car0.png"));
	textureCar->setWrapMode(QOpenGLTexture::Repeat);
	textureCar->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureCar->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	Textures.push_back(textureCar);

	QOpenGLTexture* textureWaterFlowMap = new QOpenGLTexture(QImage("./Textures/flowmap1.jpg"));
	textureWaterFlowMap->setWrapMode(QOpenGLTexture::Repeat);
	textureWaterFlowMap->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureWaterFlowMap->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	Textures.push_back(textureWaterFlowMap);

	QOpenGLTexture* textureWaterNormal = new QOpenGLTexture(QImage("./Textures/water_normal.png"));
	textureWaterNormal->setWrapMode(QOpenGLTexture::Repeat);
	textureWaterNormal->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureWaterNormal->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	Textures.push_back(textureWaterNormal);

	QOpenGLTexture* textureFloorHeightMap = new QOpenGLTexture(QImage("./Textures/floor_heightmap.jpg"));
	textureFloorHeightMap->setWrapMode(QOpenGLTexture::Repeat);
	textureFloorHeightMap->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureFloorHeightMap->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	Textures.push_back(textureFloorHeightMap);

	//floortexture
	QImage floorTexture = QImage("./Textures/sand1.jpg");
	glGenTextures(1, &floorTextureid);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, floorTextureid);
	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, floorTexture.width(), floorTexture.height(), 0, GL_BGRA, GL_UNSIGNED_BYTE, floorTexture.bits());
	glGenerateMipmap(GL_TEXTURE_2D);
	
}
void TrainView::resetArcball()
//========================================================================
{
	// Set up the camera to look at the world
	// these parameters might seem magical, and they kindof are
	// a little trial and error goes a long way
	arcball.setup(this, 45, 280, .2f, .4f, 0);
}

void TrainView::paintGL()
{

	//*********************************************************************
	//
	// * Set up basic opengl informaiton
	//
	//**********************************************************************
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	// Set up the view port
	glViewport(0, 0, width(), height());
	// clear the window, be sure to clear the Z-Buffer too
	glClearColor(0.2f, 0.3f, 0.3f, 0);

	// we need to clear out the stencil buffer since we'll use
	// it for shadows
	glClearStencil(0);
	glEnable(GL_DEPTH);

	// Blayne prefers GL_DIFFUSE
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// prepare for projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setProjection();		// put the code to set up matrices here
	
	//Get modelview matrix
	glGetFloatv(GL_MODELVIEW_MATRIX, ModelViewMatrex);
	//Get projection matrix
	glGetFloatv(GL_PROJECTION_MATRIX, ProjectionMatrex);


	//######################################################################
	// TODO: 
	// you might want to set the lighting up differently. if you do, 
	// we need to set up the lights AFTER setting up the projection
	//######################################################################
	// enable the lighting
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//*********************************************************************
	//
	// * set the light parameters
	//
	//**********************************************************************
	GLfloat lightPosition1[] = { 0, 1, 0, 0 }; // {50, 200.0, 50, 1.0};
	GLfloat whiteLight[] = { 1.0f, 1.0f, 1.0f, 1.0 };
	GLfloat grayLight[] = { .3f, .3f, .3f, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, grayLight);

	//*********************************************************************
	// now draw the ground plane
	//*********************************************************************
	/*setupFloor();
	glDisable(GL_LIGHTING);
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, floorTextureid);
	drawFloor(160, 16);
	glDisable(GL_TEXTURE_2D);*/

	//*********************************************************************
	// now draw the object and we need to do it twice
	// once for real, and then once for shadows
	//*********************************************************************
	glEnable(GL_LIGHTING);
	setupObjects();

	m_pTrack->calTotalLen(curve);
	drawStuff();
	tree->render(glm::mat4(1.0f), glm::translate(glm::mat4(1.0f), glm::vec3(6, 30, 36)), false, false);
	tree1->render(glm::mat4(1.0f), glm::translate(glm::mat4(1.0f), glm::vec3(-46, 33, -46)), false, false);
	tree->render(glm::mat4(1.0f), glm::translate(glm::mat4(1.0f), glm::vec3(-49, 32, 67)), false, false);
	tree1->render(glm::mat4(1.0f), glm::translate(glm::mat4(1.0f), glm::vec3(66, 26, -40)), false, false);
	dog->render(glm::rotate(glm::mat4(1.0f), 1.57f, glm::vec3(0, 1, 0)), glm::translate(glm::mat4(1.0f), glm::vec3(36, 3, -40)), false, false);
	if(!(m_pTrack->standCarIndex == -1 && camera == 2))
		drawCarHead(m_pTrack->headPos, m_pTrack->headDir, m_pTrack->headUp, false);
	drawCarTail(m_pTrack->tailPos, m_pTrack->tailDir, m_pTrack->tailUp, false);
	if(this->camera != 2)
		drawDogOnCar(m_pTrack->carPos, m_pTrack->carDir, m_pTrack->carUp, false);
	
	//qDebug() << arcball.eyeZ << "," << arcball.eyeX << "," << arcball.eyeY << "," << arcball.isz << "";
	// this time drawing is for shadows (except for top view)
	if (this->camera != 1) {
		setupShadows();
		//drawStuff(true);
		unsetupShadows();
	}

	m_skybox->Begin();
	glActiveTexture(GL_TEXTURE0);
	m_skybox->Paint(ProjectionMatrex, ModelViewMatrex);
	m_skybox->End();
	
	if (camera != 1) {
		m_waterSurface->Begin();
			//Active Texture
			glActiveTexture(GL_TEXTURE0);
			//Bind square's texture
			Textures[2]->bind();
			//pass texture to shader
			m_waterSurface->shaderProgram->setUniformValue("texture_flowmap", 0);
			//Bind square's texture
			glActiveTexture(GL_TEXTURE1);
			Textures[3]->bind();
			//pass texture to shader
			m_waterSurface->shaderProgram->setUniformValue("texture_normal", 1);
			glActiveTexture(GL_TEXTURE2);
			m_skybox->texture->bind();
			//pass texture to shader
			m_waterSurface->shaderProgram->setUniformValue("skybox", 2);
			m_waterSurface->shaderProgram->setAttributeValue("viewPos", arcball.eyeX, arcball.eyeY, arcball.eyeZ);
			//Call square's render function, pass ModelViewMatrex and ProjectionMatrex
			m_waterSurface->Paint(ProjectionMatrex, ModelViewMatrex);
			glDisable(GL_TEXTURE_2D);
		m_waterSurface->End();

		m_floor->Begin();
			//Active Texture
			glActiveTexture(GL_TEXTURE0);
			//Bind square's texture
			Textures[0]->bind();
			//pass texture to shader
			m_floor->shaderProgram->setUniformValue("Texture", 0);
			//Bind square's texture
			glActiveTexture(GL_TEXTURE1);
			Textures[3]->bind();
			//pass texture to shader
			m_floor->shaderProgram->setUniformValue("texture_normal", 1);
			glActiveTexture(GL_TEXTURE2);
			Textures[4]->bind();
			//pass texture to shader
			m_floor->shaderProgram->setUniformValue("depth_map", 2);
			m_floor->shaderProgram->setAttributeValue("viewPos", arcball.eyeX, arcball.eyeY, arcball.eyeZ);
			//Call square's render function, pass ModelViewMatrex and ProjectionMatrex
			m_floor->Paint(ProjectionMatrex, ModelViewMatrex);
			glDisable(GL_TEXTURE_2D);
		m_floor->End();
	}

}

//************************************************************************
//
// * This sets up both the Projection and the ModelView matrices
//   HOWEVER: it doesn't clear the projection first (the caller handles
//   that) - its important for picking
//========================================================================
void TrainView::
setProjection()
//========================================================================
{
	// Compute the aspect ratio (we'll need it)
	float aspect = static_cast<float>(width()) / static_cast<float>(height());

	// Check whether we use the world camp
	if (this->camera == 0) {
		arcball.setProjection(false);
		update();
		// Or we use the top cam
	}
	else if (this->camera == 1) {
		float wi, he;
		if (aspect >= 1) {
			wi = 200;
			he = wi / aspect;
		}
		else {
			he = 200;
			wi = he * aspect;
		}

		// Set up the top camera drop mode to be orthogonal and set
		// up proper projection matrix
		glMatrixMode(GL_PROJECTION);
		glOrtho(-wi, wi, -he, he, 200, -200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(-90, 1, 0, 0);
		update();
	}
	// Or do the train view or other view here
	//####################################################################
	// TODO: 
	// put code for train view projection here!	
	//####################################################################
	else {
#ifdef EXAMPLE_SOLUTION
		trainCamView(this, aspect);
#endif
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, static_cast<float>(width()) / static_cast<float>(height()), 0.6, 4000.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		float upOffset = m_train->height + m_wheel->r * 2 + 3.f;
		float forwardOffset = m_train->len - 0.6;
		glm::vec3 lookPos, lookInto;
		if (m_pTrack->standCarIndex != -1) {
			lookPos = m_pTrack->carPos + m_pTrack->carUp * upOffset - m_pTrack->carDir*forwardOffset;
			lookInto = lookPos + m_pTrack->carDir;
		}
		else {
			lookPos = m_pTrack->headPos + m_pTrack->headUp * m_wheel->r * 3.f;
			lookInto = lookPos + m_pTrack->headDir + glm::vec3(0, -0.2, 0);
		}

		gluLookAt(lookPos.x, lookPos.y, lookPos.z, lookInto.x, lookInto.y, lookInto.z,
			m_pTrack->carUp.x, m_pTrack->carUp.y, m_pTrack->carUp.z);

		update();
	}
}

//************************************************************************
//
// * this draws all of the stuff in the world
//
//	NOTE: if you're drawing shadows, DO NOT set colors (otherwise, you get 
//       colored shadows). this gets called twice per draw 
//       -- once for the objects, once for the shadows
//########################################################################
// TODO: 
// if you have other objects in the world, make sure to draw them
//########################################################################
//========================================================================
void TrainView::drawStuff(bool doingShadows)
{
	// Draw the control points
	// don't draw the control points if you're driving 
	// (otherwise you get sea-sick as you drive through them)
	if (this->camera != 2) {
		for (size_t i = 0; i < this->m_pTrack->points.size(); ++i) {
			if (!doingShadows) {
				if (((int)i) != selectedCube)
					glColor3ub(240, 60, 60);
				else
					glColor3ub(240, 240, 30);
			}
			this->m_pTrack->points[i].draw();
		}
		update();
	}

	// draw the track
	//####################################################################
	// TODO: 
	// call your own track drawing code
	//####################################################################
	float t, drawedDistance = 0;

	switch (curve) {
	case 0:
	{
		for (size_t i = 0; i < this->m_pTrack->points.size(); ++i) {

			glm::vec3 startP = m_pTrack->points[i].pos;
			glm::vec3 endP = m_pTrack->points[((i + 1) % m_pTrack->points.size())].pos;

			glm::vec3 startO = m_pTrack->points[i].orient;
			glm::vec3 endO = m_pTrack->points[((i + 1) % m_pTrack->points.size())].orient;

			qt = startP;

			for (int j = 1; j <= m_pTrack->subdivision; j++)
			{
				t = j / m_pTrack->subdivision;

				preP = qt1;
				preTrackHDir = trackHDir;

				qt0 = qt;
				orient_t = (1.f - t) * startO + t * endO;
				qt = (1.f - t) * startP + t * endP;
				qt1 = qt;

				trackDir = glm::normalize(qt1 - qt0);
				trackHDir = glm::normalize(glm::cross(orient_t, trackDir));

				drawTrack(doingShadows);

				//枕木
				if (m_pTrack->sleeperVisible &&
					((float)(drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1) >= m_pTrack->sleeperFrqt || drawedDistance == 0))
				{
					if (drawedDistance == 0)
						drawSleepler(qt0, trackDir, trackHDir, doingShadows);
					for (int k = 1; k <= ((drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1)) / m_pTrack->sleeperFrqt; k++)
						drawSleepler(qt0 + trackDir * (m_pTrack->sleeperFrqt * k - (drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt)), trackDir, trackHDir, doingShadows);
				}

				//车的位置 
				findCarPos(doingShadows, drawedDistance);

				drawedDistance += glm::distance(qt0, qt1);

			}

			drawTrackPillar(qt1, glm::normalize(qt1 - qt0), doingShadows);
		}
	}break;

	case 1:
	{
		for (size_t i = 0; i < this->m_pTrack->points.size(); ++i) {

			glm::vec3 P0 = m_pTrack->points[i % m_pTrack->points.size()].pos;
			glm::vec3 P1 = m_pTrack->points[((i + 1) % m_pTrack->points.size())].pos;
			glm::vec3 P2 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].pos;
			glm::vec3 P3 = m_pTrack->points[((i + 3) % m_pTrack->points.size())].pos;

			glm::vec3 O0 = m_pTrack->points[i % m_pTrack->points.size()].orient;
			glm::vec3 O1 = m_pTrack->points[((i + 1) % m_pTrack->points.size())].orient;
			glm::vec3 O2 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].orient;
			glm::vec3 O3 = m_pTrack->points[((i + 3) % m_pTrack->points.size())].orient;

			qt = P1;

			for (int j = 1; j <= m_pTrack->subdivision; j++)
			{
				t = j / m_pTrack->subdivision;

				float b0 = ( -1	*t*t*t + 2 *t*t + (-1) * t) * m_pTrack->tension;
				float b1 = (( 2 / m_pTrack->tension - 1) *t*t*t + (-3 / m_pTrack->tension + 1) *t*t + 1/m_pTrack->tension) * m_pTrack->tension;
				float b2 = ((-2 / m_pTrack->tension + 1) *t*t*t + ( 3 / m_pTrack->tension - 2) *t*t + t) * m_pTrack->tension;
				float b3 = (  1	*t*t*t + (-1) *t*t) * m_pTrack->tension;

				preP = qt1;
				preTrackHDir = trackHDir;

				qt0 = qt;
				orient_t = glm::vec3(b0 * O0.x + b1 * O1.x + b2 * O2.x + b3 * O3.x,
					b0 * O0.y + b1 * O1.y + b2 * O2.y + b3 * O3.y,
					b0 * O0.z + b1 * O1.z + b2 * O2.z + b3 * O3.z);
				qt = glm::vec3(b0 * P0.x + b1 * P1.x + b2 * P2.x + b3 * P3.x,
					b0 * P0.y + b1 * P1.y + b2 * P2.y + b3 * P3.y,
					b0 * P0.z + b1 * P1.z + b2 * P2.z + b3 * P3.z);
				qt1 = qt;

				trackDir = glm::normalize(qt1 - qt0);
				trackHDir = glm::normalize(glm::cross(orient_t, trackDir));

				drawTrack(doingShadows);

				//枕木
				if (m_pTrack->sleeperVisible &&
					((float)(drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1) >= m_pTrack->sleeperFrqt || drawedDistance == 0))
				{
					if (drawedDistance == 0)
						drawSleepler(qt0, trackDir, trackHDir, doingShadows);
					for (int k = 1; k <= ((drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1)) / m_pTrack->sleeperFrqt; k++)
						drawSleepler(qt0 + trackDir * (m_pTrack->sleeperFrqt * k - (drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt)), trackDir, trackHDir, doingShadows);
				}

				//车的位置
				findCarPos(doingShadows, drawedDistance);

				drawedDistance += glm::distance(qt0, qt1);
			}

			drawTrackPillar(qt1, glm::normalize(qt1 - qt0), doingShadows);
		}
	}break;

	case 2:
	{
		for (size_t i = 0; i < this->m_pTrack->points.size(); ++i) {

			glm::vec3 P0 = m_pTrack->points[i % m_pTrack->points.size()].pos;
			glm::vec3 P1 = m_pTrack->points[((i + 1) % m_pTrack->points.size())].pos;
			glm::vec3 P2 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].pos;
			glm::vec3 P3 = m_pTrack->points[((i + 3) % m_pTrack->points.size())].pos;

			glm::vec3 O0 = m_pTrack->points[i % m_pTrack->points.size()].orient;
			glm::vec3 O1 = m_pTrack->points[((i + 1) % m_pTrack->points.size())].orient;
			glm::vec3 O2 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].orient;
			glm::vec3 O3 = m_pTrack->points[((i + 3) % m_pTrack->points.size())].orient;

			qt = glm::vec3(1.0f / 6.0f * P0.x + 4.0f / 6.0f * P1.x + 1.0f / 6.0f * P2.x,
							1.0f / 6.0f * P0.y + 4.0f / 6.0 * P1.y + 1.0f / 6.0f * P2.y,
							1.0f / 6.0f * P0.z + 4.0f / 6.0 * P1.z + 1.0f / 6.0f * P2.z);

			for (int j = 1; j <= m_pTrack->subdivision; j++)
			{
				t = j / m_pTrack->subdivision;

				float b0 = (1 - t) * (1 - t) * (1 - t) / 6.0f;
				float b1 = (3 * t*t*t - 6 * t*t + 4) / 6.0f;
				float b2 = (-3 * t*t*t + 3 * t*t + 3 * t + 1) / 6.0f;
				float b3 = t * t*t / 6.0f;

				preP = qt1;
				preTrackHDir = trackHDir;

				qt0 = qt;
				orient_t = glm::vec3(b0 * O0.x + b1 * O1.x + b2 * O2.x + b3 * O3.x,
					b0 * O0.y + b1 * O1.y + b2 * O2.y + b3 * O3.y,
					b0 * O0.z + b1 * O1.z + b2 * O2.z + b3 * O3.z);
				qt = glm::vec3(b0 * P0.x + b1 * P1.x + b2 * P2.x + b3 * P3.x,
					b0 * P0.y + b1 * P1.y + b2 * P2.y + b3 * P3.y,
					b0 * P0.z + b1 * P1.z + b2 * P2.z + b3 * P3.z);
				qt1 = qt;

				trackHDir = glm::normalize(glm::cross(orient_t, (qt1 - qt0)));
				trackDir = glm::normalize(qt1 - qt0);

				drawTrack(doingShadows);

				//枕木
				if (m_pTrack->sleeperVisible &&
					((float)(drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1) >= m_pTrack->sleeperFrqt || drawedDistance == 0))
				{
					if (drawedDistance == 0)
						drawSleepler(qt0, trackDir, trackHDir, doingShadows);
					for (int k = 1; k <= ((drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt) + glm::distance(qt0, qt1)) / m_pTrack->sleeperFrqt; k++)
						drawSleepler(qt0 + trackDir * (m_pTrack->sleeperFrqt * k - (drawedDistance - (int)(drawedDistance / m_pTrack->sleeperFrqt) * m_pTrack->sleeperFrqt)), trackDir, trackHDir, doingShadows);
				}

				//车的位置
				findCarPos(doingShadows, drawedDistance);

				drawedDistance += glm::distance(qt0, qt1);
			}

			drawTrackPillar(qt1, glm::normalize(qt1-qt0), doingShadows);
		}
	}break;

	default: break;
	}


#ifdef EXAMPLE_SOLUTION
	drawTrack(this, doingShadows);
#endif

	// draw the train
	//####################################################################
	// TODO: 
	//	call your own train drawing code
	//####################################################################

	if (isrun && !doingShadows) {
		m_pTrack->trainU += (m_pTrack->speed / 1000.f)*(GetTickCount() - lastClock);
		if (m_pTrack->trainU >= m_pTrack->totalLen)
			m_pTrack->trainU -= m_pTrack->totalLen;
	}

	lastClock = GetTickCount();
	//drawCar(doingShadows);


#ifdef EXAMPLE_SOLUTION
	// don't draw the train if you're looking out the front window
	if (!tw->trainCam->value())
		drawTrain(this, doingShadows);
#endif
}

void TrainView::doPick(int mx, int my)
//========================================================================
{
	// since we'll need to do some GL stuff so we make this window as 
	// active window
	makeCurrent();

	// get the viewport - most reliable way to turn mouse coords into GL coords
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPickMatrix((double)mx, (double)(viewport[3] - my),
		5, 5, viewport);

	// now set up the projection
	setProjection();

	// now draw the objects - but really only see what we hit
	GLuint buf[100];
	glSelectBuffer(100, buf);
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);


	// draw the cubes, loading the names as we go
	for (size_t i = 0; i < m_pTrack->points.size(); ++i) {
		glLoadName((GLuint)(i + 1));
		m_pTrack->points[i].draw();
	}

	// go back to drawing mode, and see how picking did
	int hits = glRenderMode(GL_RENDER);
	if (hits) {
		// warning; this just grabs the first object hit - if there
		// are multiple objects, you really want to pick the closest
		// one - see the OpenGL manual 
		// remember: we load names that are one more than the index
		selectedCube = buf[3] - 1;
	}
	else // nothing hit, nothing selected
		selectedCube = -1;
}

void TrainView::drawSleepler(glm::vec3 qt, glm::vec3 trackDir, glm::vec3 trackHDir, bool doingShadows)
{

	float height = 1.f, width = 5.5f, length = 3.f, down = 0.1f;

	glm::vec3 mutouStartR = qt + trackHDir * width;
	glm::vec3 mutouEndR = qt + trackHDir * width + trackDir * length;
	glm::vec3 mutouStartL = qt - trackHDir * width;
	glm::vec3 mutouEndL = qt - trackHDir * width + trackDir * length;

	glm::vec3 mutouDir = glm::normalize(glm::cross(mutouStartR - mutouStartL, mutouStartL - mutouEndL));

	if (style == 0) {
		if (!doingShadows) {
			glColor3ub(140, 111, 88);
		}
		glBegin(GL_QUADS);
		glNormal3f(-mutouDir.x, -mutouDir.y, -mutouDir.z);
		glVertex3f((mutouStartR - mutouDir * (down + height)).x, (mutouStartR - mutouDir * (down + height)).y, (mutouStartR - mutouDir * (down + height)).z);
		glVertex3f((mutouEndR - mutouDir * (down + height)).x, (mutouEndR - mutouDir * (down + height)).y, (mutouEndR - mutouDir * (down + height)).z);
		glVertex3f((mutouEndL - mutouDir * (down + height)).x, (mutouEndL - mutouDir * (down + height)).y, (mutouEndL - mutouDir * (down + height)).z);
		glVertex3f((mutouStartL - mutouDir * (down + height)).x, (mutouStartL - mutouDir * (down + height)).y, (mutouStartL - mutouDir * (down + height)).z);

		glNormal3f(mutouDir.x, mutouDir.y, mutouDir.z);
		glVertex3f((mutouStartR - mutouDir * down).x, (mutouStartR - mutouDir * down).y, (mutouStartR - mutouDir * down).z);
		glVertex3f((mutouEndR - mutouDir * down).x, (mutouEndR - mutouDir * down).y, (mutouEndR - mutouDir * down).z);
		glVertex3f((mutouEndL - mutouDir * down).x, (mutouEndL - mutouDir * down).y, (mutouEndL - mutouDir * down).z);
		glVertex3f((mutouStartL - mutouDir * down).x, (mutouStartL - mutouDir * down).y, (mutouStartL - mutouDir * down).z);

		glNormal3f(trackHDir.x, trackHDir.y, trackHDir.z);
		glVertex3f((mutouStartR - mutouDir * (down + height)).x, (mutouStartR - mutouDir * (down + height)).y, (mutouStartR - mutouDir * (down + height)).z);
		glVertex3f((mutouEndR - mutouDir * (down + height)).x, (mutouEndR - mutouDir * (down + height)).y, (mutouEndR - mutouDir * (down + height)).z);
		glVertex3f((mutouEndR - mutouDir * down).x, (mutouEndR - mutouDir * down).y, (mutouEndR - mutouDir * down).z);
		glVertex3f((mutouStartR - mutouDir * down).x, (mutouStartR - mutouDir * down).y, (mutouStartR - mutouDir * down).z);

		glNormal3f(-trackHDir.x, -trackHDir.y, -trackHDir.z);
		glVertex3f((mutouEndL - mutouDir * (down + height)).x, (mutouEndL - mutouDir * (down + height)).y, (mutouEndL - mutouDir * (down + height)).z);
		glVertex3f((mutouStartL - mutouDir * (down + height)).x, (mutouStartL - mutouDir * (down + height)).y, (mutouStartL - mutouDir * (down + height)).z);
		glVertex3f((mutouStartL - mutouDir * down).x, (mutouStartL - mutouDir * down).y, (mutouStartL - mutouDir * down).z);
		glVertex3f((mutouEndL - mutouDir * down).x, (mutouEndL - mutouDir * down).y, (mutouEndL - mutouDir * down).z);

		glNormal3f(-trackDir.x, -trackDir.y, -trackDir.z);
		glVertex3f((mutouStartR - mutouDir * (down + height)).x, (mutouStartR - mutouDir * (down + height)).y, (mutouStartR - mutouDir * (down + height)).z);
		glVertex3f((mutouStartL - mutouDir * (down + height)).x, (mutouStartL - mutouDir * (down + height)).y, (mutouStartL - mutouDir * (down + height)).z);
		glVertex3f((mutouStartL - mutouDir * down).x, (mutouStartL - mutouDir * down).y, (mutouStartL - mutouDir * down).z);
		glVertex3f((mutouStartR - mutouDir * down).x, (mutouStartR - mutouDir * down).y, (mutouStartR - mutouDir * down).z);

		glNormal3f(trackDir.x, trackDir.y, trackDir.z);
		glVertex3f((mutouEndR - mutouDir * (down + height)).x, (mutouEndR - mutouDir * (down + height)).y, (mutouEndR - mutouDir * (down + height)).z);
		glVertex3f((mutouEndL - mutouDir * (down + height)).x, (mutouEndL - mutouDir * (down + height)).y, (mutouEndL - mutouDir * (down + height)).z);
		glVertex3f((mutouEndL - mutouDir * down).x, (mutouEndL - mutouDir * down).y, (mutouEndL - mutouDir * down).z);
		glVertex3f((mutouEndR - mutouDir * down).x, (mutouEndR - mutouDir * down).y, (mutouEndR - mutouDir * down).z);
		glEnd();
	}
	else if (style == 1) {
		if (!doingShadows) 
			glColor3ub(49, 37, 30);
		
		glLineWidth(3);
		glBegin(GL_LINES);
		glNormal3f(mutouDir.x, mutouDir.y, mutouDir.z);
		glVertex3f(mutouStartR.x, mutouStartR.y, mutouStartR.z);
		glVertex3f(mutouStartL.x, mutouStartL.y, mutouStartL.z);
		glEnd();
	}
	else {
		glPushMatrix();
		glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), qt)));
		float angle = glm::acos(qMin(qMax(glm::dot(glm::vec3(0, 0, 1), trackHDir), -1.0f), 1.0f));
		glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), angle, glm::cross(glm::vec3(0, 0, 1), trackHDir))));
		drawCylinder(2.5, 0.3, doingShadows,glm::vec3(210, 105, 30));
		glPopMatrix();
	}
}

void TrainView::drawCar(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, int k) {

	TransformMatrix = glm::mat4(1.0f);
	TransformMatrix = glm::translate(TransformMatrix, pos + up*0.3f);

	RotationMatrix = glm::mat4(1.0f);
	float angle;
	glm::vec3 rotateAxis;

	//旋转y轴
	angle = glm::acos(qMin(qMax(glm::dot(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir), -1.0f), 1.0f));
	rotateAxis = glm::cross(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RotationMatrix = glm::rotate(RotationMatrix, angle, rotateAxis);
	}

	//旋转z轴
	angle = glm::acos(qMin(qMax(glm::dot(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z))), -1.0f), 1.0f));
	rotateAxis = glm::cross(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z)));
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RotationMatrix = glm::rotate(RotationMatrix, angle, rotateAxis);
	}

	//旋转x轴
	glm::vec3 temp = RotationMatrix * glm::vec4(m_train->carUp, 1);
	glm::mat4 RRotationMatrix = glm::mat4(1.0f);

	angle = glm::acos(qMin(qMax(glm::dot(temp, up), -1.0f), 1.0f));
	rotateAxis = glm::cross(temp, up);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RRotationMatrix = glm::rotate(RRotationMatrix, angle, rotateAxis);
	}
	RotationMatrix = RRotationMatrix * RotationMatrix;

	m_train->Begin();
		//Active Texture
		glActiveTexture(GL_TEXTURE0);
		//Bind square's texture
		Textures[1]->bind();
		//pass texture to shader
		m_train->shaderProgram->setUniformValue("Texture", 0);
		//Call square's render function, pass ModelViewMatrex and ProjectionMatrex
		m_train->Paint(ProjectionMatrex, ModelViewMatrex, RotationMatrix, TransformMatrix, k);
	m_train->End();

}

void TrainView::drawCarHead(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows) {

	glm::mat4 HeadTransformMatrix = glm::mat4(1.0f);
	HeadTransformMatrix = glm::translate(HeadTransformMatrix, pos + up * 7.6f);

	glm::mat4 HeadRotationMatrix = glm::mat4(1.0f);
	float angle;
	glm::vec3 rotateAxis;

	//旋转y轴
	angle = glm::acos(qMin(qMax(glm::dot(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir), -1.0f), 1.0f));
	rotateAxis = glm::cross(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转z轴
	angle = glm::acos(qMin(qMax(glm::dot(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z))), -1.0f), 1.0f));
	rotateAxis = glm::cross(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z)));
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转x轴
	glm::vec3 temp = HeadRotationMatrix * glm::vec4(m_train->carUp, 1);
	glm::mat4 RRotationMatrix = glm::mat4(1.0f);

	angle = glm::acos(qMin(qMax(glm::dot(temp, up), -1.0f), 1.0f));
	rotateAxis = glm::cross(temp, up);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RRotationMatrix = glm::rotate(RRotationMatrix, angle, rotateAxis);
	}
	HeadRotationMatrix = RRotationMatrix * HeadRotationMatrix;

	if (doingShadows)
		trainHead->renderShadow(HeadRotationMatrix, HeadTransformMatrix);
	else
		trainHead->render(HeadRotationMatrix, HeadTransformMatrix, false, false);

}

void TrainView::drawCarTail(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows) {

	glm::mat4 HeadTransformMatrix = glm::mat4(1.0f);
	HeadTransformMatrix = glm::translate(HeadTransformMatrix, pos + up * 6.4f);

	glm::mat4 HeadRotationMatrix = glm::mat4(1.0f);
	float angle;
	glm::vec3 rotateAxis;

	//旋转y轴
	angle = glm::acos(qMin(qMax(glm::dot(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir), -1.0f), 1.0f));
	rotateAxis = glm::cross(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转z轴
	angle = glm::acos(qMin(qMax(glm::dot(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z))), -1.0f), 1.0f));
	rotateAxis = glm::cross(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z)));
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转x轴
	glm::vec3 temp = HeadRotationMatrix * glm::vec4(m_train->carUp, 1);
	glm::mat4 RRotationMatrix = glm::mat4(1.0f);

	angle = glm::acos(qMin(qMax(glm::dot(temp, up), -1.0f), 1.0f));
	rotateAxis = glm::cross(temp, up);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RRotationMatrix = glm::rotate(RRotationMatrix, angle, rotateAxis);
	}
	HeadRotationMatrix = RRotationMatrix * HeadRotationMatrix;

	if(doingShadows)
		trainTail->renderShadow(HeadRotationMatrix, HeadTransformMatrix);
	else
		trainTail->render(HeadRotationMatrix, HeadTransformMatrix, false, false);

}

void TrainView::drawDogOnCar(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, bool doingShadows) {

	glm::mat4 HeadTransformMatrix = glm::mat4(1.0f);
	if(m_pTrack->standCarIndex == -1)
		HeadTransformMatrix = glm::translate(HeadTransformMatrix, pos + up * (m_train->height * 2.f-0.2f) + dir * 2.2f);
	else if(m_pTrack->standCarIndex == m_train->carNum)
		HeadTransformMatrix = glm::translate(HeadTransformMatrix, pos + up * (m_train->height * 2.f-0.1f));
	else
		HeadTransformMatrix = glm::translate(HeadTransformMatrix, pos + up * (m_train->height * 2.f-1.f));

	glm::mat4 HeadRotationMatrix = glm::mat4(1.0f);
	float angle;
	glm::vec3 rotateAxis;

	//旋转y轴
	angle = glm::acos(qMin(qMax(glm::dot(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir), -1.0f), 1.0f));
	rotateAxis = glm::cross(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转z轴
	angle = glm::acos(qMin(qMax(glm::dot(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z))), -1.0f), 1.0f));
	rotateAxis = glm::cross(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z)));
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		HeadRotationMatrix = glm::rotate(HeadRotationMatrix, angle, rotateAxis);
	}

	//旋转x轴
	glm::vec3 temp = HeadRotationMatrix * glm::vec4(m_train->carUp, 1);
	glm::mat4 RRotationMatrix = glm::mat4(1.0f);

	angle = glm::acos(qMin(qMax(glm::dot(temp, up), -1.0f), 1.0f));
	rotateAxis = glm::cross(temp, up);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RRotationMatrix = glm::rotate(RRotationMatrix, angle, rotateAxis);
	}
	HeadRotationMatrix = RRotationMatrix * HeadRotationMatrix;

	if (doingShadows)
		dog->renderShadow(HeadRotationMatrix, HeadTransformMatrix);
	else
		dog->render(HeadRotationMatrix, HeadTransformMatrix, false, false);

}

void TrainView::drawWheel(glm::vec3 pos, glm::vec3 dir, glm::vec3 up) {

	TransformMatrix = glm::mat4(1.0f);
	TransformMatrix = glm::translate(TransformMatrix, pos + glm::vec3(0, 0.3, 0));

	RotationMatrix = glm::mat4(1.0f);
	float angle;
	glm::vec3 rotateAxis;

	//旋转y轴
	angle = glm::acos(qMin(qMax(glm::dot(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir), -1.0f), 1.0f));
	rotateAxis = glm::cross(glm::normalize(glm::vec3(dir.x, 0, dir.z)), dir);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RotationMatrix = glm::rotate(RotationMatrix, angle, rotateAxis);
	}

	//旋转z轴
	angle = glm::acos(qMin(qMax(glm::dot(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z))), -1.0f), 1.0f));
	rotateAxis = glm::cross(m_train->carDir, glm::normalize(glm::vec3(dir.x, 0, dir.z)));
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RotationMatrix = glm::rotate(RotationMatrix, angle, rotateAxis);
	}

	//旋转x轴
	glm::vec3 temp = RotationMatrix * glm::vec4(m_train->carUp, 1);
	glm::mat4 RRotationMatrix = glm::mat4(1.0f);

	angle = glm::acos(qMin(qMax(glm::dot(temp, up), -1.0f), 1.0f));
	rotateAxis = glm::cross(temp, up);
	if (angle != 0 && glm::length(rotateAxis) != 0) {
		RRotationMatrix = glm::rotate(RRotationMatrix, angle, rotateAxis);
	}
	RotationMatrix = RRotationMatrix * RotationMatrix;

	m_wheel->Begin();
	m_wheel->Paint(ProjectionMatrex, ModelViewMatrex, RotationMatrix, TransformMatrix);
	m_wheel->End();

}

void TrainView::drawTrack(bool doingShadows) {

	//轨道类型 单轨 双轨 路
	switch (track) {
	case 0:
	{
		if (style == 2) {
			glPushMatrix();
			glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), (qt0 + qt1) / 2.f)));
			float angle = glm::acos(qMin(qMax(glm::dot(glm::vec3(0, 0, 1), qt1 - qt0), -1.0f), 1.0f));
			glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), angle, glm::cross(glm::vec3(0, 0, 1), qt1 - qt0))));
			drawCylinder(glm::distance(qt0, qt1), 0.3, doingShadows, glm::vec3(210, 105, 30));
			glPopMatrix();
		}
		else {
			if (style == 0)
				glLineWidth(3);
			else if (style == 1)
				glLineWidth(1);

			glBegin(GL_LINE_LOOP);
			if (!doingShadows) 
				glColor3ub(49, 37, 30);
			
			glVertex3f(qt0.x, qt0.y, qt0.z);
			glVertex3f(qt1.x, qt1.y, qt1.z);

			glEnd();
		}

	}break;
	case 1:
	{
		if(style == 2) {
			glPushMatrix();
			glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), (qt0 + qt1) / 2.f + trackHDir * 2.5f)));
			float angle = glm::acos(qMin(qMax(glm::dot(glm::vec3(0, 0, 1), qt1 - qt0), -1.0f), 1.0f));
			glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), angle, glm::cross(glm::vec3(0, 0, 1), qt1 - qt0))));
			drawCylinder(glm::distance(qt0, qt1), 0.3, doingShadows, glm::vec3(210, 105, 30));
			glPopMatrix();

			glPushMatrix();
			glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), (qt0 + qt1) / 2.f - trackHDir * 2.5f)));
			angle = glm::acos(qMin(qMax(glm::dot(glm::vec3(0, 0, 1), qt1 - qt0), -1.0f), 1.0f));
			glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), angle, glm::cross(glm::vec3(0, 0, 1), qt1 - qt0))));
			drawCylinder(glm::distance(qt0, qt1), 0.3, doingShadows, glm::vec3(210, 105, 30));
			glPopMatrix();
		}
		else {
			if (style == 0)
				glLineWidth(3);
			else if (style == 1)
				glLineWidth(1);

			glBegin(GL_LINES);
			if (!doingShadows) 
				glColor3ub(49, 37, 30);

			glVertex3f((preP + preTrackHDir * 2.5f).x, (preP + preTrackHDir * 2.5f).y, (preP + preTrackHDir * 2.5f).z);
			glVertex3f((qt0 + trackHDir * 2.5f).x, (qt0 + trackHDir * 2.5f).y, (qt0 + trackHDir * 2.5f).z);
			glVertex3f((qt0 - trackHDir * 2.5f).x, (qt0 - trackHDir * 2.5f).y, (qt0 - trackHDir * 2.5f).z);
			glVertex3f((preP - preTrackHDir * 2.5f).x, (preP - preTrackHDir * 2.5f).y, (preP - preTrackHDir * 2.5f).z);
			glVertex3f((qt0 + trackHDir * 2.5f).x, (qt0 + trackHDir * 2.5f).y, (qt0 + trackHDir * 2.5f).z);
			glVertex3f((qt1 + trackHDir * 2.5f).x, (qt1 + trackHDir * 2.5f).y, (qt1 + trackHDir * 2.5f).z);
			glVertex3f((qt1 - trackHDir * 2.5f).x, (qt1 - trackHDir * 2.5f).y, (qt1 - trackHDir * 2.5f).z);
			glVertex3f((qt0 - trackHDir * 2.5f).x, (qt0 - trackHDir * 2.5f).y, (qt0 - trackHDir * 2.5f).z);

			glEnd();
		}
		
	}break;
	case 2:
	{
		glBegin(GL_QUADS);
		if (!doingShadows) {
			if(style == 2)
				glColor3ub(255, 128, 51);
			else
				glColor3ub(49, 37, 30);
		}

		glVertex3f((preP + preTrackHDir * 2.5f).x, (preP + preTrackHDir * 2.5f).y, (preP + preTrackHDir * 2.5f).z);
		glVertex3f((qt0 + trackHDir * 2.5f).x, (qt0 + trackHDir * 2.5f).y, (qt0 + trackHDir * 2.5f).z);
		glVertex3f((qt0 - trackHDir * 2.5f).x, (qt0 - trackHDir * 2.5f).y, (qt0 - trackHDir * 2.5f).z);
		glVertex3f((preP - preTrackHDir * 2.5f).x, (preP - preTrackHDir * 2.5f).y, (preP - preTrackHDir * 2.5f).z);
		glVertex3f((qt0 + trackHDir * 2.5f).x, (qt0 + trackHDir * 2.5f).y, (qt0 + trackHDir * 2.5f).z);
		glVertex3f((qt1 + trackHDir * 2.5f).x, (qt1 + trackHDir * 2.5f).y, (qt1 + trackHDir * 2.5f).z);
		glVertex3f((qt1 - trackHDir * 2.5f).x, (qt1 - trackHDir * 2.5f).y, (qt1 - trackHDir * 2.5f).z);
		glVertex3f((qt0 - trackHDir * 2.5f).x, (qt0 - trackHDir * 2.5f).y, (qt0 - trackHDir * 2.5f).z);

		glEnd();
	}break;
	default:break;
	}

}

bool TrainView::convertAxis(glm::vec3 sourceVec, glm::vec3 targetVec) {
	glm::vec3 source = glm::vec3(sourceVec.x, sourceVec.y, 0);
	glm::vec3 target = glm::vec3(targetVec.x, targetVec.y, 0);
	glm::vec3 cross = glm::cross(source, target);
	if (cross.z > 0)
		return true;
	else
		return false;

}

void TrainView::findCarPos(bool doingShadows, float drawedDistance)
{
	for (int k = -1; k <= m_train->carNum; k++) {
		float currentTrainU = m_pTrack->trainU - (m_train->len *2.f + 1) * k;
		if (k == -1)
			currentTrainU += 3;
		else if (k == m_train->carNum)
			currentTrainU -= 2;

		if (currentTrainU < 0)
			currentTrainU = m_pTrack->totalLen + (currentTrainU - (int)(currentTrainU / m_pTrack->totalLen) * m_pTrack->totalLen);
		if (currentTrainU > m_pTrack->totalLen)
			currentTrainU -= m_pTrack->totalLen;

		if (drawedDistance <= currentTrainU && drawedDistance + glm::distance(qt0, qt1) > currentTrainU) {

			carPos = qt0 + trackDir * (currentTrainU - drawedDistance);
			carDir = trackDir;
			carUp = glm::normalize(glm::cross(trackDir, trackHDir));

			//重力
			if (m_pTrack->physics && k == -1 && isrun) {
				/*float h = carPos.y - m_pTrack->headPos.y;
				if (h > 0)
					m_pTrack->speed -= sqrt(2. * h)/9.f;
				else
					m_pTrack->speed += sqrt(2. * (-h))/9.f;*/

				m_pTrack->a = glm::dot(carDir, glm::vec3(0, -1, 0)) / 4.f;
				m_pTrack->speed += m_pTrack->a;
			}

			if (k == m_pTrack->standCarIndex) {
				m_pTrack->carPos = carPos;
				m_pTrack->carDir = carDir;
				m_pTrack->carUp = carUp;
			}

			if (k == -1) {
				m_pTrack->headDir = carDir;
				m_pTrack->headPos = carPos;
				m_pTrack->headUp = carUp;
				continue;
			}
			else if (k == m_train->carNum) {
				m_pTrack->tailDir = carDir;
				m_pTrack->tailPos = carPos;
				m_pTrack->tailUp = carUp;
				continue;
			}

			drawCar(carPos, carDir, carUp, k);
		}

		//车轮子
		if(!(m_pTrack->standCarIndex == -1 && camera == 2))
			findWheelPos(currentTrainU, drawedDistance, k);
	}
}

void TrainView::drawTrackPillar(glm::vec3 pos, glm::vec3 dir, bool doingShadows) {

	glm::vec3 up = glm::vec3(0, 1, 0);
	glm::vec3 pillarHDir = glm::normalize(glm::cross(up, dir));

	glPushMatrix();
	glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), pos - glm::vec3(0,1,0)*pos.y/2.f + trackHDir * 2.5f - up * 0.1f)));
	glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), 1.57f, glm::vec3(1,0,0))));
	drawCylinder(pos.y / 2.f, 0.6, doingShadows, glm::vec3(128, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glMultMatrixf((const float*)glm::value_ptr(glm::translate(glm::mat4(1.0f), pos - glm::vec3(0, 1, 0)*pos.y / 2.f - trackHDir * 2.5f - up * 0.1f)));
	glMultMatrixf((const float*)glm::value_ptr(glm::rotate(glm::mat4(1.0f), 1.57f, glm::vec3(1, 0, 0))));
	drawCylinder(pos.y / 2.f, 0.6, doingShadows, glm::vec3(128, 0, 0));
	glPopMatrix();

}

void TrainView::drawCylinder(float height, float r, bool doingShadows, glm::vec3 color) {

	if (!doingShadows)
		glColor3ub(color.x, color.y, color.z);

	glBegin(GL_TRIANGLES);
	for (int j = 0; j < 360; j += 15)
	{
		float p1 = j * 3.14 / 180;
		float p2 = (j + 15) * 3.14 / 180;
		glm::vec3 nextPos1 = glm::normalize(glm::vec3(sin(p1), cos(p1), 0.0f))*r;
		glm::vec3 nextPos2 = glm::normalize(glm::vec3(sin(p2), cos(p2), 0.0f))*r;

		glm::vec3 a = nextPos1 + glm::vec3(0, 0, 1) * height;
		glm::vec3 b = nextPos1 - glm::vec3(0, 0, 1) * height;
		glm::vec3 c = nextPos2 + glm::vec3(0, 0, 1) * height;
		glm::vec3 d = nextPos2 - glm::vec3(0, 0, 1) * height;

		glNormal3f(0, 0, 1);
		glVertex3f(0, 0, 0 + height);
		glVertex3f(nextPos1.x, nextPos1.y, nextPos1.z + height);
		glVertex3f(nextPos2.x, nextPos2.y, nextPos2.z + height);
		glNormal3f(0, 0, -1);
		glVertex3f(0, 0, 0 - height);
		glVertex3f(nextPos1.x, nextPos1.y, nextPos1.z - height);
		glVertex3f(nextPos2.x, nextPos2.y, nextPos2.z - height);
		glNormal3f(((nextPos1 + nextPos2) / 2.f).x, ((nextPos1 + nextPos2) / 2.f).y, ((nextPos1 + nextPos2) / 2.f).z);
		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);
		glVertex3f(c.x, c.y, c.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(d.x, d.y, d.z);
	}

	glEnd();
	glPopMatrix();
}

void TrainView::findWheelPos(float currentTrainU, float drawedDistance, int k) {
	float frontWheel = currentTrainU + 3.f;
	float backWheel = currentTrainU - 3.f;

	if (k == -1) {
		frontWheel += 2.45f;
		backWheel -= 3.1f;
	}
	else if (k == m_train->carNum) {
		frontWheel += 1.6f;
		backWheel -= 1.6f;
	}

	if (backWheel < 0)
		backWheel = m_pTrack->totalLen + backWheel;
	if (frontWheel >= m_pTrack->totalLen)
		frontWheel -= m_pTrack->totalLen;

	glm::vec3 wheelPos, wheelDir, wheelUp;
	if (drawedDistance <= frontWheel && drawedDistance + glm::distance(qt0, qt1) > frontWheel) {

		wheelPos = qt0 + trackDir * (frontWheel - drawedDistance);
		wheelDir = trackDir;
		wheelUp = glm::normalize(glm::cross(trackDir, trackHDir));

		drawWheel(wheelPos, wheelDir, wheelUp);
	}

	if (drawedDistance <= backWheel && drawedDistance + glm::distance(qt0, qt1) > backWheel) {

		wheelPos = qt0 + trackDir * (backWheel - drawedDistance);
		wheelDir = trackDir;
		wheelUp = glm::normalize(glm::cross(trackDir, trackHDir));

		drawWheel(wheelPos, wheelDir, wheelUp);
	}

	if (k == -1) {

		frontWheel -= 3.06f;
		backWheel = frontWheel - 3.06f;

		if (backWheel < 0)
			backWheel = m_pTrack->totalLen + backWheel;
		if (frontWheel >= m_pTrack->totalLen)
			frontWheel -= m_pTrack->totalLen;

		if (drawedDistance <= frontWheel && drawedDistance + glm::distance(qt0, qt1) > frontWheel) {

			wheelPos = qt0 + trackDir * (frontWheel - drawedDistance);
			wheelDir = trackDir;
			wheelUp = glm::normalize(glm::cross(trackDir, trackHDir));

			drawWheel(wheelPos, wheelDir, wheelUp);
		}

		if (drawedDistance <= backWheel && drawedDistance + glm::distance(qt0, qt1) > backWheel) {

			wheelPos = qt0 + trackDir * (backWheel - drawedDistance);
			wheelDir = trackDir;
			wheelUp = glm::normalize(glm::cross(trackDir, trackHDir));

			drawWheel(wheelPos, wheelDir, wheelUp);
		}
	}
	if (k == m_train->carNum) {

		frontWheel -= 3.06f;

		if (frontWheel >= m_pTrack->totalLen)
			frontWheel -= m_pTrack->totalLen;

		if (drawedDistance <= frontWheel && drawedDistance + glm::distance(qt0, qt1) > frontWheel) {

			wheelPos = qt0 + trackDir * (frontWheel - drawedDistance);
			wheelDir = trackDir;
			wheelUp = glm::normalize(glm::cross(trackDir, trackHDir));

			drawWheel(wheelPos, wheelDir, wheelUp);
		}
	}
}