#include <iostream>
#include <string>
#include <fstream>
#include "coursefile.h"
#include "Executive.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    std::string fileName=argv[1];
     Executive exec(fileName); //sample creation of executive object
     exec.run(); //presumably handles the calling of all other member methods
  }

  return(0);
}
