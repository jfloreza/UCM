
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"

void rotate( const Model& hand, const Model& uarm, const Model& larm)
{
	//upperarm
	glPushMatrix();
	glTranslatef(0.0, 0.0, -25.0);
	glRotatef(App->rotshoulder, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	draw_model (uarm, App->smooth);

	//lowerarm
	glPushMatrix();
	glTranslatef(0.0, 0.0, 25.0);
	glRotatef(App->rotelbow, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	draw_model (larm, App->smooth);

	//Hand
	glPushMatrix();
	glTranslatef(0.0, 0.0, 25.0);
	glRotatef(App->rotwrist, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	draw_model (hand, App->smooth);
	glPopMatrix();

}

void draw_model ( const Model& m, bool smooth)
{
	glEnable(GL_NORMALIZE);
	if(App->wireframe){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
	else
		glPolygonMode(GL_FRONT, GL_FILL);

	glBegin(GL_TRIANGLES);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	if(smooth)
	{
		for(int i = 0; i < m.fsize; i++)
		{
			glColor3d(m.F[i].r/255.0, m.F[i].g/255.0, m.F[i].b/255.0);

			glNormal3d(m.N[m.F[i].na].x, m.N[m.F[i].na].y, m.N[m.F[i].na].z);
			glVertex3d(m.V[m.F[i].va].x, m.V[m.F[i].va].y, m.V[m.F[i].va].z);

			glNormal3d(m.N[m.F[i].nb].x, m.N[m.F[i].nb].y, m.N[m.F[i].nb].z);
			glVertex3d(m.V[m.F[i].vb].x, m.V[m.F[i].vb].y, m.V[m.F[i].vb].z);

			glNormal3d(m.N[m.F[i].nc].x, m.N[m.F[i].nc].y, m.N[m.F[i].nc].z);
			glVertex3d(m.V[m.F[i].vc].x, m.V[m.F[i].vc].y, m.V[m.F[i].vc].z);
		}
		glEnd();
	}

	if(!smooth)
	{
		for(int i = 0; i < m.fsize; i++)
		{
			glColor3d(m.F[i].r/255.0, m.F[i].g/255.0, m.F[i].b/255.0);

			Vec u = m.V[m.F[i].vb] - m.V[m.F[i].va];
			Vec v = m.V[m.F[i].vb] - m.V[m.F[i].vc];

			Vec w = cross(v, u);
			w.normalize();
			glNormal3d(w.x, w.y, w.z);

			glVertex3d(m.V[m.F[i].va].x, m.V[m.F[i].va].y, m.V[m.F[i].va].z);
			glVertex3d(m.V[m.F[i].vb].x, m.V[m.F[i].vb].y, m.V[m.F[i].vb].z);
			glVertex3d(m.V[m.F[i].vc].x, m.V[m.F[i].vc].y, m.V[m.F[i].vc].z);

		}
		glEnd();

	}
}

void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	//Components
	GLfloat ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat diffuse[] = { .3, .3, .3, 1.0};
	GLfloat specular[] = { 0.8, 0.8, 0.8, 1.0};
	GLfloat position[] = {50.0, 50.0, 0.0, 1.0 };

	//Create lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void draw_axis ( double r )
 {
   double d=r/20.0;
   glBegin ( GL_LINES );

   glColor3f ( .5, .5, .5 );		
   glVertex3d ( -r, 0, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, -d, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, d, 0 ); glVertex3d ( r, 0, 0 );

   glColor3f ( 0.5, .5, .5 );		
   glVertex3d ( 0, -r, 0 ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, -d ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, d ); glVertex3d ( 0, r, 0 );

   glColor3f ( 0.5, 0.5, .5 );		
   glVertex3d ( 0, 0, -r ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, -d, r-d ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, d, r-d ); glVertex3d ( 0, 0, r );

   glEnd();
 }

