#include "DMV.h"
DMV::DMV(string fileName)
{
  ifstream inFile;
  inFile.open(fileName)
  if(inFile.is_open())
  {
    inFlie>>size;

    string record;

    array = new driversLR*[size];

    for(int i=0;i<size;i++)
    {
      array[i] = new driversLR(); //you connect driversLR with your array
      inFile>>record;
      array[i]->setFirstName(record);
      inFile>>record;
      array[i]->setLastName(record);
      //...
    }
  }
}

//makefile
Driver: main.o driversLR.o DMV.o
	g++ -std=c++11 -g -Wall main.o driversLR.o DMV.o -o Driver

driversLR.o: driversLR.cpp
	g++ -std=c++11 -g -Wall -c driversLR.cpp

DMV.o: DMV.cpp
	g++ -std=c++11 -g -Wall -c DMV.cpp

main.o: main.cpp DMV.h driversLR.h
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o Driver


#ifndef A_H
#define A_H

class A
{
private:
public:
  A();
  ~A(){}; // if you do this, you cannot write A::~A() in A.cpp
};
#endif

//A.h
~A();
//A.cpp
A::~A()
{

}

OR

//A.h
~A(){};
//A.cpp
do nothing;
