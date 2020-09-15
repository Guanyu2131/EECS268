/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:ProductionRule.h
@Date:10/13/2018
@Brief: this file is using vector as fundation to statisfy multiple functions, such
@ as get name of the vector, and get entry of the vector or get size of the vector.
------------------------------------------------------------------------------*/
#ifndef PRODUCTIONRULE_H
#define PRODUCTIONRULE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ProductionRule
{
private:
  string department;
  vector<string> myProduct;
public:
  /** Cestructor allows function create new vector type
      heap memory and have a name called department when the
      process is called. */
  ProductionRule(string name);

  /** Destructor allows concrete implementations to clean up
      heap memory when the Queue is discarded. */
  ~ProductionRule(){};

  /** Sees whether this process is empty.
      @return True if the process is empty, or false if not. */
  bool isEmpty();

  /**
  * @pre give a terminal word to the vector
  * @post the productionrule will store this terminal word at the end of vector
  **/
  void setTerminal(string Terminal);

  /** This function will check if the vector is empty.
      @return int size in current process.
      @no need to change anything, it is constant. */
  int getSize()const;

  /**
  * @pre we can obtain the department using this function
  * @post to present the department of this vector
  * @return show the department in current process
  **/
  string getDepart()const;

  /**
  * @pre we can obtain the terminal using this function
  * @post to present the terminal in certain position to function
  * @return the terminal word in current position of vector
  * @param position position is an integer, must larger than 0 and smaller than size+1.
  * @throw runtime_error if position is invalid
  **/
  string getTerminal(int position)throw(runtime_error);
};
#endif
