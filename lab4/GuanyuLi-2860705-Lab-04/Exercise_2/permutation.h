/*---------------------------------------------------------------------------
@File Name:permutation.h
@Author:Guanyu Li
@Data:10/1/2018
@Description:track to save the sequence, and permute is used for break down the
@ string, swap()can switch two char* position.
---------------------------------------------------------------------------*/
#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <iostream>
#include <string>
using namespace std;
class permutation
{
private:
  int track;
public:
  /** constructor allows create new int type
    heap memory when the permutation is called. */
  permutation(){track=0;};

  /** Destructor allows concrete implementations to clean up
     heap memory when the permutation is discarded. */
  ~permutation(){track=0;};

  /**
  * @pre a and b are two char from string.
  * @post will switch these two char
  * @param a: is a char type data
  * @param b; is a char type data
  **/
  void swap(char *x, char *y);

  /**
  * @pre This function will rearrange the string an print it
  * @post will read entry at * and return true or false
  * @param a: is a pointer char type value
  * @param l,r:one is the begining address and another is the last address
  **/
  void permute(char *a, int l, int r);
};
#endif
