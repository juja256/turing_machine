#include "turing_machine.h"
#include "iostream"
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <fstream>

int main() {
	std::ifstream is;
	is.open("program.tm",std::ifstream::in);
	std::string line;
	if (!is)
		std::cout<<0;
	std::cout<<line;
	std::getline(is, line);
	int n = atoi(line.c_str());
	char** program = new char*[n];
	for (int i=0 ;i<n; i++) {
		std::getline(is, line);
		program[i]=new char[line.size()];
		program[i]=strdup(line.c_str());
	}
	for (int i=0; i<n; i++) std::cout<<program[i]<<"\n";
	state states[] = {state(0,0,1), state(1,0,0), state(2,0,0), state(3,0,0), state(4,1,0)};
	
	std::vector<state> s(states, states + sizeof(states)/sizeof(state));
	turing_machine TM(s, 64);
	std::string word;
	std::cin >> word;
	try {
		TM.calculate(program, n, strdup(word.c_str()));
		TM.print_tape();
	}
	catch(std::logic_error& e) {
		std::cout<<e.what();
	}
	return 0;
}
