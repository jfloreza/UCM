/*=================================================
 * glutapp3d 1.0
 * Example program illustrating OpenGL and GLUT
 * CSE170 - Introduction to Computer Graphics
 * UC Merced, M. Kallmann 
 *=================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "glutapp.h"
#include "draw.h"
#include "time.h"

//==========================================================================
// We use a global pointer to maintain the a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;
double time_start, current_time;
double hold_time = 0;
double time = 0;

//==========================================================================
// appKeyboardFunc is called every time a "normal" ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   const double inc=0.25;
   switch ( key )
    { case ' ': App->run = !App->run;
				if(App->run)
				{
					time_start = get_time();
					glutIdleFunc(timer);
					break;
				} else
					hold_time = time;
					printf("Elapsed Time:%lf\n", hold_time);
					break;
	  case 13: App->reset = !App->reset;
		  if (App->reset)
		  {
			  printf("Timer Cleared.\n");
			  time = 0;
			  hold_time = 0;
			  glutIdleFunc(timer);
		  }
		  break;
	  case 27 : exit(1); // Esc was pressed
	   
      default: return; // return without rendering
	}
	 
   //glutPostRedisplay();
}

//==========================================================================
// This appKeyboardFunc is for handling special keys. Note that this is 
// C++ and the parameter list differs from the other appKeyboardFunc
//==========================================================================
void appKeyboardFunc ( int key, int x, int y )
 {
   const double incr=5;
   const double incf=0.5;
   switch ( key )
    { /*case GLUT_KEY_LEFT:      App->roty-=incr; break;
      case GLUT_KEY_RIGHT:     App->roty+=incr; break;
      case GLUT_KEY_UP:        App->rotx+=incr; break;
      case GLUT_KEY_DOWN:      App->rotx-=incr; break;
      case GLUT_KEY_PAGE_UP:   App->fovy-=incf; break;
      case GLUT_KEY_PAGE_DOWN: App->fovy+=incf; break;
      default: return; // return without rendering*/
	}

   // at this point the mark position changed and so we render the scene again:
   //glutPostRedisplay();
}

//==========================================================================
// Called every time the window is resized
// Parameters w, h are the width and height of the window in pixels
//==========================================================================
void appResizeWindow ( int w, int h )
 {
   // Define that OpenGL should use the whole window for rendering
   glViewport( 0, 0, w, h );	
}

//==========================================================================
// appDrawScene() will redraw the scene accodring to the current state of
// the application. For more complex scenes, display lists should be used.
//==========================================================================
void appDrawScene ()
 {
   // Clear the rendering buffer:
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Set the viewing frustum for a coordinate range in [-10,10]^3
   int w = glutGet ( GLUT_WINDOW_WIDTH );
   int h = glutGet ( GLUT_WINDOW_HEIGHT );
   double aspect = double(w)/double(h);
   glMatrixMode ( GL_PROJECTION );
   glLoadIdentity ();
   gluPerspective ( App->fovy, aspect, 2/*znear*/, 50/*zfar*/ );
   gluLookAt ( 0, 0, -20, // eye
               0, 0, 0,    // center
               0, 1, 0 );  // up vector

   // Clear the model transformation stack:
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   // Rotate the scene for some simple visualization:
   glRotated ( App->rotx, 1, 0, 0 );
   glRotated ( App->roty, 0, 1, 0 );

   // Draw:
   if ( App->viewaxis ) draw_axis ( 10.0 );
   draw_clock();
   draw_hands(time);

	   

   // Show back buffer:
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

void timer()
{
	if(App->reset)
	{
		App->reset = false;
		time = 0; 
		glutPostRedisplay(); 
		return;
	}
	current_time = get_time();
	time = hold_time + (current_time - time_start);
	if(!App->run)return;

	glutPostRedisplay();
}
//==========================================================================
// Main routine
//==========================================================================
int main ( int argc, char** argv )
 {
   // First thing to do is to create a single application state instance
   // and init here each state variable of our application:
   App = new AppState;
   App->fovy = 60;
   App->rotx = 0;
   App->roty = 0;
   App->viewaxis = false;
   App->run = false;
   App->second_hand = 0;
   App->minute_hand = 0;
   App->reset = false;

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
   glLineWidth ( 1 );

   // Set up GLUT callback functions for key presses
   glutKeyboardFunc ( appKeyboardFunc );
   glutSpecialFunc ( appKeyboardFunc );

   // Set up GLUT callback function for resizing windows
   glutReshapeFunc( appResizeWindow );

   // Set up GLUT callback for drawing the scene
   glutDisplayFunc( appDrawScene );

   // Print some info
   printf ( "Press escape button to quit.\n");
   printf ( "Press spacebar to start and stop.\n");
   printf ( "Press enter to reset.\n");
	
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}

