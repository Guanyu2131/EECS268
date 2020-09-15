#include <iostream>
#include <string>
#include "Executive.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 3)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
    Executive exec(argv[1],argv[2]);
  }
  return(0);
}
