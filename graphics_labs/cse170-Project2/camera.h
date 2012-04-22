// Camera.h

class Camera
{
	int x, y, z;
	double ang;
public:
	Camera();
	void rotangle(int pos);
	int getx();
	int gety();
	int getz();
};
