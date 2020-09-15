#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H

#include<stdexcept>
#include<string>

using namespace std;
class NotFoundException: public logic_error
{
public:
  NotFoundException(const string& message);
};
#endif
