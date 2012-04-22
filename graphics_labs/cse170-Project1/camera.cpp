// Camera.cpp

#include "camera.h"
#include <math.h>

#define PI	3.14159

Camera::Camera()
{
	x = 100; y = 100; z = 100;
}

double Camera::getx()
{
	return x;
}

double Camera::gety()
{
	return y;
}

double Camera::getz()
{
	return z;
}