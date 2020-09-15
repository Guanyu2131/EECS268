/*---------------------------------------------------------------------------
@File Name:permutation.cpp
@Author:Guanyu Li
@Data:10/1/2018
@Description:track to save the sequence, and permute is used for break down the
@ string, swap()can switch two char* position.
---------------------------------------------------------------------------*/
#include "permutation.h"
void permutation::swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutation::permute(char *a, int l, int r)
{
  if (l == r)
  {
    track++;
    if(track%2!=0)
    {
      cout<<a[0]<<endl;
      for(int i = 0; i < r; i++)
      {
        cout<<a[i];
      }
      cout<<endl;
      printf("%s\n", a);
    }
    else{
      for(int i = 0; i < r; i++)
      {
        cout<<a[i];
      }
      cout<<endl;
      printf("%s\n", a);
    }
  }

  else
  {
     for (int i = l; i <= r; i++)
     {
       if(*a=='\0') break;
        swap((a+l), (a+i));
        permute(a,l+1, r);
        swap((a+l), (a+i)); //backtrack
     }
   }
}
