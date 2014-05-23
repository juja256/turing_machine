#ifndef TAPE_H
#define TAPE_H

class tape {
	char* t;
public:
	tape(int size);
	~tape();
	int print_word(char* word);
	char get_symbol(int p);
	void print_symbol(char s, int p);
	int get_size();
};

#endif
