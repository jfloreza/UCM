//Point.h  Needed to allow each point to move
#ifndef _POINT_H
#define _POINT_H

#include "vec.h"

class Point {
	float x, y, z;
	bool selected;

public:
	Point();
	void set(float _x, float _y, float _z);
	void move(float _x, float _y, float _z);

	float getX();
	float getY();
	float getZ();

	void draw();
	void select();
	void deselect();
};

#endif