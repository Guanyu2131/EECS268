/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.h
@Date:9/23/2018
@Brief: this file is use for reading command from file and run the command from
@process.h and call the Queue<stack> function to store information
------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include "process.h"
#include "Queue.h"

class Executive
{
private:
  Queue<process> myp;
public:

  /**
  * nothing is in here as you can see
  */
  Executive(){};

  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~Executive(){myp.peekFront().clear();};

  /**
  *@pre file is files name, should be as a string style
  *@post read file from File and satisfy all requirement from these command
  **/
  void run(string file);

  /**
  *@pre a is a string type data which is program name
  *@post this function will create a new process and print out explaination for start.
  **/
  void startProcess(string a);

  /**
  *@pre b is a string type data which is function name
  *@post this function can put the call function in process and store this to
  *@post the last position of Queue.
  **/
  void callFunction(string b);

  /**
  *@post this function can tell client what is in current program
  *@post if the only function is main, then we will return the whole process,
  *@post if we have other functions, it will delete that one and put this program in
  *@post the back of the queue.
  **/
  void returnFunction();
};
#endif
