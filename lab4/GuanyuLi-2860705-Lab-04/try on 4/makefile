harderChecker: main.o parent.o
	g++ -std=c++11 -g -Wall main.o parent.o -o harderChecker

main.o: main.cpp parent.h
	g++ -std=c++11 -g -Wall -c main.cpp

parent.o: parent.h
	g++ -std=c++11 -g -Wall -c parent.cpp

clean:
	rm *.o harderChecker
