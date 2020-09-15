/*------------------------------------------------------------------------------
@File Name:fibonacci.h
@Author:Guanyu Li
@Data:9/27/2018
@Description:recursion function for getFibonacci sequence and to tell if it
@is in the sequence
------------------------------------------------------------------------------*/
#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <stdexcept>

class fibonacci
{
private:
public:
  /**
  * @pre The i is ith entry i want to get.
  * @post will return the value in ith term
  * @return ith entry to the user.
  * @throw when user give me negative number, i will throw error
  **/
  int getFibonacci(int i)throw(std::runtime_error);

  /**
  * @pre The i is the count of which round i am in, test is the number
  * @user give me to find from sequence
  * @post will tell if test number is in sequence
  * @return when find test, return true, otherwise return false
  * @throw when user give me negative number, i will throw error
  **/
  bool isFibonacci(int i, int test)throw(std::runtime_error);
};
#endif
