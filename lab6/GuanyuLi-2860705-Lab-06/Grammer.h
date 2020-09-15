/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Grammer.h
@Date:10/13/2018
@Brief: this file will read file from given filename and store them as
@ProductionRule type vector.
------------------------------------------------------------------------------*/
#ifndef GRAMMER_H
#define GRAMMER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ProductionRule.h"

using namespace std;
class Grammer
{
private:
  int count;
  string reply;
  vector<ProductionRule> myVec;
public:
  /** Cestructor allows function create new Grammer type
      @heap memrory. It will read file and store them in a vector<ProductionRule>.*/
  Grammer(string fileName);

  /** Destructor allows concrete implementations to clean up
      heap memory when the Grammer is discarded. */
  ~Grammer(){clear();}

  /** clear allows concrete implementations to clean up
      string reply and int count when the function been called. */
  void clear(){reply="";};

  /**
  * @pre get to position myVec[index] and translate it
  * @post this function will call itself until the count==10 or
  * @transplate will the information that can be decode
  * @param index: index can not be larger than vector<ProductionRule>.size and >=0;
  **/
  void recGram(int index);

  /**
  * @pre get a randome number from range size number.
  * @post will use randome function to get a randome number, the range is (0-range-1).
  * @param range: range can be any integer larger than 0.
  **/
  int getRandom(int range);

  /**
  *@return the string reply to the process.
  **/
  string Reply();
};
#endif
