#include "turing_machine.h"
#include "iostream"
#include <cstring>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <fstream>

int main() {
	std::ifstream is("program.tm");
	std::string line;
	
	
	std::getline(is, line);
	int n = atoi(line.c_str());
	char** program = new char*[n];
	for (int i=0 ;i<n; i++) {
		std::getline(is, line);
		program[i]=new char[line.size()];
		program[i]=strdup(line.c_str());
	}
	for (int i=0; i<n; i++) std::cout<<program[i]<<"\n";
	state a(0, 0, 1);
	state b(1, 0, 0);
	state c(2, 0, 0);
	state d(3, 0, 0);
	state e(4, 1, 0);
	std::vector<state> s;
	s.push_back(a); s.push_back(b); s.push_back(c); s.push_back(d); s.push_back(e);
	turing_machine TM(s, 64);
	try {
		TM.calculate(program, n, strdup("1111101111"));
		TM.print_tape();
	}
	catch(std::logic_error& e) {
		std::cout<<e.what();
	}
	return 0;
}
