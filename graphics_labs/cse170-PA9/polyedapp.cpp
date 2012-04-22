/*=================================================
 * polyedapp.cpp 1.0
 * Example program illustrating OpenGL and GLUT
 * CSE170 - Introduction to Computer Graphics
 * UC Merced, M. Kallmann 
 *=================================================*/

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "draw.h"
# include "polyedapp.h"

//==========================================================================
// We use a global pointer to maintain a single instance of the 
// state of our application, see comments in glutapp.h
//==========================================================================
AppState* App;

//==========================================================================
// Here we define the extent of the coordinates of our 2D scene space
//==========================================================================
const double AppXmin = -1.0;
const double AppXmax = 1.0;
const double AppYmin = -1.0;
const double AppYmax = 1.0;

//==========================================================================
// appKeyboardFunc is called every time an ascii key is pressed
//==========================================================================
void appKeyboardFunc ( unsigned char key, int x, int y )
 {
   switch ( key )
    { case 127: // Del pressed
        if ( App->selection<App->poly.size() ) // there is a selection
         { App->poly.erase(App->poly.begin()+App->selection);
           if ( App->selection>0 && App->selection>=App->poly.size() ) App->selection--;
           glutPostRedisplay();
         } break;

	  case 27: // Esc was pressed
        if ( App->selection<App->poly.size() ) // there is a selection
         { App->selection=9999;
           glutPostRedisplay();
         } 
        else exit(1);
        break;
		
	  case '0': App->curve = 0; break;
	  case '1': App->curve = 1; break;
	  case '2': App->curve = 2; break;
	  case '3': App->curve = 3; break;
	  case '4': App->curve = 4; break;
	  case '5': App->curve = 5; break;
	  case '6': App->curve = 6; break;
	}
   //printf("%d\n",key); // to debug
}

//==========================================================================
// This appKeyboardFunc is for handling special keys. Note that this is 
// C++ and the parameter list differs from the other appKeyboardFunc
//==========================================================================
void appKeyboardFunc ( int key, int x, int y )
 {
   switch ( key )
    { case GLUT_KEY_LEFT:  printf("<-\n"); break;
      case GLUT_KEY_RIGHT: printf("->\n"); break;
	  case GLUT_KEY_UP: App->numSegments++; break;
	  case GLUT_KEY_DOWN: if(App->numSegments > 0){App->numSegments--; break;}
      default: return; // return without rendering
	}
   glutPostRedisplay();
}

//==========================================================================
// Called every time the window is resized
// Parameters w, h are the width and height of the window in pixels
//==========================================================================
void appResizeWindow ( int w, int h )
 {
   glViewport( 0, 0, w, h );	
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

   // Draw control polygon:
   unsigned i;
   std::vector<Vec>& p = App->poly;
   glPointSize ( 4 );
   glLineWidth ( 1 );
   glColor3f ( 0.5, 0.6, 1.0 );
   glBegin ( GL_LINE_STRIP );
     for ( i=0; i<p.size(); i++ ) glVertex2f ( p[i].x, p[i].y );
   glEnd();
   glColor3f ( 0.1, 0.2, 1.0 );
   glBegin ( GL_POINTS );
     for ( i=0; i<p.size(); i++ ) glVertex2f ( p[i].x, p[i].y );
   glEnd();

   // Draw selection as a circle of radius pickprec:
   i = App->selection;
   int n=12;
   float r = App->pickprec;
   float a=0, da = (2*3.1415)/n;
   if ( i<p.size() ) // there is a selection
    { glBegin ( GL_LINE_LOOP );
        while ( n-- )
         { glVertex2f ( p[i].x+r*cos(a), p[i].y+r*sin(a) );
           a+=da;
         }
      glEnd();
    }

   // Draw curve:
   glColor3f ( 1.0, 0.2, 0.1 );
   // ....
   // ....
   Vec point;
   float t;

   switch (App->curve)
   {
   case 1: //lagrange
	   glBegin(GL_LINE_STRIP);
	   glVertex2f(p.front().x, p.front().y);

	   for (int i = 0; i <= App->numSegments; i++)
	   {
		   t = float(i) / float(App->numSegments) ;
		   point = eval_lagrange (t, p);
		   glVertex2f (point.x, point.y);
	   }

	   glVertex2f(p.back().x, p.back().y);
	   glEnd();
	   glutPostRedisplay();
	   break;

   case 2: //bezier
	   glutPostRedisplay();
	   break;

   case 3: //quadritc
	   glBegin(GL_LINE_STRIP);
	   for (int i = 1; i <= App->numSegments; i++)
	   {
		   t = float(i) / float(App->numSegments);
		   if (p.size() >= 4)
		   {
			   point = eval_bspline(t, 4, p);
			   glVertex2f(point.x, point.y);
		   }
	   }
	   glEnd();
	   glutPostRedisplay();
	   break;

   case 4: //cubic
	   glBegin(GL_LINE_STRIP);
	   for (int i = 1; i < App->numSegments; i++ )
	   {
		   t = float(i) / float(App->numSegments);
		   if (p.size() >= 3)
		   {
			   point = eval_bspline(t, 3, p);
			   glVertex2f(point.x, point.y);
		   }
	   }
	   glEnd();
	   glutPostRedisplay();
	   break;

   case 5: //catmull-rom
	   glBegin(GL_LINE_STRIP);
	   for (int i = 1; i < App->numSegments; i++)
	   {
		   t = float(i) / float(App->numSegments);
		   if (p.size() >= 4)
		   {
			   point = eval_bspline(t, 3, p);
		   }
	   }
	   glEnd();
	   glutPostRedisplay();
	   break;

   case 6: // bessel overhauser
	   glBegin(GL_LINE_STRIP);
	   break;
	   
	}


   // Done drawing, just swap buffers:
   glFlush();         // flush the pipeline (usually not necessary)
   glutSwapBuffers(); // we were drawing to the back buffer, now bring it to the front
}

Vec win2scene ( int x, int y )
 {
   int w = glutGet ( GLUT_WINDOW_WIDTH );
   int h = glutGet ( GLUT_WINDOW_HEIGHT	);
   return Vec ( AppXmin + (AppXmax-AppXmin)*float(x)/float(w),
               -AppYmin - (AppYmax-AppYmin)*float(y)/float(h) );
 }

void appMouseFunc ( int button, int state, int x, int y ) // mouse clicks
 {
   Vec m = win2scene(x,y);

   // Check if a vertex is being selected, ie, if mouse click
   // is very close to a vertex:
   unsigned i;
   std::vector<Vec>& p = App->poly;
   for ( i=0; i<p.size(); i++ )
    if ( dist(p[i],m)<=App->pickprec ) break;

   if ( i<p.size() ) // vertex selected
    { App->selection = i;
      glutPostRedisplay();
      return;
    }

   // At this point no selection was detected and we will add a new vertex:
   if ( state==GLUT_DOWN ) return; // just process adding vertices on mouseup event

   if ( App->selection<App->poly.size() ) // there is a selection, add there
    { App->poly.insert ( App->poly.begin()+App->selection+1, m );
      App->selection++;
    } 
   else // add at the end
    { p.push_back ( m );
    } 

   // printf("%d %d: %f %f\n",button,state,m.x,m.y); // to debug
   glutPostRedisplay();
 }

void appMotionFunc ( int x, int y ) // mouse dragging
 {
   std::vector<Vec>& p = App->poly;
   if ( App->selection<p.size() ) // there is a selection
    { p[App->selection] = win2scene(x,y);
      glutPostRedisplay();
    }
   //printf("%f %f\n",float(x),float(y)); // to debug
 }

//==========================================================================
// Main routine
//==========================================================================
int main ( int argc, char** argv )
 {
   // First thing to do is to create a single application state instance
   // and init here each state variable of our application:
   App = new AppState;
   App->pickprec = 0.04f;
   App->selection = 9999; // value >pol.size() means no selection
   App->numSegments = 30;
   App->curve = 0;

   // Init GLUT:
   glutInit ( &argc,argv );
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

   // Window position (from top corner), and size (width and height)
   glutInitWindowPosition( 20, 60 );
   glutInitWindowSize( 360, 360 );
   glutCreateWindow( "CSE170 Polygon Edition App" );

   // Initialize OpenGL settings as we want
   glEnable ( GL_DEPTH_TEST );
   glEnable ( GL_POINT_SMOOTH );
   glEnable ( GL_LINE_SMOOTH );
   glHint ( GL_LINE_SMOOTH_HINT, GL_NICEST );
   glHint ( GL_POINT_SMOOTH_HINT, GL_NICEST );
   glClearColor ( 1, 1, 1, 1 );

   // Set up GLUT callback functions for key presses
   glutKeyboardFunc ( appKeyboardFunc );
   glutSpecialFunc ( appKeyboardFunc );

   // Set up GLUT callback function for resizing windows
   glutReshapeFunc( appResizeWindow );

   // Set up GLUT callback for drawing the scene
   glutDisplayFunc( appDrawScene );

   // Set up GLUT mouse callbacks
   glutMouseFunc ( appMouseFunc );
   glutMotionFunc ( appMotionFunc );

   // Set up idle callback for background processing if needed
   // glutIdleFunc( myIdleFunction );

   // Print some info
   printf ( "Edit, add and select vertices with the mouse.\n");
   printf ( "Delete selected vertices with the Del key.\n" );
   printf ( "Esc key clears selections, if none, it will quit.\n");
	
   // Finally start the main loop
   // Note that glutMainLoop never returns so your program is entirely event-driven
   glutMainLoop ();
}
