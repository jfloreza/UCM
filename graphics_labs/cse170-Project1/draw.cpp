
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"

void draw_axis ( double r )
 {
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

   glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	//Body points
	glVertex3f(2.0, 8.0, 0.0);
	glVertex3f(2.0, 9.0, 1.0);
	glVertex3f(2.0, 7.0, 3.0);
	glVertex3f(2.0, 4.0, 4.0);
	glVertex3f(2.0, 0.0, 3.5);
	glVertex3f(1.0, -3.0, 3.0);
	glVertex3f(1.0, -7.0, 3.0);

	glVertex3f(1.0, -8.0, 5.0);
	glVertex3f(0.5, -10.0, 5.0);
	glVertex3f(0.25, -9.5, 2.0);
	glVertex3f(0.5, -10.0, 0.0);
	glVertex3f(1.0, -8.0, 0.0);
	glVertex3f(1.0, -7.0, 1.0);
	glVertex3f(1.0, -3.0, 1.0);
	glVertex3f(2.0, 0.0, 0.5);

	glVertex3f(-1.5, 8.0, 0.0);
	glVertex3f(-2.5, 9.0, 1.0);
	glVertex3f(-2.0, 7.0, 3.0);
	glVertex3f(-2.0, 4.0, 4.0);
	glVertex3f(-2.0, 0.0, 3.5);
	glVertex3f(-1.0, -3.0, 3.0);
	glVertex3f(-1.0, -7.0, 3.0);

	glVertex3f(-1.0, -8.0, 5.0);
	glVertex3f(-0.5, -10.0, 5.0);
	glVertex3f(-0.25, -9.5, 2.0);
	glVertex3f(-0.5, -10.0, 0.0);
	glVertex3f(-1.0, -8.0, 0.0);
	glVertex3f(-1.0, -7.0, 1.0);
	glVertex3f(-1.0, -3.0, 1.0);
	glVertex3f(-2.0, 0.0, 0.5);

	glVertex3f(2.0, 4.0, -1.0);
	glVertex3f(2.0, 0.0, -1.0);
	
	glEnd();
 }

void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Components
	GLfloat ambient[] = { 0.5, 0.5, 0.5, 10.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {100.0, 100.0, 100.0, 1.0 };

	//Create lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}