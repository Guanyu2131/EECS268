#ifndef INVALID_SET_ENTRY_REQUEST_H
#define INVALID_SET_ENTRY_REQUEST_H

#include<stdexcept>
#include<string>

using namespace std;
class InvalidSetEntryRequest: public logic_error
{
public:
  InvalidSetEntryRequest(const string& message);
};
#endif
