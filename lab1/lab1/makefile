student: main.o coursefile.o Executive.o
	g++ -std=c++11 -g -Wall main.o coursefile.o Executive.o -o student
coursefile.o: coursefile.cpp
	g++ -std=c++11 -g -Wall -c coursefile.cpp
Executive.o: Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o student
