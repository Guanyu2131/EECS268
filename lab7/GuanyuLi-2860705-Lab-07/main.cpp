#include <iostream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if(argc < 3)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
		srand48((unsigned)time(NULL));
    Executive exec(argv[1],argv[2],argv[3]);
		exec.run();
  }
	return(0);
}
