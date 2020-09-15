parens: main.o parenthesis.o
	g++ -std=c++11 -g -Wall main.o parenthesis.o -o parens

main.o: main.cpp parenthesis.h
	g++ -std=c++11 -g -Wall -c main.cpp

parenthesis.o: parenthesis.h
	g++ -std=c++11 -g -Wall -c parenthesis.cpp

clean:
	rm *.o parens
