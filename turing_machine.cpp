#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "turing_machine.h"

turing_machine::turing_machine(std::vector<state>& s_, int size_=0)
:t(tape(size_)), s(s_), h(0) {
	for (int i=0; i<s_.size(); i++) {
		if (s_[i].is_primary()) cur = s_[i].get_id();
		break;
	}
}

turing_machine::~turing_machine() {}

int turing_machine::calculate(char** program, int program_len, char* argc) {

	int f = t.print_word(argc);
	h.set_pos(f);
	
	// magic begins here
	int i=0;
	while (1) {
		char* c = new char[16];
		std::vector<char*> lexems;
		std::stringstream ss(std::string(program[i]));
		while (ss>>c) 
			lexems.push_back(strdup(c));
		//for (int b=0 ;b<5;b++ ) std::cout << lexems[b];
		if (lexems.size() != 5) {  throw std::logic_error("Syntax error 1!"); }
		//std::cout<<cur<<atoi(lexems[0]);
		if (cur == atoi(lexems[0])) { // begin
			char cur_symbol = h.read(&t);
			
			if (cur_symbol == lexems[1][0]) {
				
				cur = atoi(lexems[2]);
				h.write(lexems[3][0], &t);
				switch(lexems[4][0]) {
					 case 'L':
						h.move_left();
						break;
					 case 'R':
					 	h.move_right(&t);
					 	break;
					 case 'S':
					 	break;
					 default: 
					 	throw std::logic_error("Syntax error 2!");
					 	break;	
				}
				
			}
		} // end
		if (get_state_by_id(cur)->is_finite()) { 
			

			return 1; 	
		}
		
		++i;
		if (i==program_len) i=0; // back to the start of program
		
	}
}

void turing_machine::print_tape() {
	h.set_pos(0);
	for (int i=0; i<t.get_size(); i++) { 
		std::cout<<h.read(&t);
		h.move_right(&t); 
	}
}

state* turing_machine::get_state_by_id(int id) {
	for (int i=0; i<s.size(); i++)
		if (s[i].get_id()==id) return &s[i];
}