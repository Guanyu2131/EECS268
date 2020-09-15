/*------------------------------------------------------------------------------
@File Name:fibonacci.cpp
@Author:Guanyu Li
@Data:9/27/2018
@Description:recursion function for getFibonacci sequence and to tell if it
@is in the sequence
------------------------------------------------------------------------------*/
#include "fibonacci.h"
int fibonacci::getFibonacci(int i) throw(std::runtime_error)
{
  if(i >= 0)
  {
    if(i == 0)
    {
      return(0);
    }
    else if(i == 1)
    {
      return(1);
    }
    else
    {
      return(getFibonacci(i-1) + getFibonacci(i-2));
    }
  }
  else{
    throw(std::runtime_error("It's negative number, what are you thinking about?"));
  }
}

bool fibonacci::isFibonacci(int i, int test)throw(std::runtime_error)
{
  if(test<0)
  {
    throw(std::runtime_error("It's negative number, what are you thinking about?"));
  }
  else
  {
    int fib = getFibonacci(i);
    if(fib == test)
    {
      return(true);
    }
    else if(fib < test)
    {
      isFibonacci(i+1,test);
    }
    else if(fib > test)
    return(false);
  }
}
