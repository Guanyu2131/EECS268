/*------------------------------------------------------------------------------
@File Name:main.cpp
@Author:Guanyu Li
@Data:10/2/2018
@Description: this file did nothing except call function from Executive.h to run.
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
    Executive exec;
    exec.run(argv[1]);
  }
  return(0);
}
