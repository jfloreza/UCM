
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"

# define PI (3.141592653589793)

void draw_wire_tube ( double len, double rt, double rb, int nfaces )
{
	double deg = 0;
	if(nfaces < 1)nfaces = 1;
	double ndeg = 360 / nfaces;
	double xt, zt, xb, zb, xa, za, xa2, za2;


	while(deg < 360)
	{
		xt = rt * cos(deg * 0.017453);
		zt = rt * sin(deg * 0.017453);
		xb = rb * cos(deg * 0.017453);
		zb = rb * sin(deg * 0.017453);
		xa = rt * cos((deg + ndeg) * 0.017453);
		za = rt * sin((deg + ndeg) * 0.017453);
		xa2 = rb * cos((deg + ndeg) * 0.017453);
		za2 = rb * sin((deg + ndeg) * 0.017453);

	//Top part
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3d(0, len/2, 0);
    glVertex3d(xt, len/2, zt);

	//Bottom Part
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(0, -len/2, 0);
	glVertex3d(xb, -len/2, zb);

	//Connect top to bottom
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(xt, len/2, zt);
	glVertex3d(xb, -len/2, zb);

	//Connect edge to edge
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(xt, len/2, zt);
	glVertex3d(xa, len/2, za);

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(xb, -len/2, zb);
	glVertex3d(xa2, -len/2, za2);


    glEnd();
	deg = deg + ndeg;
	}
}
//green is y
//red is x
//blue is z

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

