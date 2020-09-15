perm: main.o permutation.o
	g++ -std=c++11 -g -Wall main.o permutation.o -o perm

main.o: main.cpp permutation.h
	g++ -std=c++11 -g -Wall -c main.cpp

permutation.o: permutation.cpp
	g++ -std=c++11 -g -Wall -c permutation.cpp

clean:
	rm *.o perm
