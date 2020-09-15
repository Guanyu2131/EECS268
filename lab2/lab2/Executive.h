/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.h
@Date:9/14/2018
@Brief: this file is complete object orientation, it can read file and run the
@command from browser.h
------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include"browser.h"
#include <string>
#include <iostream>
#include <fstream>

class Executive
{
private:
  browser mybrows;
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
  ~Executive(){};

  /**
  *@pre file is files name, should be as a string style
  *@post read file from File and satisfy all kinds of function
  **/
  void run(string file);


};
#include "Executive.cpp"
#endif
