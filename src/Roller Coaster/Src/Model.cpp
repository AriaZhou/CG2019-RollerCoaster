#include "model.h"

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QVarLengthArray>

#include <QtOpenGL/QtOpenGL>

Model::Model(const QString &filePath, int s, glm::vec3 p)
	: m_fileName(QFileInfo(filePath).fileName())
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
		return;

	boundsMin = glm::vec3(1e9, 1e9, 1e9);
	boundsMax = glm::vec3(-1e9, -1e9, -1e9);

	QTextStream in(&file);
	while (!in.atEnd()) {
		QString input = in.readLine();
		if (input.isEmpty() || input[0] == '#')
			continue;

		QTextStream ts(&input);
		QString id;
		ts >> id;
		if (id == "v") {
			glm::vec3 p;
			for (int i = 0; i < 3; ++i) {
				ts >> p[i];
				boundsMin[i] = qMin(boundsMin[i], p[i]);
				boundsMax[i] = qMax(boundsMax[i], p[i]);
			}
			m_points << p;
			//m_colors << glm::vec3(0.725, 0.48, 0.337);
			m_colors << currentColor;
		}
		else if (id == "f" || id == "fo") {
			QVarLengthArray<int, 4> p;

			while (!ts.atEnd()) {
				QString vertex;
				ts >> vertex;
				const int vertexIndex = vertex.split('/').value(0).toInt();
				if (vertexIndex)
					p.append(vertexIndex > 0 ? vertexIndex - 1 : m_points.size() + vertexIndex);
			}

			for (int i = 0; i < p.size(); ++i) {
				const int edgeA = p[i];
				const int edgeB = p[(i + 1) % p.size()];

				if (edgeA < edgeB) {
					m_edgeIndices << edgeA << edgeB;
				}
			}

			for (int i = 0; i < 3; ++i) {
				m_pointIndices << p[i];
			}

			if (p.size() == 4)
				for (int i = 0; i < 3; ++i) {
					m_pointIndices << p[(i + 2) % 4];
				}

		}
		else if (id == "usemtl") {
			QString value;
			ts >> value;
			if (value == "Mat_0")
				currentColor = glm::vec3(185. / 255., 122. / 255., 86. / 255.);
			else if (value == "Mat_1")
				currentColor = glm::vec3(0./255., 0./255., 0./255.);
			else if (value == "Mat_2")
				currentColor = glm::vec3(73. / 255., 25. / 255., 10. / 255.);
			else if (value == "Mat_3")
				currentColor = glm::vec3(255. / 255., 255. / 255., 255. / 255.);
			else if (value == "Mat_4")
				currentColor = glm::vec3(88. / 255., 88. / 255., 88. / 255.);
			else if (value == "Mat_5")
				currentColor = glm::vec3(235. / 255., 236. / 255., 166. / 255.);
			else if (value == "68_0")
				currentColor = glm::vec3(21./255., 81./255., 45./255.);
			else if (value == "74_0")
				currentColor = glm::vec3(73./255., 25./255., 10./255.);
			else
				currentColor = glm::vec3(1, 1, 1);
		}
		else if (id == "vt") {

		}
	}

	const glm::vec3 bounds = boundsMax - boundsMin;
	const qreal scale = s / qMax(bounds.x, qMax(bounds.y, bounds.z));
	for (int i = 0; i < m_points.size(); ++i)
		m_points[i] = (m_points[i] + p - (boundsMin + bounds * 0.5f)) * (float)scale;

	m_normals.resize(m_points.size());
	for (int i = 0; i < m_pointIndices.size(); i += 3) {
		const glm::vec3 a = m_points.at(m_pointIndices.at(i));
		const glm::vec3 b = m_points.at(m_pointIndices.at(i + 1));
		const glm::vec3 c = m_points.at(m_pointIndices.at(i + 2));

		const glm::vec3 normal = glm::normalize(glm::cross(b - a, c - a));

		for (int j = 0; j < 3; ++j)
			m_normals[m_pointIndices.at(i + j)] += normal;
	}

	for (int i = 0; i < m_normals.size(); ++i)
		m_normals[i] = glm::normalize(m_normals[i]);
}

void Model::renderShadow(glm::mat4 rotateMat, glm::mat4 transformationMat) const
{
	setupShadows();
	glm::mat4 fuzheng = glm::mat4(1.0f);
	fuzheng = glm::rotate(fuzheng, 3.1415926f, glm::vec3(0, 1, 0));
	fuzheng = glm::rotate(fuzheng, 1.57f, glm::vec3(-1, 0, 0));
	glMultMatrixf((const float*)glm::value_ptr(transformationMat));
	glMultMatrixf((const float*)glm::value_ptr(rotateMat));
	glMultMatrixf((const float*)glm::value_ptr(fuzheng));

	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, (float *)m_points.data());
	glDrawElements(GL_TRIANGLES, m_pointIndices.size(), GL_UNSIGNED_INT, m_pointIndices.data());

	glDisableClientState(GL_VERTEX_ARRAY);
	unsetupShadows();

}

void Model::render(glm::mat4 rotateMat, glm::mat4 transformationMat, bool wireframe, bool normal) const
{

	glm::mat4 fuzheng = glm::mat4(1.0f);
	fuzheng = glm::rotate(fuzheng, 3.1415926f, glm::vec3(0, 1, 0));
	fuzheng = glm::rotate(fuzheng, 1.57f, glm::vec3(-1, 0, 0));
	glPushMatrix();
	glMultMatrixf((const float*)glm::value_ptr(transformationMat));
	glMultMatrixf((const float*)glm::value_ptr(rotateMat));
	glMultMatrixf((const float*)glm::value_ptr(fuzheng));

	glEnableClientState(GL_VERTEX_ARRAY);
	if (wireframe) {
		glVertexPointer(3, GL_FLOAT, 0, (float *)m_points.data());
		//glTexCoordPointer();
		glDrawElements(GL_LINES, m_edgeIndices.size(), GL_UNSIGNED_INT, m_edgeIndices.data());
	}
	else {
		glEnable(GL_DEPTH_TEST);
		glEnableClientState(GL_COLOR_ARRAY);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
		glShadeModel(GL_SMOOTH);

		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, (float *)m_points.data());
		glColorPointer(3, GL_FLOAT, 0, (float *)m_colors.data());
		glNormalPointer(GL_FLOAT, 0, (float *)m_normals.data());
		glDrawElements(GL_TRIANGLES, m_pointIndices.size(), GL_UNSIGNED_INT, m_pointIndices.data());

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisable(GL_DEPTH_TEST);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}