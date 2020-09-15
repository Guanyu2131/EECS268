lab3: main.o PrecondViolatedExcep.o Executive.o process.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o Executive.o process.o -o lab3

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

process.o: process.h process.cpp
	g++ -std=c++11 -g -Wall -c process.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab3
