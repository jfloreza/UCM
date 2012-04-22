// Camera.cpp

#include "camera.h"
#include <math.h>

#define PI	3.14159

Camera::Camera()
{
	x = 15; y = 0; z = 5;
	ang = -90;
}

void Camera::rotangle(int pos)
{
	if(pos == 1)ang+=18.0;
	else
		ang-=18.0;
	x = 15 * sin(-ang * (PI / 180.0));
	y = 15 * cos(-ang * (PI / 180.0));
}

int Camera::getx()
{
	return x;
}

int Camera::gety()
{
	return y;
}

int Camera::getz()
{
	return z;
}