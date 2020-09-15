fib: main.o fibonacci.o
	g++ -std=c++11 -g -Wall main.o fibonacci.o -o fib

main.o: main.cpp fibonacci.h
	g++ -std=c++11 -g -Wall -c main.cpp

fibonacci.o: fibonacci.cpp
	g++ -std=c++11 -g -Wall -c fibonacci.cpp

clean:
	rm *.o fib
