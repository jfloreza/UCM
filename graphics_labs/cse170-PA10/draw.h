// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

void initPoints(Point points[][4]);
void drawPoints(Point points[][4]);
void selectPoint(Point points[][4], int x, int y);
void movePoint(Point points[][4], int selX, int selY, int x, int y, int z);
void drawLines(Point points[][4]);
void draw_bezier(Point points[][4], Point bpoints[][4]);
Vec eval_bezier(float u, float v, Point points[][4]);
int factorial ( int number );
void drawPatch(Point points[][4]);
void print(Point points[][4]);
void enable_lights();

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );



