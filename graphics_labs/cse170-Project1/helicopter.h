// Helicopter.h
#include "glutapp.h"
#include "vec.h"
#include <math.h>

#define PI	3.15159

class Helicopter
{
	double nposx, nposy, nposz;
	double rotspeed, angle;
	double pitch, hpitch;
	double velocity;
	bool cockpit, increase;
	Vec points[42];

	//Primitives
	void draw_body();
	void draw_back_rotors();
	void draw_main_rotors();
	void draw_triangle(Vec v1, Vec v2, Vec v3);

public:
	double roty;
	double posx, posy, posz;
	Helicopter();
	void draw_helicopter();

	//Functions to control helicopter
	void update_rotspeed(bool increase);
	void update_angle();
	void update_position();
	void update_pitch(int direction);
	void move_up(bool increase);
	void reset();

	//Functions for camera control
	double cameraX();
	double cameraY();
	double cameraZ();

	double cameraPosX();
	double cameraPosY();
	double cameraPosZ();
	
};