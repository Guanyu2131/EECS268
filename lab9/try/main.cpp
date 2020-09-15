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
    Executive exec;
		exec.run(argv[1]);
  }
  return(0);
}
