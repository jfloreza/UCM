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
#include "grid.h"
#include "camera.h"
#include "cursor.h"

//==========================================================================
// We use a global pointer to maintain the a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;
Camera cam = Camera();
Cursor cursor = Cursor();

//==========================================================================
// appKeyboardFunc is called every time a "normal" ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   const double inc=0.25;
   switch ( key )
   { case ' ': swap_blocks(App->blockmap, App->posx, App->posy); break;
   //case 'v': App->viewaxis = !App->viewaxis; break;
   //case ',': cam.rotangle(1); break;
   //case '.': cam.rotangle(0); break;
   //case '/': generate_layer(App->blockmap); break;
   case 'v': raise_layer(App->blockmap); break;
   case 'b': App->blockmap[0][0].black(); break;
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
   switch ( key ) {  
		case GLUT_KEY_LEFT:
			if(App->posx == 0) {
				App->posx = 19;
				cam.rotangle(0);
				break;
			} else 
				App->posx--;
			cam.rotangle(0);
			break;

		case GLUT_KEY_RIGHT:
			if(App->posx == 19) {
				App->posx = 0;
				cam.rotangle(1);
				break;
			} else 
				App->posx++;
			cam.rotangle(1);
			break;

		case GLUT_KEY_UP:
			if(App->posy < 9)App->posy++; break;

		 case GLUT_KEY_DOWN: 
			 if(App->posy > 0)App->posy--; break;

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
	 if (App->start == true) {
		 enable_lights();
   // Clear the rendering buffer:
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   // Set the viewing frustum for a coordinate range in [-10,10]^3
   int w = glutGet ( GLUT_WINDOW_WIDTH );
   int h = glutGet ( GLUT_WINDOW_HEIGHT );
   double aspect = double(w)/double(h);
   glMatrixMode ( GL_PROJECTION );
   glLoadIdentity ();
   gluPerspective ( App->fovy, aspect, 2/*znear*/, 100/*zfar*/ );
   gluLookAt ( cam.getx(), cam.gety(), cam.getz(), // eye
               0, 0, 5.5,    // center
               0, 0, 1 );  // up vector

   // Clear the model transformation stack:
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   // Rotate the scene for some simple visualization:
   glRotated ( App->rotx, 1, 0, 0 );
   glRotated ( App->roty, 0, 1, 0 );

   // Draw:
   //Cursor:
   cursor.draw_cursor(App->posx, App->posy);
   cursor.draw_cursor(App->posx + 1, App->posy);

   

   //printf("Cursor Position: %d, %d\n", App->posx, App->posy);
   //Draw map:
   draw_map(App->blockmap);
   losegrid(App->loser);

   //Idle functions
   glutIdleFunc(timer);

   if ( App->viewaxis ) draw_axis ( 10.0 );

   // Show back buffer:
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}
}

void timer() {
	drop_block(App->blockmap);
	int time = glutGet(GLUT_ELAPSED_TIME);
	int val = (time / 250) % 2;
	int checktime = (time / 500) % 2;
	int raisetime = time % 10000;
	//printf("Time: %d\n", raisetime);

	if (val == 0)cursor.blink(false);
	if (val == 1)cursor.blink(true);
	if (checktime == 1)check_blocks(App->blockmap);
	if(raisetime < 3000 && raisetime > 2975)raise_layer(App->blockmap);
	loser(App->blockmap);
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
   App->posx = 0;
   App->posy = 0;
   App->start = false;

   // Init GLUT:
   glutInit ( &argc,argv );
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

   // Window position (from top corner), and size (width and height)
   glutInitWindowPosition( 20, 60 );
   glutInitWindowSize( 500, 500 );
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

   //Menu
   buildMenu();
   glutAttachMenu(GLUT_RIGHT_BUTTON);

   // Print some info
   printf ("Welcome to Tetris Redux.  Right click the window to start\n");
   //printf ("Arrow keys move cursor.  Spacebar to swap\n");
   //printf ( "Press escape button to quit.\n");
	
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}

