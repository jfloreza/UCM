//Blocks.cpp

#include <math.h>
#include "block.h"
#include "glutapp.h"

#define PI	3.14159

Block::Block() {
	type = 0;
	falling = false;
}

Block::Block(int _type) {
	type = _type;
}

int Block::check_type() {
	return type;
}

void Block::set(int _type) {
	type = _type;
}

void Block::draw_block(int _i, int _j) {
	glEnable(GL_COLOR_MATERIAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	float x, y;
	float i = float(_i);
	float j = float(_j);

	float ang; //staring angle
	if (i == 0) {
		ang = 0;
	} else
		ang = 18.0 * i;

	x = cos(ang * (PI / 180.0)) * 3.2;
	y = sin(ang * (PI / 180.0)) * 3.2;

	switch(type) {
		case 0: //No block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			//glutWireCube(1.0f);
			glPopMatrix();
			break;
		case 1: //Red block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(1.0, 0.0, 0.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 2: //Blue block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(0.0, 0.0, 1.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 3: //Green block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(0.0, 1.0, 0.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 4: //Dark Purple
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(0.3, 0.1, 0.6);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 5: //Pink Block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(1.0, 0.0, 1.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 6: //Cyan block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(0.0, 1.0, 1.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 7: //Yellow block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(0.5, 0.5, 0.5);
			glutWireCube(1.0f);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
		case 9: //White grid, losing block
			glPushMatrix();
			glTranslatef(x, y, j);
			glColor3f(1.0, 1.0, 1.0);
			glutSolidCube(1.0f);
			glPopMatrix();
			break;
	}
}

void Block::clear_block() {
	//destroy the block 'cause they lined up
	//TODO: i'm gonna make the blocks explode.  it'll be cool, promise
	type = 0;
}

void Block::select(int _i, int _j) {
	float x, y;
	float i = float(_i);
	float j = float(_j);

	float ang; //staring angle
	if (i == 0) {
		ang = 0;
	} else
		ang = 18.0 * i;


	//Draw first block
	x = cos(ang * (PI / 180.0)) * 3.5;
	y = sin(ang * (PI / 180.0)) * 3.5;
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(x, y, j);
	glutWireCube(1.0f);
	glPopMatrix();
}

void Block::black() {
	type = 9;
}