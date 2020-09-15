a: main.o NotFoundException.o InvalidSetEntryRequest.o Task.o Executive.o
	g++ -std=c++11 -g -Wall main.o NotFoundException.o InvalidSetEntryRequest.o Task.o Executive.o -o a

NotFoundException.o: NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

InvalidSetEntryRequest.o: InvalidSetEntryRequest.cpp
	g++ -std=c++11 -g -Wall -c InvalidSetEntryRequest.cpp

Task.o: Task.cpp
	g++ -std=c++11 -g -Wall -c Task.cpp

Executive.o: Executive.cpp BinaryNode.h BinarySearchTree.h Task.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o a
