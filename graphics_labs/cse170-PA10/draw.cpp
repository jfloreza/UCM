
# include <math.h>
# include <stdio.h>

# include "glutapp.h"
# include "draw.h"
# include "point.h"

# define nCr(n, r) (float(factorial(n)) / float(factorial(r) * (factorial(n-r)))

void initPoints(Point points[][4])
{
	//Init the points
	float x = -6.0, y = -6.0, z = 0.0;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			points[i][j].set(x, y, z);
			y += 4.0;
		}
		y = -6;
		x += 4.0;
	}
}

void print(Point points[][4])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("Point[%i][%i]: %f, %f, %f\n", i, j, points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
		}
	}
}

void drawPoints(Point points[][4])
{
	//Draw each point
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			points[i][j].draw();
		}
	}
	glColor3f(1.0, 1.0, 1.0);
	drawLines(points);
}

void drawPatch(Point points[][4])
{
	glEnable(GL_COLOR_MATERIAL);
	if(App->wireframe){glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	int i, j;
	
	if(App->smooth)
	{
		for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				glBegin(GL_POLYGON);
				glNormal3f(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
				glVertex3f(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());

				glNormal3f(points[i][j+1].getX(), points[i][j+1].getY(), points[i][j+1].getZ());
				glVertex3f(points[i][j+1].getX(), points[i][j+1].getY(), points[i][j+1].getZ());

				glNormal3f(points[i+1][j+1].getX(), points[i+1][j+1].getY(), points[i+1][j+1].getZ());
				glVertex3f(points[i+1][j+1].getX(), points[i+1][j+1].getY(), points[i+1][j+1].getZ());

				glNormal3f(points[i+1][j].getX(), points[i+1][j].getY(), points[i+1][j].getZ());
				glVertex3f(points[i+1][j].getX(), points[i+1][j].getY(), points[i+1][j].getZ());

				glEnd();
			}
		}
	}

	if(!App->smooth)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				Vec l, m, o, u, v, w;
				l.set(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
				m.set(points[i][j+1].getX(), points[i][j+1].getY(), points[i][j+1].getZ());
				o.set(points[i+1][j].getX(), points[i+1][j].getY(), points[i+1][j].getZ());

				u = l - m;
				v = l - o;
				w = cross(u, v);

				glBegin(GL_POLYGON);
				glNormal3f(-w.x, -w.y, -w.z);
				glVertex3f(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
				glVertex3f(points[i][j+1].getX(), points[i][j+1].getY(), points[i][j+1].getZ());
				glVertex3f(points[i+1][j+1].getX(), points[i+1][j+1].getY(), points[i+1][j+1].getZ());
				glVertex3f(points[i+1][j].getX(), points[i+1][j].getY(), points[i+1][j].getZ());

				glEnd();
			}
		}
	}

}

void drawLines(Point points[][4])
{
	glDisable(GL_LIGHTING);
	int i, j;

	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex3f(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
		}
		glEnd();
	}

	for(j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			glBegin(GL_LINE_STRIP);
			glVertex3f(points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
		}
		glEnd();
	}
	glEnable(GL_LIGHTING);
}

void selectPoint(Point points[][4], int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if(i == x && j == y)
			{
				points[i][j].select();
			} else
				points[i][j].deselect();
		}
	}
	glColor3f(1.0, 1.0, 1.0);
}

void movePoint(Point points[][4], int selX, int selY, int x, int y, int z)
{
	points[selX][selY].move(x, y, z);
}

void draw_bezier(Point points[][4], Point bpoints[][4])
{
	float u, v;
	int i, j;
	Vec evalpt;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
		u = float(i) / 3;
		v = float(j) / 3;
		evalpt = eval_bezier(u, v, points);
		bpoints[i][j].set(evalpt.x, evalpt.y, evalpt.z);
		//printf("Evalpt: %f, %f, %f\n", evalpt.x, evalpt.y, evalpt.z);
		//printf("point: %f, %f, %f\n", points[i][j].getX(), points[i][j].getY(), points[i][j].getZ());
		//printf("bpoint: %f, %f, %f\n", bpoints[i][j].getX(), bpoints[i][j].getY(), bpoints[i][j].getZ());

		glVertex3f(evalpt.x, evalpt.y, evalpt.z);
		}
	}
	glEnd();
	
	drawPatch(bpoints);
}

Vec eval_bezier(float u, float v, Point points[][4])
{
	Vec B;
	int n = 3, m = 3;

	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++) 
		{
			B.x += nCr( n, i ) * pow(( 1 - u ), float( n - i )) * pow( u, float(i) ) * 
				   nCr( n, j ) * pow(( 1 - v ), float( m - j )) * pow( v, float(j) ) * 
				   points[i][j].getX() ) );

			B.y += nCr( n, i ) * pow(( 1 - u ), float( n - i )) * pow( u, float(i) ) * 
				   nCr( n, j ) * pow(( 1 - v ), float( m - j )) * pow( v, float(j) ) * 
				   points[i][j].getY() ) );

			B.z += nCr( n, i ) * pow(( 1 - u ), float( n - i )) * pow( u, float(i) ) * 
				   nCr( n, j ) * pow(( 1 - v ), float( m - j )) * pow( v, float(j) ) * 
				   points[i][j].getZ() ) );
		}
	}

	//printf("Bezier returns: %f, %f, %f\n", B.x, B.y, B.z);

	return B;
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

int factorial ( int number ) {
	int temp;

	if ( number <= 1 )
		return 1;

	temp = number * factorial ( number - 1 );
	return temp;
}
void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Components
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 10.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {0.0, 0.0, 10.0, 1.0 };

	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	//Create lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}