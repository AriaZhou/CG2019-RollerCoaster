#ifndef MODEL_H
#define MODEL_H

#include <QtCore/QString>
#include <QtCore/QVector>

#include <math.h>
#include "Utilities/3DUtils.H"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Model
{
public:
	Model() {}
	Model(const QString &filePath, int s, glm::vec3 p);

	void render(glm::mat4 routateMat, glm::mat4 transformationMat, bool wireframe = false, bool normal = false) const;
	void renderShadow(glm::mat4 rotateMat, glm::mat4 transformationMat) const;

	QString fileName() const { return m_fileName; }
	int faces() const { return m_pointIndices.size() / 3; }
	int edges() const { return m_edgeIndices.size() / 2; }
	int points() const { return m_points.size(); }

private:
	QString m_fileName;
	QVector<glm::vec3> m_points;
	QVector<glm::vec3> m_colors;
	QVector<glm::vec3> m_texCoor;
	QVector<glm::vec3> m_normals;
	glm::vec3 currentColor = glm::vec3(185. / 255., 122. / 255., 86. / 255.);
	glm::vec3 boundsMin, boundsMax;

	QVector<int> m_edgeIndices;
	QVector<int> m_pointIndices;
};

#endif