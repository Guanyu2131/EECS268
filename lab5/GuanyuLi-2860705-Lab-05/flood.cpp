/*------------------------------------------------------------------------------
@File Name:flood.cpp
@Author:Guanyu Li
@Data:10/4/2018
@Description:this file will define flood, bool iscomplete, insert and flowRec
@ function.which will copy the exactly the same map from txt and then fill it up.
------------------------------------------------------------------------------*/
#include "flood.h"
flood::flood(int r,int c, int cont)
{
  rows=r;
  cols=c;
  contt=cont-1;
  map = new char*[rows];
  for(int i=0;i<rows;i++)
  {
    map[i]=new char[cols];
  }
  for(int i=0; i<rows;i++)
  {
    for(int j=0; j<cols;j++)
    {
      map[i][j]=' ';
    }
  }
}

flood::~flood()
{
  for(int i=0; i<rows;i++)
  {
    delete[] map[i];
  }
  delete[] map;
}

bool flood::isComplete()
{
  if(contt==0)
  {
    for(int i=0; i<rows; i++)
    {
      for(int j=0;j<cols;j++)
      {
        if(map[i][j]=='~'&&isFull(i,j)==false)
        {
          return(false);
          break;
        }
      }
    }
    return(true);
  }
  return(true);
}

bool flood::isFull(int r, int c)
{
  if(r-1<rows && r-1>=0 && map[r-1][c]==' ') return false;
  if(r+1<rows && r+1>=0 && map[r+1][c]==' ') return false;
  if(c-1<cols && c-1>=0 && map[r][c-1]==' ') return false;
  if(c+1<cols && c+1>=0 && map[r][c+1]==' ') return false;
  return(true);
}

void flood::insert(int r, int c, char terrain)
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      if(i==r&&j==c)
      map[i][j]=terrain;
    }
  }
}

void flood::flowRec(int current_r, int current_c)
{
  insert(current_r,current_c,'~');
  while (contt>0)
  {
    if(current_r-1<rows && current_r-1>=0 && map[current_r-1][current_c]==' ')
    {
      contt--;
      flowRec(current_r-1,current_c);
    }
    else if(current_c+1<cols && current_c+1>=0 && map[current_r][current_c+1]==' ')
    {
      contt--;
      flowRec(current_r,current_c+1);
    }
    else if(current_r+1<rows && current_r+1>=0 && map[current_r+1][current_c]==' ')
    {
      contt--;
      flowRec(current_r+1,current_c);
    }
    else if(current_c-1<cols && current_c-1>=0 && map[current_r][current_c-1]==' ')
    {
      contt--;
      flowRec(current_r,current_c-1);
    }
    else return;
  }
}

void flood::print() const
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<<map[i][j];
    }
    cout<<endl;
  }
}
