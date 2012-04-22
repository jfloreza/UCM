
# include <math.h>
# include <stdio.h>
# include <math.h>
# include "glutapp.h"
# include "draw.h"
# include "time.h"

# define degToRad	0.017453


void draw_tube(int hand)
{
	int len = 0;
	if(hand == 1){len = 8; glColor3f(1, 0, 0);} //longer hand
	if(hand == 0){len = 5; glColor3f(0, 1, 0);}//shorter hand
	double deg = 0;
	double ndeg = 45;

	double ibx = cos(deg * degToRad);
	double ibz = sin(deg * degToRad);
	double cbx, cbz; //next points

	while (deg < 390)
	{
		cbx = cos(deg * degToRad);
		cbz = sin(deg * degToRad);

		glBegin(GL_LINES);
		glVertex3d(ibx, len-1, ibz);
		glVertex3d(cbx, len-1, cbz);

		glBegin(GL_LINES);
		glVertex3d(0, len, 0);
		glVertex3d(cbx, len-1, cbz);

		glBegin(GL_LINES);
		glVertex3d(ibx, 0, ibz);
		glVertex3d(cbx, 0, cbz);

		glBegin(GL_LINES);
		glVertex3d(ibx, len-1, ibz);
		glVertex3d(ibx, 0, ibz);

		ibx = cbx;
		ibz = cbz;

		glEnd();
		deg += ndeg;
	}

}

void draw_clock ()
{
	double deg = 0;
	double ndeg = 30;

	double ix = 10 * cos(deg * degToRad);
	double iy = 10 * sin(deg * degToRad);
	double cx, cy;

	while (deg < 390)
	{
		cx = 10 * cos(deg * degToRad);
		cy = 10 * sin(deg * degToRad);

		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3d(ix, iy, 0);
		glVertex3d(cx, cy, 0);

		ix = cx;
		iy = cy;

		glEnd();
		deg += ndeg;
	}
}

void draw_hands(double time)
{
	glPushMatrix();
	glTranslatef (0.0, 0.0, 0.0);
	glRotatef (time * 6, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.0);
	glPushMatrix();
	draw_tube(0);
	glPopMatrix();

	glTranslatef (0.0, 0.0, 0.0);
	glRotatef (time * 360, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.0);
	glPushMatrix();
	draw_tube(1);
	glPopMatrix();


}


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
 }

