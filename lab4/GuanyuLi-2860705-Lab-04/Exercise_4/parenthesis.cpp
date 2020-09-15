/*------------------------------------------------------------------------------
@File Name:parenthesis.cpp
@Author:Guanyu Li
@Data:9/28/2018
@Description:recursion function is isBalenced(char* sample), char*
@sample is a pointer can move from left to right to count if it is balence.
------------------------------------------------------------------------------*/
#include "parenthesis.h"
using namespace std;
parenthesis::parenthesis()
{
  mystack = new stack<char>;
}

parenthesis::~parenthesis()
{
  delete mystack;
}


bool parenthesis::isPair(char a, char b)
{
  if(a=='{' && b=='}') return(true);
  else if(a=='[' && b==']') return(true);
  else if(a=='(' && b==')') return(true);
  else return(false);
}

bool parenthesis::isBalenced(char* check)
{

  if(*check=='\0')
  {
    return(mystack->isEmpty());
  }

  else if(*check=='('||*check=='{'||*check=='[')
  {
    mystack->push(*check);
    return(isBalenced(++check));
  }

  else if(*check==')'||*check=='}'||*check==']')
  {
    if(!mystack->isEmpty())
    {
      if(isPair(mystack->peek(),*check))
      {
        mystack->pop();
        return(isBalenced(++check));
      }
      else return(false);
    }
    else return(false);
  }

  return(isBalenced(++check));
}
