
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"

# define MINRADIUS	0.00001
# define PI		3.14159



void draw_wire_tube ( double len, double rt, double rb, int nfaces )
 {
   if ( rb<=0 ) rb=MINRADIUS;
   if ( rt<=0 ) rt=MINRADIUS;
   if ( nfaces<3 ) nfaces = 3;
   
   // compute vertical axis:
   double dang = (2.0*PI)/double(nfaces);
   double ang = 0;

   // we will use len as half the length:
   len = len/2;

   // initial points:
   double ibx=rb, iby=-len, ibz=0; // bottom
   double itx=rt, ity=+len, itz=0; // top

   // current points start as the initial points:
   double cbx=ibx, cby=iby, cbz=ibz; // bottom
   double ctx=itx, cty=ity, ctz=itz; // top

   // declare the "next points" to form the cylinder lines:
   double nbx, nby, nbz; // bottom
   double ntx, nty, ntz; // top

   // compute the points all around body:
   int i=1;
   glBegin ( GL_LINES );
   do { // rotate the current points:
        if ( i<nfaces ) // normal rotation for intermediate points
         { ang += dang;
           double ca = cos(ang);
           double sa = sin(ang);
           nbx=ca*rb; nby=cby; nbz=sa*rb;
           ntx=ca*rt; nty=cty; ntz=sa*rt;
         }
        else // to make a perfect closure, the last points are exactly the first ones
         { nbx=ibx; nby=iby; nbz=ibz;
           ntx=itx; nty=ity; ntz=itz;
         }

        // draw bottom boundary:
        glVertex3d ( cbx, cby, cbz ); glVertex3d ( nbx, nby, nbz );
        // draw top boundary:
        glVertex3d ( ctx, cty, ctz ); glVertex3d ( ntx, nty, ntz );
        // draw vertical line:
        glVertex3d ( cbx, cby, cbz ); glVertex3d ( ctx, cty, ctz );
        // draw top and bottom line to center (optional):
        glVertex3d ( ctx, cty, ctz ); glVertex3d ( 0, +len, 0 );
        glVertex3d ( cbx, cby, cbz ); glVertex3d ( 0, -len, 0 );

        // update current points:
        cbx=nbx; cby=nby; cbz=nbz;
        ctx=ntx; cty=nty; ctz=ntz;
        
        // increment side counter:
        i++;
      } while ( i<=nfaces );

   // done
   glEnd();
 }

void draw_solid_tube (double len, double rt, double rb, int nfaces, bool smooth)
{
	glEnable(GL_COLOR_MATERIAL);
	if(App->wireframe){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
   if ( rb<=0 ) rb=MINRADIUS;
   if ( rt<=0 ) rt=MINRADIUS;
   if ( nfaces<3 ) nfaces = 3;
   glColor3f(0.8, 1.5, 0.3);
   
   // compute vertical axis:
   double dang = (2.0*PI)/double(nfaces);
   double ang = 0;

   // we will use len as half the length:
   len = len/2;

   // initial points:
   double ibx=rb, iby=-len, ibz=0; // bottom
   double itx=rt, ity=+len, itz=0; // top

   // current points start as the initial points:
   double cbx=ibx, cby=iby, cbz=ibz; // bottom
   double ctx=itx, cty=ity, ctz=itz; // top

   // declare the "next points" to form the cylinder lines:
   double nbx, nby, nbz; // bottom
   double ntx, nty, ntz; // top

   //declare vector variables
   double utx, uty, utz, vtx, vty, vtz;
   double px, py, pz, qx, qy, qz;

   //declar normal vector variables
   double notx, noty, notz;
   double pnx, pny, pnz;

   //lengths for normals
   double tlen, plen;

   // compute the points all around body:
   int i=1;
   while(i <= nfaces)
   { // rotate the current points:
        if ( i<nfaces ) // normal rotation for intermediate points
         { ang += dang;
           double ca = cos(ang);
           double sa = sin(ang);
           nbx=ca*rb; nby=cby; nbz=sa*rb;
           ntx=ca*rt; nty=cty; ntz=sa*rt;
         }
        else // to make a perfect closure, the last points are exactly the first ones
         { nbx=ibx; nby=iby; nbz=ibz;
           ntx=itx; nty=ity; ntz=itz;
         }

		//Calculating vectors and normals for upper and lower parts
		utx = ntx - ctx;
		uty = nty - cty;
		utz = ntz - ctz;

		vtx = 0 - ctx;
		vty = len - cty;
		vtz = 0 - ctz;

		//Normal for faces
		px = nbx - cbx;
		py = nby - cby;
		pz = nbz - cbz;

		qx = ctx - cbx;
		qy = cty - cby;
		qz = ctz - cbz;

		//Cross products for normal vectors U X V
		notx = (uty * vtz) - (utz * vty);
		noty = (utz * vtx) - (utx * vtz);
		notz = (utx * vty) - (uty * vtx);
		tlen = sqrt( (notx * notx) + (noty * noty) + (notz * notz) );

		//Polygon is P X Q
		pnx = (px * qz) - (pz * qy);
		pny = (pz * qx) - (px * qz);
		pnz = (px * qy) - (py * qx);
		plen = sqrt( (pnx * pnx) + (pny * pny) + (pnz * pnz) );
		

		//Normalize, checking for division by zero
		if(tlen == 0)tlen = 1;
		notx /= tlen;
		noty /= tlen;
		notz /= tlen;

		if(plen == 0)plen = 1;
		px /= plen;
		py /= plen;
		pz /= plen; //*/


		/*/Testing for normal vector
		glBegin( GL_LINES );
		glVertex3d(0, 0, 0);
		glVertex3d(px, py, pz);
		glEnd(); //*/

		//Start drawing
		glBegin ( GL_TRIANGLES );
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

		
		if(!smooth)
		{
			//draw top polygons
			glNormal3d(-notx, -noty, -notz);
			glVertex3d(ctx, cty, ctz);
			glVertex3d(ntx, nty, ntz);
			glVertex3d(0, len, 0);

			//draw bottom polygons
			glNormal3d(notx, noty, notz);
			glVertex3d(cbx, cby, cbz);
			glVertex3d(nbx, nby, nbz);
			glVertex3d(0, -len, 0);

			//draw faces
			glNormal3d(-pnx, -pny, -pnz);

			glVertex3d(ctx, cty, ctz);
			glVertex3d(ntx, nty, ntz);
			glVertex3d(cbx, cby, cbz);

			glVertex3d(cbx, cby, cbz);
			glVertex3d(nbx, nby, nbz);
			glVertex3d(ntx, nty, ntz);
		}

		if(smooth)
		{
			//draw top polygons
			glNormal3d(ctx, cty, ctz);
			glVertex3d(ctx, cty, ctz);

			glNormal3d(ntx, nty, ntz);
			glVertex3d(ntx, nty, ntz);

			glNormal3d(0, len, 0);
			glVertex3d(0, len, 0);

			//draw bottom polygons
			glNormal3d(cbx, cby, cbz);
			glVertex3d(cbx, cby, cbz);

			glNormal3d(nbx, nby, nbz);
			glVertex3d(nbx, nby, nbz);

			glNormal3d(0, -len, 0);
			glVertex3d(0, -len, 0);

			//draw faces
			glNormal3d(ctx, cty, ctz);
			glVertex3d(ctx, cty, ctz);

			glNormal3d(ntx, nty, ntz);
			glVertex3d(ntx, nty, ntz);

			glNormal3d(cbx, cby, cbz);
			glVertex3d(cbx, cby, cbz);

			glNormal3d(cbx, cby, cbz);
			glVertex3d(cbx, cby, cbz);

			glNormal3d(nbx, nby, nbz);
			glVertex3d(nbx, nby, nbz);

			glNormal3d(ntx, nty, ntz);
			glVertex3d(ntx, nty, ntz);
		}

        // update current points:
        cbx=nbx; cby=nby; cbz=nbz;
        ctx=ntx; cty=nty; ctz=ntz;
        
        // increment side counter:
        i++;
      }

   // done
   glEnd();

   glBegin(GL_POINTS);
   glColor3d(1, 1, 1);
   glVertex3d(8.0, 8.0, 8.0);
   glEnd();

}

void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Components
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { .3, .3, .3, 1.0};
	GLfloat specular[] = { 0.8, 0.8, 0.8, 1.0};
	GLfloat position[] = {8.0, 8.0, 8.0, 1.0 };

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

