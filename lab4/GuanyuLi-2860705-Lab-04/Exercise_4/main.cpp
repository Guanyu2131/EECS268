/*------------------------------------------------------------------------------
@File Name:main.cpp
@Author:Guanyu Li
@Data:9/28/2018
@Description:takes a sequence of parenthesis from the command line.My program
@will indicate whether or not it's a balanced set of parenthesis
------------------------------------------------------------------------------*/
#include <iostream>
#include "parenthesis.h"
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    parenthesis check;
    if(check.isBalenced(argv[1]))
    {
      cout<<"The sequence "<<argv[1]<<" is balenced\n";
    }
    else
    {
      cout<<"The sequence "<<argv[1]<<" is not balenced\n";
    }
  }
  return(0);
}
