/*------------------------------------------------------------------------------
@File Name:main.cpp
@Author:Guanyu Li
@Data:9/26/2018
@Description: a program that takes an integer and a flag from the user.
@The flag will indicate one of two options: -i is ith fibonacci, -v is verify
@ if it's in fibonacci sequence.
------------------------------------------------------------------------------*/
#include <iostream>
#include <stdexcept>
#include "fibonacci.h"
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    string baba=argv[1];
    fibonacci haha;
    if(baba == "-i")
    {
      cout<<haha.getFibonacci(atoi(argv[2]))<<endl;
    }
    else if (baba == "-v")
    {
      if(haha.isFibonacci(0, atoi(argv[2]))==false)
      {
        cout<<argv[2]<<" is not in the sequence\n";
      }
      else{
        cout<<argv[2]<<" is in the sequence\n";
      }
    }
    else{
      cout<<"Your command is invalid\n";
    }
  }
  return(0);
}
