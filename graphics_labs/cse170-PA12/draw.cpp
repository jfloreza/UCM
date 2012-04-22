
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"

void draw_triangle(Vec v1, Vec v2, Vec v3)
{
	glEnable(GL_COLOR_MATERIAL);
	if(App->wireframe){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glColor3f(1.0, 1.0, 1.0);

	if(App->smooth)
	{
		glBegin(GL_POLYGON);
		glNormal3f(v1.x, v1.y, v1.z); glVertex3f(v1.x, v1.y, v1.z);
		glNormal3f(v1.x, v1.y, v1.z); glVertex3f(v2.x, v2.y, v2.z);
		glNormal3f(v1.x, v1.y, v1.z); glVertex3f(v3.x, v3.y, v3.z);
		glEnd();
	}

	if(!App->smooth)
	{
		Vec norm, u, v;
		u = v1 - v2;
		v = v2 - v3;
		norm = cross(u, v);
		norm.normalize();

		glBegin(GL_POLYGON);
		glNormal3f(norm.x, norm.y, norm.z);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glEnd();
	}
}

void divide(Vec v1, Vec v2, Vec v3, int divs)
{
	Vec v12, v23, v31;

	if(divs == 0)
	{
		draw_triangle(v1, v2, v3);
		return;
	}

	v12 = v1 + v2;
	v23 = v2 + v3;
	v31 = v3 + v1;

	v12.normalize();
	v23.normalize();
	v31.normalize();

	divide(v1, v12, v31, divs - 1);
	divide(v2, v23, v12, divs - 1);
	divide(v3, v31, v23, divs - 1);
	divide(v12, v23, v31, divs - 1);
}

void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Components
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 10.0 };
	GLfloat diffuse[] = { .3, .3, .3, 1.0};
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {5.0, 5.0, 5.0, 1.0 };

	//Create lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}


void draw_axis ( double r )
 {
	 glDisable(GL_LIGHTING);
   double d=r/20.0;
   glBegin ( GL_LINES );

   glColor3f ( 1, 0, 0 );		
   glVertex3d ( -r, 0, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, -d, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, d, 0 ); glVertex3d ( r, 0, 0 );

   glColor3f ( 0, 1, 0 );		
   glVertex3d ( 0, -r, 0 ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, -d ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, d ); glVertex3d ( 0, r, 0 );

   glColor3f ( 0, 0, 1 );		
   glVertex3d ( 0, 0, -r ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, -d, r-d ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, d, r-d ); glVertex3d ( 0, 0, r );

   glEnd();
 }