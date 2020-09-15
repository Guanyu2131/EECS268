/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.h
@Date:10/12/2018
@Brief: this file will get file name from user and read the file through functions in Grammer
------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Grammer.h"

class Executive
{
private:
public:
  /**
  * pass file name to function in grammer and automatically generate a while loop to ask question and answer it.
  */
  Executive(string filename_1,string filename_2);

  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~Executive(){};
};
#endif
