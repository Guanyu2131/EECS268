lab7: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o lab7

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h bubbleSort.cpp insertionSort.cpp mergesort.cpp quicksort.cpp selectionSort.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab7
