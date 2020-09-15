/*------------------------------------------------------------------------------
@File Name:main.cpp
@Author:Guanyu Li
@Data:9/14/2018
@Description: this file did nothing except call function from Executive.h to run.
@such as insert, remove, replace.
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    string fileName=argv[1];
    Executive exec;
    exec.run(fileName);
  }
  return(0);
}
