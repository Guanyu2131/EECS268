/*------------------------------------------------------------------------------
@File Name:main.cpp
@Author:Guanyu Li
@Data:10/12/2018
@Description: this file did nothing except call function from Executive.h to run.
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "Executive.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    srand((unsigned)time(nullptr));
    Executive exec(argv[1],argv[2]);
  }
	return(0);
}
