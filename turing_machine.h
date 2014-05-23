#ifndef TURING_MACHINE
#define TURING_MACHINE

#include <vector>
#include "abstract_algorithm.h"
#include "tape.h"
#include "state.h"
#include "head.h"

class turing_machine : public abstract_algorithm {
	tape t;
	std::vector<state> s;
	head h;
	int cur;
	state* get_state_by_id(int id);
public:
	turing_machine(std::vector<state>& s, int size);
	~turing_machine();
	int calculate(char** program, int program_len, char* argc);
	void print_tape();
};

#endif
