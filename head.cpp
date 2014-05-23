#include "head.h"
#include <stdexcept>

head::head(int p):pos(p) {}

char head::read(tape* t) {
	return t->get_symbol(pos);
}

void head::write(char c, tape* t) {
	t->print_symbol(c, pos);
}

void head::move_left() {
	if (pos!=0) 
		pos--;
	else throw std::logic_error("Reached end of the tape!");
}

void head::move_right(tape* t) {
	if (pos!=t->get_size()) 
		pos++;
	else throw std::logic_error("Reached end of the tape!");
}

void head::set_pos(int p) {
	pos=p;
}