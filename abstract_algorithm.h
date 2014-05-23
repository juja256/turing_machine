#ifndef ABSTRACT_ALGORITHM
#define ABSTRACT_ALGORITHM

class abstract_algorithm {
public:
	virtual int calculate(char** program, int program_len, char* argc)=0;
};

#endif
