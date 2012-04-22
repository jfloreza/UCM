
# include <math.h>
# include <stdio.h>
#include <cstdlib>

# include "glutapp.h"
# include "draw.h"

void zero_map(Block blockmap[][10]) {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			blockmap[i][j] = Block();
		}
	}
}

void init_map(Block blockmap[][10]) {
	int i, j, random_int;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 5; j++) {
			random_int = rand() % 7 + 1;
			blockmap[i][j].set(random_int); //set each block in the map to 0
			//blockmap[i][j].set(random_int);
		}
		for (j = 5; j < 10; j++) {
			blockmap[i][j].set(0);
		}
	}
}

void draw_map(Block blockmap[][10]) {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			blockmap[i][j].draw_block(i, j);
		}
	}
}

void generate_layer(Block blockmap[][10]) {
	int i, random_int;
	for (i = 0; i < 20; i++) {
		random_int = rand() % 7 ;
		blockmap[i][0].set(random_int);
	}
}

void raise_layer(Block blockmap[][10]) {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 9; j > 0; j-- ) {
			blockmap[i][j].set(blockmap[i][j-1].check_type());
		}
	}
	generate_layer(blockmap);
}

void swap_blocks(Block blockmap[][10], int i, int j) {
	int temp;
	temp = blockmap[i][j].check_type();
	if (i == 19) {
		blockmap[i][j].set(blockmap[0][j].check_type());
		blockmap[0][j].set(temp);
	} else {
		blockmap[i][j].set(blockmap[i+1][j].check_type());;
		blockmap[i+1][j].set(temp);
	}
}

void check_blocks(Block blockmap[][10]) {
	int i, j;
	int up, down, left, right, curr;
	int up2, down2, left2, right2;
	for (i = 0; i < 20; i++) {
		for(j = 0; j < 10; j++) {
			//Get current block
			curr = blockmap[i][j].check_type(); 

			//Get surrounding blocks
			up = blockmap[i][j+1].check_type();
			down = blockmap[i][j-1].check_type();

			//Get set of blocks 2 spaces away
			up2 = blockmap[i][j+2].check_type();
			down2 = blockmap[i][j-2].check_type();

			//Handle edge cases
			//Left Edge
			if(i == 0) {
				//Get surrounding blocks
				right = blockmap[1][j].check_type();
				left = blockmap[19][j].check_type();

				//Get set of blocks 2 spaces away
				right2 = blockmap[2][j].check_type();
				left2 = blockmap[18][j].check_type();

				if(left == curr && right == curr) {
					//Clear 5 horizontally
					if (left2 == curr && right2 == curr) {
						blockmap[18][j].clear_block();
						blockmap[19][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[i+1][j].clear_block();
						blockmap[i+2][j].clear_block();
					} 
					//Clear 4, going left
					else if (left2 == curr) {
						blockmap[18][j].clear_block();
						blockmap[19][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[i+1][j].clear_block();
					}

					//Clear 4, going upward
					else if (right == curr) {
						blockmap[19][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[i+1][j].clear_block();
						blockmap[i+2][j].clear_block();
					}
					else 
					//Clear 3
						blockmap[19][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[i+1][j].clear_block();
				}
			}

			//Right edge
			else if(i == 19) {
				//Get surrounding blocks
				right = blockmap[0][j].check_type();
				left = blockmap[18][j].check_type();

				//Get set of blocks 2 spaces away
				right2 = blockmap[1][j].check_type();
				left2 = blockmap[17][j].check_type();

				if(left == curr && right == curr) {
					//Clear 5 horizontally
					if (left2 == curr && right2 == curr) {
						blockmap[i-2][j].clear_block();
						blockmap[i-1][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[0][j].clear_block();
						blockmap[1][j].clear_block();
					} 
					//Clear 4, going left
					else if (left2 == curr) {
						blockmap[i-2][j].clear_block();
						blockmap[i-1][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[0][j].clear_block();
					}

					//Clear 4, going upward
					else if (right == curr) {
						blockmap[i-1][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[0][j].clear_block();
						blockmap[1][j].clear_block();
					}
					else 
					//Clear 3
						blockmap[i-1][j].clear_block();
						blockmap[i][j].clear_block();
						blockmap[0][j].clear_block();
				}
			}
			else
				right = blockmap[i+1][j].check_type();
				left = blockmap[i-1][j].check_type();
				
				right2 = blockmap[i+2][j].check_type();
				left2 = blockmap[i-2][j].check_type();

			//Decide which blocks to clear out
			//Vertical is easy
			if(up == curr && down == curr) {

				//Clear 5 vertically
				if (up2 == curr && down2 == curr) {
					blockmap[i][j+2].clear_block();
					blockmap[i][j+1].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i][j-1].clear_block();
					blockmap[i][j-2].clear_block();
				} 
				//Clear 4, going downward
				else if (down2 == curr) {
					blockmap[i][j+1].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i][j-1].clear_block();
					blockmap[i][j-2].clear_block();
				}

				//Clear 4, going upward
				else if (up2 == curr) {
					blockmap[i][j+2].clear_block();
					blockmap[i][j+1].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i][j-1].clear_block();
				}
				else 
				//Clear 3
					blockmap[i][j+1].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i][j-1].clear_block();
			}

			//General Horizontal
			if(left == curr && right == curr) {

				//Clear 5 horizontally
				if (left2== curr && right2 == curr) {
					blockmap[i+2][j].clear_block();
					blockmap[i+1][j].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i-1][j].clear_block();
					blockmap[i-2][j].clear_block();
				} 
				//Clear 4, going left
				else if (left2 == curr) {
					blockmap[i+1][j].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i-1][j].clear_block();
					blockmap[i-2][j].clear_block();
				}

				//Clear 4, going right
				else if (right2 == curr) {
					blockmap[i+2][j].clear_block();
					blockmap[i+1][j].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i-1][j].clear_block();
				}
				else 
				//Clear 3
					blockmap[i+1][j].clear_block();
					blockmap[i][j].clear_block();
					blockmap[i-1][j].clear_block();
			}
		}
	}
}

void drop_block(Block blockmap[][10]) {
	int i, j;
	int type;
	for (i = 0; i < 20; i++) {
		for (j = 1; j < 10; j++) {
			type = blockmap[i][j-1].check_type();
			if (type == 0) {
				blockmap[i][j-1].set(blockmap[i][j].check_type());
				blockmap[i][j].clear_block();
			}
		}
	}
}


void draw_axis ( double r )
 {
   double d=r/20.0;
   glBegin ( GL_LINES );

   glColor3f ( 1, 0, 0 );		
   glVertex3d ( -r, 0, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, -d, 0 ); glVertex3d ( r, 0, 0 );
   glVertex3d ( r-d, d, 0 ); glVertex3d ( r, 0, 0 );

   glColor3f ( 0, 1, 0 );		
   glVertex3d ( 0, -r, 0 ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, -d ); glVertex3d ( 0, r, 0 );
   glVertex3d ( 0, r-d, d ); glVertex3d ( 0, r, 0 );

   glColor3f ( 0, 0, 1 );		
   glVertex3d ( 0, 0, -r ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, -d, r-d ); glVertex3d ( 0, 0, r );
   glVertex3d ( 0, d, r-d ); glVertex3d ( 0, 0, r );

   glEnd();
 }

void loser(Block blockmap[][10]) {
	if (App->start == true) {
		int i = 0;
		while (i < 20) {
			if (blockmap[i][9].check_type() != 0) {
				printf("Game over!\n");
				App->start = false;
				break;
			}

			i++;
		}
	}
}

int buildMenu() {
	int menu;
	menu = glutCreateMenu(select);
	glutAddMenuEntry("Start game", 0);
	glutAddMenuEntry("Instructions", 1);

	return menu;
}

void select(int val) {
	switch(val) {
		case 0: 
			losegrid(App->loser);
			App->start = true;
			zero_map(App->blockmap);

			init_map(App->blockmap);

			

			system("cls");
			printf("Starting new game...\n");
			printf("Good Luck!\n");
			break;
		case 1:
			printf("Use the arrow keys to move.  Spacebar to swap blocks\n");
			printf("Use the v key to manually raise the stack.\n");
			printf("Line up 3 or more to make the dissapear.\n");
			printf("If your stack reaches the top, you lose\n");

	}
	glutPostRedisplay();
}

void losegrid(Block loser[20]) {
	for (int i = 0; i < 20; i++) {
		loser[i].set(9);
		loser[i].draw_block(i, 9);
	}
}

void enable_lights()
{
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Components
	GLfloat ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat diffuse[] = { .3, .3, .3, 1.0};
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat position[] = {10.0, 10.0, 10.0, 1.0 };

	//Create lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}