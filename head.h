#ifndef HEAD_H
#define HEAD_H

#include "tape.h"

class head {
	int pos;
public:
	head(int p);
	char read(tape* t);
	void write(char c, tape* t);
	void move_left();
	void move_right(tape* t);
	void set_pos(int p);
};

#endif
