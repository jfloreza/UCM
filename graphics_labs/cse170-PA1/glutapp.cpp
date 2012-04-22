/*=================================================
 * glutapp2d 1.0
 * Example program illustrating OpenGL and GLUT
 * CSE170 - Introduction to Computer Graphics
 * UC Merced, M. Kallmann 
 *=================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glutapp.h"

//==========================================================================
// We use a global pointer to maintain the a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;
double interval = .001;

//==========================================================================
// appKeyboardFunc is called every time a "normal" ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   switch ( key )
    { case ' ': // space bar
	   printf ( "Space pressed.\n" );
       App->markx = 1.5;
       App->marky = 1.5;
	   interval = .001;
       glutPostRedisplay();
	   break;

	  case 27: // Esc was pressed
	   exit(1);
	}
}

//==========================================================================
// This appKeyboardFunc is for handling special keys. Note that this is 
// C++ and the parameter list differs from the other appKeyboardFunc
//==========================================================================
void appKeyboardFunc ( int key, int x, int y )
 {
   const double incx=0.001;
   const double incy=0.1;
   switch ( key )
    { case GLUT_KEY_LEFT:  interval-=incx; break;
      case GLUT_KEY_RIGHT: interval+=incx; break;
      case GLUT_KEY_UP:    App->marky+=incy; break;
      case GLUT_KEY_DOWN:  App->marky-=incy; break;
      default: return; // return without rendering
	}

   // at this point the mark position changed and so we render the scene again:
   glutPostRedisplay();
}

//==========================================================================
// Called every time the window is resized
// Parameters w, h are the width and height of the window in pixels
//==========================================================================
void appResizeWindow ( int w, int h )
 {
   double scale, center;
   double winXmin, winXmax, winYmin, winYmax;

   const double appXmin = 0.0;
   const double appXmax = 3.0;
   const double appYmin = 0.0;
   const double appYmax = 3.0;

   // Define that OpenGL should use the whole window for rendering
   glViewport( 0, 0, w, h );	

   // Set up the projection matrix using a orthographic projection that will
   // maintain the aspect ratio of the scene no matter the aspect ratio of
   // the window, and also set the min/max coordinates to be the disered ones
   w = (w==0) ? 1 : w;
   h = (h==0) ? 1 : h;
   if ( (appXmax-appXmin)/w < (appYmax-appYmin)/h )
    {
      scale = ((appYmax-appYmin)/h)/((appXmax-appXmin)/w);
	  center = (appXmax+appXmin)/2;
	  winXmin = center - (center-appXmin)*scale;
	  winXmax = center + (appXmax-center)*scale;
	  winYmin = appYmin;
	  winYmax = appYmax;
	}
   else
    {
      scale = ((appXmax-appXmin)/w)/((appYmax-appYmin)/h);
	  center = (appYmax+appYmin)/2;
	  winYmin = center - (center-appYmin)*scale;
	  winYmax = center + (appYmax-center)*scale;
	  winXmin = appXmin;
	  winXmax = appXmax;
    }
	
   // Now we use glOrtho to set up our viewing frustum
   glMatrixMode ( GL_PROJECTION );
   glLoadIdentity ();
   glOrtho ( winXmin, winXmax, winYmin, winYmax, -1, 1 );
}


//==========================================================================
// appDrawScene() will redraw the scene accodring to the current state of
// the application. For more complex scenes, display lists should be used.
//==========================================================================
void appDrawScene ()
 {
   // Clear the rendering window
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Clear the trasnformation stack
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   // Set drawing color to red
   glColor3f ( 1.0, 0.3, 0.3 );		

   /*/ Draw a cross
   double s=0.1;
   glBegin ( GL_LINES );
   glVertex2d ( App->markx-s, App->marky );
   glVertex2d ( App->markx+s, App->marky );
   glVertex2d ( App->markx, App->marky-s );
   glVertex2d ( App->markx, App->marky+s );
   glEnd();*/

   //Draw a house
   glBegin( GL_TRIANGLES );
   glColor3f ( 1.0, 0.0, 0.0 ); // red
   glVertex3f ( 0.75, 1.0, 0.5 );
   glVertex3f ( 0.0, 0.5, 0.0 );
   glVertex3f ( 1.5, 0.5, 0.0 );
   glEnd();

   glBegin( GL_POLYGON );
   glColor3f ( 0.0, 1.0, 1.0);
   glVertex3f ( 0.35, 0.5, 0.5 );
   glVertex3f ( 1.15, 0.5, 0.0);
   glVertex3f ( 1.15, 0.0, 0.0);
   glVertex3f ( 0.35, 0.0, 0.0);
   glEnd();

   glBegin( GL_POLYGON );
   glColor3f(0.5, 0.5, 0.5);
   glVertex3f (0.40, 0.25, 0.5);
   glVertex3f (0.60, 0.25, 0.5);
   glVertex3f (0.60, 0.0, 0.5);
   glVertex3f (0.40, 0.0, 0.5);
   glEnd();

   //Draw a Boat
   //Appstate x = 1.5, y = 1.5
   glBegin (GL_POLYGON);
   glColor3f( 0.5, 0.15, 0.0);
   glVertex3f(App->markx + 1, App->marky + .5, 0.5);
   glVertex3f(App->markx, App->marky +.5, 0.0);
   glVertex3f(App->markx + .3, App->marky, 0.0);
   glVertex3f(App->markx + .7, App->marky, 0.0);
   glEnd();

   glBegin(GL_POINTS);
   glColor3f(0.0, 0.0, 1.0);
   glVertex3f(App->markx + .5, App->marky + 1, .5);
   glEnd();

   glBegin(GL_LINES);
   glColor3f(1.0, .6, .3);
   glVertex3f(App->markx + .5, App->marky + 1, .5);
   glVertex3f(App->markx + .5, App->marky, 0.0);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3f(1.0, 1.0, 1.0);
   glVertex3f(App->markx + .5, App->marky + 1, .5);
   glVertex3f(App->markx, App->marky + .75, 0.0);
   glVertex3f(App->markx + .5, App->marky + .75, 0.0);
   glEnd();

   //Draw Ice Cream Sandwich
   glBegin(GL_POLYGON);
   glColor3f(1.0, 1.0, 1.0);
   glVertex3f(2.25, 1.25, 0.0);
   glVertex3f(2.75, 1.25, 0.0);
   glVertex3f(2.75, 1.05, 0.0);
   glVertex3f(2.25, 1.05, 0.0);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3f(0.8, 0.15, 0.0);
   glVertex3f(2.25, 1.30, 0.0);
   glVertex3f(2.75, 1.30, 0.0);
   glVertex3f(2.75, 1.25, 0.0);
   glVertex3f(2.25, 1.25, 0.0);
   glEnd();

   glBegin(GL_POLYGON);
   glColor3f(0.8, 0.15, 0.0);
   glVertex3f(2.25, 1.05, 0.0);
   glVertex3f(2.75, 1.05, 0.0);
   glVertex3f(2.75, 1.0, 0.0);
   glVertex3f(2.25, 1.0, 0.0);
   glEnd();

   /*/ Draw some white points
   glColor3f ( 1.0, 1.0, 1.0 );		
   glBegin ( GL_POINTS );
   glVertex3f ( 1.0, 1.0, 1.0 );
   glVertex3f ( 1.0, 2.0, 1.0 );
   glVertex3f ( 2.0, 2.0, 1.0 );
   glVertex3f ( 2.0, 1.0, 1.0 );
   glEnd();

   // Draw three overlapping triangles
   glBegin( GL_TRIANGLES );
   glColor3f ( 1.0, 0.0, 0.0 ); // red
   glVertex3f ( 0.3, 1.0, 0.5 );
   glVertex3f ( 2.7, 0.85, 0.0 );
   glVertex3f ( 2.7, 1.15, 0.0 );

   glColor3f ( 0.0, 1.0, 0.0 ); // green
   glVertex3f ( 2.53, 0.71, 0.5 );
   glVertex3f ( 1.46, 2.86, 0.0 );
   glVertex3f ( 1.2, 2.71, 0.0 );

   glColor3f ( 0.0, 0.0, 1.0 ); // blue
   glVertex3f ( 1.667, 2.79, 0.5 );
   glVertex3f ( 0.337, 0.786, 0.0 );
   glVertex3f ( 0.597, 0.636, 0.0 );
   glEnd();*/

   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

//==========================================================================
// myidlefunction
//==========================================================================

void myIdleFunction()
{

	App->markx += interval;
	if (App->markx > 3.0) App->markx = 0;
	if (App->markx < 0) App->markx = 3;
	if (App->marky > 3.0) App->marky = 0;
	if (App->marky < 0) App->marky = 3;
	appDrawScene();
}

//==========================================================================
// Main routine
//==========================================================================
int main ( int argc, char** argv )
 {
   // First thing to do is to create a single application state instance
   // and init here each state variable of our application:
   App = new AppState;
   App->markx = 0;
   App->marky = 1.5;

   // Init GLUT:
   glutInit ( &argc,argv );
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

   // Window position (from top corner), and size (width and height)
   glutInitWindowPosition( 20, 60 );
   glutInitWindowSize( 360, 360 );
   glutCreateWindow( "CSE170 glutapp" );

   // Initialize OpenGL settings as we want
   glEnable ( GL_DEPTH_TEST );
   glEnable ( GL_POINT_SMOOTH );
   glEnable ( GL_LINE_SMOOTH );
   glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
   glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
   glPointSize ( 6 );
   glLineWidth ( 2 );

   // Set up GLUT callback functions for key presses
   glutKeyboardFunc ( appKeyboardFunc );
   glutSpecialFunc ( appKeyboardFunc );

   // Set up GLUT callback function for resizing windows
   glutReshapeFunc( appResizeWindow );

   // Set up GLUT callback for drawing the scene
   glutDisplayFunc( appDrawScene );

   // Set up idle callback for background processing if needed
   glutIdleFunc( myIdleFunction );

   // Print some info
   printf ( "Control Speed <left> <right>\n" );
   printf ( "Up or down <up> <down>\n");
   printf ( "Spacebar to reset\n");
   printf ( "Press escape button to quit.\n");
	
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}
