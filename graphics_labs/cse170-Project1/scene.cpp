#include "scene.h"

Scene::Scene()
{
	maxX = 500;
	maxY = 500;
	maxZ = 500;
}

void Scene::draw_Scene()
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glColor3f(0.2, 0.6, 0.2);

	glBegin(GL_QUADS);
	glVertex3d(-maxX, -maxY, -1.0);
	glVertex3d(maxX, -maxY, -1.0);
	glVertex3d(maxX, maxY, -1.0);
	glVertex3d(-maxX, maxY, -1.0);
	glEnd();


	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex3d(10.0, 10.0, 50.0);
	glVertex3d(10.0, 20.0, 50.0);
	glVertex3d(20.0, 20.0, 50.0);
	glVertex3d(20.0, 10.0, 50.0);

	glVertex3d(10.0, 10.0, 0.0);
	glVertex3d(10.0, 20.0, 0.0);
	glVertex3d(20.0, 20.0, 0.0);
	glVertex3d(20.0, 10.0, 0.0);

	glVertex3d(10.0, 10.0, 50.0);
	glVertex3d(10.0, 20.0, 50.0);
	glVertex3d(10.0, 20.0, 0.0);
	glVertex3d(10.0, 10.0, 0.0);
	

	glVertex3d(20.0, 20.0, 50.0);
	glVertex3d(20.0, 10.0, 50.0);
	glVertex3d(20.0, 10.0, 0.0);
	glVertex3d(20.0, 20.0, 0.0);
	
	glVertex3d(10.0, 20.0, 50.0);
	glVertex3d(20.0, 10.0, 50.0);
	glVertex3d(20.0, 10.0, 0.0);
	glVertex3d(10.0, 20.0, 0.0);


	glVertex3d(30.0, -10.0, 50.0);
	glVertex3d(30.0, -20.0, 50.0);
	glVertex3d(40.0, -20.0, 50.0);
	glVertex3d(40.0, -10.0, 50.0);

	glVertex3d(30.0, -10.0, 0.0);
	glVertex3d(30.0, -20.0, 0.0);
	glVertex3d(40.0, -20.0, 0.0);
	glVertex3d(40.0, -10.0, 0.0);

	glVertex3d(30.0, -10.0, 50.0);
	glVertex3d(30.0, -20.0, 50.0);
	glVertex3d(30.0, -20.0, 0.0);
	glVertex3d(30.0, -10.0, 0.0);
	
	glVertex3d(40.0, -20.0, 50.0);
	glVertex3d(40.0, -10.0, 50.0);
	glVertex3d(40.0, -10.0, 0.0);
	glVertex3d(40.0, -20.0, 0.0);

	glVertex3d(30.0, -20.0, 50.0);
	glVertex3d(40.0, -10.0, 50.0);
	glVertex3d(40.0, -10.0, 0.0);
	glVertex3d(30.0, -20.0, 0.0);
	
	glEnd();

	/*glPushMatrix();
	glTranslated(10, 23, 0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 23, 0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(13, 51, 0);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(83, 94, 0);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(51, -90, 0);
	glColor3f(1.0, 1.0, 1.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-63, -23, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(162, 12, 0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(10);
	glPopMatrix();*/
}