// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

#include "gs_image.h"

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );
void draw_wire_tube ( double len, double rt, double rb, int nfaces );
void draw_solid_tube (double len, double rt, double rb, int nfaces, bool smooth, bool texture, GsImage& img);
void enable_lights ();