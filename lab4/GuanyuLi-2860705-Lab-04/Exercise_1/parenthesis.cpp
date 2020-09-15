/*------------------------------------------------------------------------------
@File Name:parenthesis.cpp
@Author:Guanyu Li
@Data:9/27/2018
@Description:recursion function is isBalenced(char* sample, int count), char*
@sample is a pointer can move from left to right to count if it is balence.
------------------------------------------------------------------------------*/
#include "parenthesis.h"
bool parenthesis::isBalenced(char* sample, int count)
{
  if(count<0)
  {
    return(false);
  }
  if(*sample=='\0')
  {
    return(count == 0); //check when sample is empty, if count is 0;
  }
  else{
    if(*sample=='(')
    {
      count++;
    }
    else if(*sample==')')
    {
      count--;
    }
  }
  return(isBalenced(++sample,count));
}
