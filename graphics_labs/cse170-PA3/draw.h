// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );
void draw_clock();
void draw_hands(double time);
void draw_tube(int hand);