/*=================================================
 * polyedapp.h 1.0
 * CSE170 - Introduction to Computer Graphics
 * UC Merced, M. Kallmann 
 *=================================================*/

// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

// Include GLUT (OpenGL Graphics Utility Library) header files.
// In Windows we include our own included GLUT header file, but
// in Linux, the GLUT header file should be already installed.
#ifdef WIN32
#include <glut/glut.h>
#else
#include <GL/glut.h>
#endif

// we are using STL vector class to hold our control polygon
# include <vector>
# include "vec.h"

// The application state is stored in the AppState structure defined
// below. A single instance of this structure is initialized in
// glutapp.cpp and is accessible by pointer App. This will allow
// your application data to be visible by all source files including
// this header file and this will be very usefull when your project
// grows and becomes multi-file project.
struct AppState
 { std::vector<Vec> poly;
   float pickprec;
   unsigned selection;
   int numSegments, curve;
 };
extern AppState* App; // Pointer to the single instance


