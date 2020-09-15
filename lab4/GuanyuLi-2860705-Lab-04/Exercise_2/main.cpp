/* @File Name:main.cpp
@Author:Guanyu Li
@Data:10/1/2018
@Description:takes a string from the command line and prints every permutation
@of that string
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "permutation.h"
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    permutation p;
    string a = argv[1];
    p.permute(argv[1],0,a.length()-1);
  }
    return(0);
}
