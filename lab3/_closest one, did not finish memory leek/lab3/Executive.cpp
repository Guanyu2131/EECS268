/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.cpp
@Date:9/23/2018
@Brief: this file is use for reading command from file and run the command from
@process.h and call the Queue<stack> function to store information
------------------------------------------------------------------------------*/
#include "Executive.h"
void Executive::run(string file)
{
  string Fname = "";
  string Pname = "";
  string command = "ABC";
  ifstream inFile;
  inFile.open(file);
  while(command != "")
  {
    inFile >> command;
    if(inFile.eof())break;
    else{
      if(command == "START")
      {
        inFile >> Pname;
        startProcess(Pname);
      }
      else if(command == "CALL")
      {
        inFile >> Fname;
        callFunction(Fname);
      }
      else if(command == "RETURN")returnFunction();
    }
  }
  // while(myp.isEmpty()!=true)myp.peekFront().clear();
}

void Executive::startProcess(string a)
{
  process app(a);
  app.start();
  myp.enqueue(app);
  // myp.peekFront().start();
}

void Executive::callFunction(string b)
{
  myp.peekFront().setFunction(b);
  myp.peekFront().call();
  myp.enqueue(myp.peekFront());
  myp.dequeue();
}

void Executive::returnFunction()
{
  myp.peekFront().ret();
  myp.enqueue(myp.peekFront());
  myp.dequeue();
}
