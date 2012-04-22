// Ensure the header file is included only once in multi-file projects
// Pragma once is a non-standard but widely supported preprocessor directive
# pragma once

// draw 3D axis centered at origin and with each axis with given length
void draw_axis ( double r );

void init_map(Block blockmap[][10]);
void draw_map(Block blockmap[][10]);
void generate_layer(Block blockmap[][10]);
void raise_layer(Block blockmap[][10]);
void swap_blocks(Block blockamp[][10], int i, int j);
void check_blocks(Block blockmap[][10]);
void drop_block(Block blockmap[][10]);
void zero_map(Block blockmap[][10]);
void loser(Block blockmap[][10]);
int buildMenu();
void select(int val);
void losegrid(Block loser[20]);
void enable_lights();