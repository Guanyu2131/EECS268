Lab05: main.o flood.o Executive.o
	g++ -std=c++11 -g -Wall main.o flood.o Executive.o -o Lab05

main.o: main.cpp flood.h Executive.o
	g++ -std=c++11 -g -Wall -c main.cpp

flood.o: flood.cpp flood.h
	g++ -std=c++11 -g -Wall -c flood.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
clean:
	rm *.o Lab05
