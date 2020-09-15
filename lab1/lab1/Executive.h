#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "coursefile.h"
#include <stdio.h>
using namespace std;

class Executive
{
private:
  coursefile** arr;
  int arrSize;
public:
  Executive(string file);
  void menu();
  void run();
  void backup();
};
#endif
