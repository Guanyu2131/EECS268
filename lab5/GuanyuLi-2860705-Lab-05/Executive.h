/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.h
@Date:10/4/2018
@Brief: this file will read txt file from user and use function in flood class
@ to poor water in lower area and to tell did they finish the flood.
------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <fstream>
#include <iostream>
#include <string>
#include "flood.h"

class Executive
{
private:
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
  * @pre file is files name, should be as a string style
  * @post read file from File and satisfy all kinds of function
  **/
  void run(string file);
};
#endif
