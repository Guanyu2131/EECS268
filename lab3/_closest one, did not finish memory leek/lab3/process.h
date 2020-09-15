/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:process.h
@Date:9/23/2018
@Brief: this file is using stack as fundation to statisfy multiple function.
------------------------------------------------------------------------------*/
#ifndef PROCESS_H
#define PROCESS_H
#include "stack.h"
#include <iostream>
#include<string>
using namespace std;

class process
{
private:
  stack<string>* MyProcess;
  string name;
public:
  /** Cestructor allows function create new stack type
      heap memory when the process is called. */
  process(){};

  /** Cestructor allows function create new stack type
      heap memory and have a name called pname when the
      process is called. */
  process(string pname);

  /** Destructor allows concrete implementations to clean up
      heap memory when the Queue is discarded. */
  ~process(){};

  /** Sees whether this process is empty.
   @return True if the process is empty, or false if not. */
  bool isEmpty();

  /**
  * @pre give a function name to the stack
  * @post this process have this function
  **/
  void setFunction(string function);

  /**
  * @pre we can obtain the process name using this function
  * @post to present the name in this stack
  * @return show the process name in current process
  **/
  string getName();

  /**
  * @pre we can obtain the function using this function
  * @post to present the first function in this stack
  * @return show the function in current process
  **/
  string getFunction();

  /** Print out the start command request when this function
   @be called, and the data in the file do not need change*/
  void start()const;

  /** Print out the call command request when this function
   @be called*/
  void call();

  /** Print out the return command request when this function
   @be called*/
  void ret();

  void clear();
};
#endif
