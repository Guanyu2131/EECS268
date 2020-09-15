harderChecker: main.o PrecondViolatedExcep.o parenthesis.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o parenthesis.o -o harderChecker

main.o: main.cpp Node.h stack.h parenthesis.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

parenthesis.o: parenthesis.h
	g++ -std=c++11 -g -Wall -c parenthesis.cpp

clean:
	rm *.o harderChecker
