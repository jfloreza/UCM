// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once
# include "model.h"
# include "vec.h"

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );
void enable_lights ();
void draw_model ( const Model& m, bool smooth);
void rotate( const Model& hand, const Model& uarm, const Model& larm);



