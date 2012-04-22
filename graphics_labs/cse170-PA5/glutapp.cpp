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
#include "model.h"

//==========================================================================
// We use a global pointer to maintain the a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;
Model rhand = Model();
Model rlowerarm = Model();
Model rupperarm = Model();

//==========================================================================
// appKeyboardFunc is called every time a "normal" ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   const double inc=0.25;
   switch ( key )
    { case ' ': App->viewaxis = !App->viewaxis; break;
	  case 122 : App->wireframe = true; break; //z
	  case 120 : App->smooth = false; App->wireframe = false; break;//x
	  case 99 : App->smooth = true; App->wireframe = false; break;//c
	  case 113 : App->rotshoulder += 5.0; break; //q
	  case 97 : App->rotshoulder -= 5.0; break; //a
	  case 119 : App->rotelbow += 5.0; break; //w
	  case 115 : App->rotelbow -= 5.0; break;//s
	  case 101 : App->rotwrist += 5.0;break; //e
	  case 100 : App->rotwrist -= 5.0;break;//d
	  case 27 : exit(1); // Esc was pressed
	   
      default: return; // return without rendering
	}

   glutPostRedisplay();
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
    { case GLUT_KEY_LEFT:      App->roty-=incr; break;
      case GLUT_KEY_RIGHT:     App->roty+=incr; break;
      case GLUT_KEY_UP:        App->rotx+=incr; break;
      case GLUT_KEY_DOWN:      App->rotx-=incr; break;
      case GLUT_KEY_PAGE_UP:   App->fovy-=incf; break;
      case GLUT_KEY_PAGE_DOWN: App->fovy+=incf; break;
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
   gluPerspective ( App->fovy, aspect, 20/*znear*/, 150/*zfar*/ );
   gluLookAt ( 0, 0, -100, // eye
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
   enable_lights();
   rotate(rhand, rupperarm, rlowerarm);
   //rotelbow(rlowerarm);
   //rotshoulder(rupperarm);
   //draw_model(rhand, App->smooth);
   //draw_model(rlowerarm, App->smooth);
   //draw_model(rupperarm, App->smooth);

   // Show back buffer:
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
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
   App->roty = -90;
   App->viewaxis = true;
   App->smooth = true;
   App->wireframe = false;
   App->rotwrist = 0.0;
   App->rotelbow = 0.0;
   App->rotshoulder = 0.0;
   rhand.load("rhand.m");
   rlowerarm.load("rlowerarm.m");
   rupperarm.load("rupperarm.m");

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
	
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}

