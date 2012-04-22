//Blocks.h  Each block is created using this class
# ifndef _BLOCK_H_
# define _BLOCK_H_

class Block {
	int type; //Type of block
	bool falling; //Check if the block is moving

public:
	Block();
	Block(int _type);
	int check_type();
	void set(int _type);
	void draw_block(int _i, int _j);
	void clear_block();
	void select(int _i, int _j);
	void black();
};

#endif