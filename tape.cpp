#include "tape.h"
#include <cstring>
#include <stdexcept>

tape::tape(int size) {
	if (size==0) size=512;
	t = new char[size];
	for (int i=0; i<size; i++)
		t[i]='#';
}

tape::~tape() {
	delete[] t;
}

int tape::print_word(char* word) {
	int word_len = strlen(word);
	int tape_len = get_size();
	if (word_len>=tape_len) throw std::logic_error("Too long word!");
	for (int i=0; i<word_len; i++) {
		t[(tape_len-word_len)/2+i] = word[i];
	}
	return (tape_len-word_len)/2;
}

char tape::get_symbol(int p) {
	return t[p];
}

void tape::print_symbol(char s, int p) {
	t[p]=s;
}

int tape::get_size() {
	return strlen(t);
}
