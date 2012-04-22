//Point.cpp
# include "point.h"
# include "glutapp.h"

Point::Point()
{
	x = 0; 
	y = 0; 
	z = 0;
}

void Point::set(float _x, float _y, float _z)
{
	x = _x; y = _y, z = _z;
	selected = false;
}

void Point::move(float _x, float _y, float _z)
{
	x += _x;
	y += _y;
	z += _z;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

float Point::getZ()
{
	return z;
}

void Point::draw()
{
	glDisable(GL_LIGHTING);
	if(selected)glColor3f(1.0, 0.0, 0.0);
	else
		glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex3f(x, y, z);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Point::select()
{
	selected = true;
}

void Point::deselect()
{
	selected = false;
}