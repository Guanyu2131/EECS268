#include "InvalidSetEntryRequest.h"
InvalidSetEntryRequest::InvalidSetEntryRequest(const string& message): logic_error("Invalid Set Entry Request: " + message)
{
}
