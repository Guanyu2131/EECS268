lab8: main.o PrecondViolatedExcep.o Executive.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o Executive.o -o lab8

main.o: main.cpp BinaryNode.h BinaryNodeTree.h Executive.h stack.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

Executive.o: Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o lab8
