//Grid.cpp

#include "grid.h"


Grid::Grid()
{

}

void Grid::draw_square()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}

void Grid::draw_sides()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-5.0, 0.0, 0.0);
	glVertex3f(-5.0, 0.0, 20.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(5.0, 0.0, 0.0);
	glVertex3f(5.0, 0.0, 20.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0, -5.0, 0.0);
	glVertex3f(0.0, -5.0, 20.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0, 5.0, 0.0);
	glVertex3f(0.0, 5.0, 20.0);
	glEnd();
}

void Grid::draw_grid()
{
	draw_square();
	draw_sides();
}