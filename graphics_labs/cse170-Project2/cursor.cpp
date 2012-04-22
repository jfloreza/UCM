//Cursor.cpp

#include <math.h>
#include "cursor.h"
#include "glutapp.h"

# define PI		3.14159

Cursor::Cursor() {
	flag = false;
}

void Cursor::draw_cursor(int _i, int _j) {
	if (flag == false) {
		glColor3f(1.0, 1.0, 1.0);
	} else
		glColor3f(0.0, 0.0, 0.0);

	float x, y;
	float i = float(_i);
	float j = float(_j);

	float ang; //staring angle
	if (i == 0) {
		ang = 0;
	} else
		ang = 18.0 * i;


	//Draw first block
	x = cos(ang * (PI / 180.0)) * 3.2;
	y = sin(ang * (PI / 180.0)) * 3.2;
	glPushMatrix();
	glTranslatef(x, y, j);
	glutWireCube(1.2f);
	glPopMatrix();
}

void Cursor::blink(bool val) {
	flag = val;
}