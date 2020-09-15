/*------------------------------------------------------------------------------
@File Name:parenthesis.h
@Author:Guanyu Li
@Data:9/28/2018
@Description:recursion function is isBalenced(char* sample), char*
@sample is a pointer can move from left to right to count if it is balence.
------------------------------------------------------------------------------*/
#ifndef PARENTHESIS_H
#define PARENTHESIS_H
#include "stack.h"

class parenthesis
{
private:
  stack<char>* mystack;
public:

  /** constructor allows create new stack type
      heap memory when the parenthesis is called. */
  parenthesis();

  /** Destructor allows concrete implementations to clean up
      heap memory when the parenthesis is discarded. */
  ~parenthesis();

  /**
  * @pre a and b are bracket simble, and one is form stack, the other is from check
  * @post will compare these two to tell if they are a pair
  * @param a: is a char type data
  * @param b; is a char type data
  **/
  bool isPair(char a, char b);

  /**
  * @pre The check is a pointer
  * @post will read entry at * and return true or false
  * @param sample: is a pointer type value
  * @param Entry: A count to save how many time the (())read
  **/
  bool isBalenced(char* check);
};
#endif
