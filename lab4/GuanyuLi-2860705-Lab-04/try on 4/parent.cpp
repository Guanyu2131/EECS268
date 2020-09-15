#include "parent.h"

bool parent::isBalenced(char* sample, int count, int count2, int count3)
{
  if(count<0||count2<0||count3<0)
  {
    return(false);
  }
  if(*sample=='\0')
  {
    if(count==0&&count2==0&&count3==0)
    return(true); //check when sample is empty, if count is 0;
    else
    return(false);
  }
  if(count>count2)
  {

  }
  else{
    if(*sample=='('||*sample=='{'||*sample=='[')
    {
      if(*sample=='(')
      count++;
      else if(*sample=='{')
      count2++;
      else if(*sample=='[')
      count3++;
    }
    else if(*sample==')'||*sample=='}'||*sample==']')
    {
      if(*sample==')')
      count--;
      else if(*sample=='}')
      count2--;
      else if(*sample==']')
      count3--;
    }
  }
  return(isBalenced(++sample,count,count2,count3));
}

//can not check {[}], because it can only check the number it appear but not the sequence.
