/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Grammer.cpp
@Date:10/13/2018
@Brief: this file will read file from given filename and store them as
@ProductionRule type vector.
------------------------------------------------------------------------------*/
#include "Grammer.h"
Grammer::Grammer(string fileName)
{
  count = 0;
  reply = "";
  string read="";
  ifstream inFile;
  inFile.open(fileName);
  inFile >> read;
  while(!inFile.eof())
  {
    ProductionRule temp(read);
    inFile >> read;
    while(read!="#")
    {
      temp.setTerminal(read);
      inFile >> read;
    }
    myVec.push_back(temp);
    inFile >> read;
  }
}

void Grammer::recGram(int index)
{
  int a = myVec[index].getSize();
  for(int i=1; i <= a; i++)
  {
    vector<int> address;
    int b = myVec.size();
    for(int k=0; k<b; k++)
    {
      if(myVec[index].getTerminal(i)==myVec[k].getDepart())
      {
        address.push_back(k);
      }
    }
    int c = address.size();
    if(c>0)
    {
      recGram(address.at(getRandom(c)));
    }
    else
    {
      if(count==0)
      {
        reply = myVec[index].getTerminal(i);
        count++;
      }
      else if(myVec[index].getTerminal(i)=="."||myVec[index].getTerminal(i)=="?")
      {
        reply = reply + myVec[index].getTerminal(i);
        count=0;
      }
      else
      {
        reply = reply + " " + myVec[index].getTerminal(i);
        count++;
      }
    }
  }
}

int Grammer::getRandom(int range)
{
  return(rand()%range);
}

string Grammer::Reply()
{
  recGram(0);
  return(reply);
}
