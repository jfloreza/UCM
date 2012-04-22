// Cursor.h cursor selection class
#ifndef _CURSOR_H_
#define _CURSOR_H_

class Cursor {
	bool flag; //check if i should be blinking
public:
	Cursor();
	void draw_cursor(int _i, int _j);
	void blink(bool val);
};

#endif