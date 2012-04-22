//Helicopter.cpp

#include "helicopter.h"

Helicopter::Helicopter()
{
	posx = 0; posy = 0; posz = 0; roty = 0;
	rotspeed = 0; angle = 0, velocity = 0;
	pitch = 0; hpitch = 0; cockpit = false;
	increase = false;

	//Body and tail
	points[0].set(2.0, 8.0, 0.0);
	points[1].set(2.0, 9.0, 1.0);
	points[2].set(1.0, 7.0, 3.0);
	points[3].set(1.0, 4.0, 4.0);
	points[4].set(2.0, 0.0, 3.5);
	points[5].set(1.0, -3.0, 3.0);
	points[6].set(0.5, -7.0, 2.5);

	points[7].set(0.25, -8.0, 5.0);
	points[8].set(0.25, -10.0, 5.0);
	points[9].set(0.25, -9.5, 2.0);
	points[10].set(0.25, -10.0, 0.0);
	points[11].set(0.25, -8.0, 0.0);
	points[12].set(0.5, -7.0, 1.5);
	points[13].set(1.0, -3.0, 1.0);
	points[14].set(2.0, 0.0, 0.5);
	points[15].set(2.0, 4.0, 0.0);

	points[16].set(-2.0, 8.0, 0.0);
	points[17].set(-2.0, 9.0, 1.0);
	points[18].set(-1.0, 7.0, 3.0);
	points[19].set(-1.0, 4.0, 4.0);
	points[20].set(-2.0, 0.0, 3.5);
	points[21].set(-1.0, -3.0, 3.0);
	points[22].set(-0.5, -7.0, 2.5);

	points[23].set(-0.25, -8.0, 5.0);
	points[24].set(-0.25, -10.0, 5.0);
	points[25].set(-0.25, -9.5, 2.0);
	points[26].set(-0.25, -10.0, 0.0);
	points[27].set(-0.25, -8.0, 0.0);
	points[28].set(-0.5, -7.0, 1.5);
	points[29].set(-1.0, -3.0, 1.0);
	points[30].set(-2.0, 0.0, 0.5);
	points[31].set(-2.0, 4.0, 0.0);

	//Landing rail
	points[32].set(2.0, 4.0, -1.0);
	points[33].set(2.0, 0.0, -1.0);
	points[34].set(-2.0, 4.0, -1.0);
	points[35].set(-2.0, 0.0, -1.0);
	points[36].set(2.0, 5.0, -1.0);
	points[37].set(2.0, -1.0, -1.0);
	points[38].set(-2.0, 5.0, -1.0);
	points[39].set(-2.0, -1.0, -1.0);

	//Blip for top rotor
	points[40].set(0.0, 2.0, 5.0);
	points[41].set(1.0, -9.0, 3.5);

	
}

void Helicopter::draw_helicopter()
{
	glPushMatrix();
	glTranslated(posx, posy, posz);
	glRotatef(roty, 0.0, 0.0, 1.0);
	glRotatef(pitch, 1.0, 0.0, 0.0);
	glRotatef(hpitch, 0.0, 1.0, 0.0);
	draw_body();
	glPopMatrix();

	glPushMatrix();
	glTranslated(posx, posy, posz);
	glRotatef(roty, 0.0, 0.0, 1.0);
	glTranslated(0.0, 2.0, -0.5);
	glRotatef(pitch, 1.0, 0.0, 0.0);
	glRotatef(hpitch, 0.0, 1.0, 0.0);
	glRotated(angle, 0.0, 0.0, 1.0);
	draw_main_rotors();
	glPopMatrix();

	glPushMatrix();
	glTranslated(posx, posy, posz);
	glRotatef(roty, 0.0, 0.0, 1.0);
	glRotatef(pitch, 1.0, 0.0, 0.0);
	glRotatef(hpitch, 0.0, 1.0, 0.0);
	glTranslated(0.0, -8.5, 3.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	draw_back_rotors();
	glPopMatrix();
}

void Helicopter::draw_body()
{
	//Indices for points
	int index[68][3] = {

	//Right Side (14 pts)
	{0, 1, 2}, {0, 2, 15}, {15, 2, 3}, {14, 15, 3},
	{14, 3, 4}, {13, 14, 4}, {13, 4, 5}, {12, 13, 5},
	{12, 5, 6}, {6, 7, 8}, {9, 6, 8}, {9, 12, 6}, 
	{9, 10, 12}, {10, 11, 12},

	//Left Side (14 pts)
	{16, 17, 18}, {16, 18, 31}, {31, 18, 19}, {30, 31, 19},
	{30, 19, 20}, {29, 30, 20}, {29, 20, 21}, {28, 29, 21},
	{28, 21, 22}, {22, 23, 24}, {25, 22, 24}, {25, 28, 22}, 
	{25, 26, 28}, {26, 27, 28},

	//Tops and bottoms (32)
	{1, 17, 2}, {2, 17, 18}, {3, 2, 18}, {3, 18, 19},
	{4, 3, 19}, {4, 19, 20}, {5, 4, 20}, {5, 20, 21},
	{6, 5, 21}, {6, 21, 22}, {7, 6, 22}, {7, 22, 23},
	{8, 9, 23}, {8, 23, 24}, {9, 8, 24}, {9, 24, 25},
	{10, 9, 25}, {10, 25, 26}, {11, 10, 26}, {11, 26, 27},
	{12, 11, 27}, {12, 27, 28}, {13, 12, 28}, {13, 28, 29},
	{14, 13, 29}, {14, 29, 30}, {15, 14, 30}, {15, 30, 31},
	{0, 15, 16}, {0, 31, 16}, {1, 0, 17}, {1, 16, 17},

	//Blip for rotors (8)
	{40, 3, 4}, {40, 3, 19}, {40, 19, 20}, {40, 20, 4},
	{41, 6, 7}, {41, 7, 8}, {41, 8, 9}, {41, 9, 6}
	};

	glEnable(GL_COLOR_MATERIAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	//Draw body
	for (int i = 0; i < 68; i++)
	{
		glColor3f(0.8, 0.8, 0.8);
		if(i == 28 || i == 29)glColor3f(0.0, 0.0, 0.8);
		draw_triangle(points[index[i][0]], points[index[i][1]], points[index[i][2]]);
	}

	glBegin(GL_LINES);
	glVertex3f(points[36].x, points[36].y, points[36].z);
	glVertex3f(points[37].x, points[37].y, points[37].z);

	glVertex3f(points[38].x, points[38].y, points[38].z);
	glVertex3f(points[39].x, points[39].y, points[39].z);

	glVertex3f(points[15].x, points[15].y, points[15].z);
	glVertex3f(points[32].x, points[32].y, points[32].z);

	glVertex3f(points[31].x, points[31].y, points[31].z);
	glVertex3f(points[34].x, points[34].y, points[34].z);

	glVertex3f(points[14].x, points[14].y, points[14].z);
	glVertex3f(points[33].x, points[33].y, points[33].z);

	glVertex3f(points[30].x, points[30].y, points[30].z);
	glVertex3f(points[35].x, points[35].y, points[35].z);

	glEnd();
}

void Helicopter::draw_back_rotors()
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3d(.25, 1.0, 1.0);
	glVertex3d(.25, -1.0, 1.0);
	glVertex3d(-.25, -1.0, 1.0);
	glVertex3d(-.25, 1.0, 1.0);
	glEnd();
}

void Helicopter::draw_main_rotors()
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3d(.5, 7.0, 5.5);
	glVertex3d(.5, -7.0, 5.5);
	glVertex3d(-.5, -7.0, 5.5);
	glVertex3d(-.5, 7.0, 5.5);
	glEnd();
}

void Helicopter::draw_triangle(Vec v1, Vec v2, Vec v3)
{
	glBegin(GL_POLYGON);
	glNormal3f(v1.x, v1.y, v1.z); glVertex3f(v1.x, v1.y, v1.z);
	glNormal3f(v2.x, v2.y, v2.z); glVertex3f(v2.x, v2.y, v2.z);
	glNormal3f(v3.x, v3.y, v3.z); glVertex3f(v3.x, v3.y, v3.z);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);

	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v3.x, v3.y, v3.z);

	glVertex3f(v3.x, v3.y, v3.z);
	glVertex3f(v1.x, v1.y, v1.z);

	glEnd();

}

double Helicopter::cameraX()
{
	if(!cockpit)return -25 * sin( -roty * (PI / 180) ) + posx;
	else return sin( -roty * (PI / 180) ) + posx;
}

double Helicopter::cameraY()
{
	if(!cockpit)return -25 * cos( -roty * (PI / 180) ) + posy;
	else return 15 * cos( -roty * (PI / 180) ) + posy;
}

double Helicopter::cameraZ()
{
	if(!cockpit)return posz + 25;
	else return posz;
}

double Helicopter::cameraPosX()
{
	if(!cockpit)return posx;
	else return 25 * sin( -roty * (PI / 180) ) + posx;

}
double Helicopter::cameraPosY()
{
	if(!cockpit)return posy;
	else return 25 * cos( -roty * (PI / 180) ) + posy;
}
double Helicopter::cameraPosZ()
{
	if(!cockpit)return posz;
	else return posz;
}

void Helicopter::update_angle()
{
	if(angle >= 360 || angle < 0)angle = 0;
	angle += rotspeed;
}

void Helicopter::update_position()
{
	if(hpitch < 0) roty++;
	if(hpitch > 0) roty--;

	nposx = -velocity * sin(-roty * (PI / 180) ) + posx;
	nposy = -velocity * cos(-roty * (PI / 180) ) + posy;

	if(velocity != 0)
	{
		posx = nposx;//velocity * sin(-roty * (PI / 180) );
		posy = nposy; //velocity * cos(-roty * (PI / 180) );
	}

	if(roty == 360 || roty == 0 || roty == -360)roty = 0;
	
}

void Helicopter::reset()
{
	if(pitch > 0)pitch--;
	if(pitch < 0)pitch++;
	if(hpitch > 0)hpitch--;
	if(hpitch < 0)hpitch++;

	if(velocity > 0)velocity--;
	if(velocity < 0)velocity++;

	if(rotspeed < 15 && posz > 0)posz--;
}

void Helicopter::update_pitch(int direction)
{
	if(posz >= 10)
	{
		if(pitch > 45)pitch = 45;
		if(pitch < -45)pitch = -45;

		if(hpitch >= 45)hpitch = 45;
		if(hpitch <= -45)hpitch = -45;

		//left
		if(direction == 0)hpitch -=5;
		//right
		if(direction == 2)hpitch += 5;
		//forward
		if(direction == 1){ pitch -= 5; velocity = -1; }
		//backward
		if(direction == 3){ pitch +=5; velocity = 1; }
	}
}

void Helicopter::move_up(bool direction)
{
	if(direction)
	{
		if(rotspeed >= 30 && posz <= 500)posz++;
	}

	if(!direction)
	{
		if(posz >= 3)posz--;
	}
}

void Helicopter::update_rotspeed(bool increase)
{
	if(rotspeed <= 0)rotspeed = 0;
	if(rotspeed >= 60)rotspeed = 60;

	if(increase)rotspeed += 5;
	if(!increase)rotspeed -=5;

}