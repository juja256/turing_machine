FLAGS:= -g -Wall
GXX:= g++
all: tm

tm: main.o tape.o state.o head.o turing_machine.o 
	$(GXX) $(FLAGS) -o tm main.o tape.o state.o head.o turing_machine.o 

turing_machine.o: turing_machine.cpp turing_machine.h
	$(GXX) $(FLAGS) -c turing_machine.cpp

state.o: state.cpp state.h
	$(GXX) $(FLAGS) -c state.cpp

head.o: head.cpp head.h
	$(GXX) $(FLAGS) -c head.cpp

tape.o: tape.cpp tape.h
	$(GXX) $(FLAGS) -c tape.cpp

main.o: main.cpp
	$(GXX) $(FLAGS) -c main.cpp

clean:
	rm -f *.o tm

