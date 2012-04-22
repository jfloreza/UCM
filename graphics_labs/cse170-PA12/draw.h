// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

#include "vec.h"

void draw_triangle(Vec v1, Vec v2, Vec v3);
void divide(Vec v1, Vec v2, Vec v3, int divs);
void enable_lights();

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );
