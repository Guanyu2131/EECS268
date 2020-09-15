grammer: main.o Grammer.o ProductionRule.o Executive.o
	g++ -std=c++11 -g -Wall main.o Grammer.o ProductionRule.o Executive.o -o grammer

main.o: main.cpp Grammer.h Executive.h ProductionRule.h
	g++ -std=c++11 -g -Wall -c main.cpp

Grammer.o: Grammer.cpp Grammer.h
	g++ -std=c++11 -g -Wall -c Grammer.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

ProductionRule.o: ProductionRule.cpp ProductionRule.h
	g++ -std=c++11 -g -Wall -c ProductionRule.cpp

clean:
	rm *.o grammer
