/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.cpp
@Date:10/4/2018
@Brief: this file will read txt file from user and use function in flood class
@ to poor water in lower area and to tell did they finish the flood.
------------------------------------------------------------------------------*/
#include "Executive.h"
void Executive::run(string file)
{
  int rows, cols, startC, startR, capacity, record= 0;
  string temp;
  ifstream inFile;
  inFile.open(file);
  inFile >> rows >> cols;
  inFile >> startR >> startC;
  if(rows<1||cols<1)
  {
    cout<<"Invalid map.\n";
  }
  else if(startR>=rows||startC>=cols||startR<0||startC<0)
  {
    cout<<"Invalid starding position.\n";
  }
  else
  {
    inFile >> capacity;
    flood myflood(rows, cols, capacity);
    getline(inFile,temp);
    cout<<temp;
    for(int i=0;i<rows;i++)
    {
      getline(inFile,temp);
      for(int j=0;j<cols;j++)
      {
        record++;
        if(record%cols==0)
          {
            myflood.insert((record/cols)-1,cols-1,temp[j]);
          }
          else{
            myflood.insert(record/cols,(record%cols)-1,temp[j]);
          }
      }
    }
    cout<<"Size: "<<rows<<", "<<cols<<endl;
    cout<<"Starting position: "<<startR<<", "<<startC<<endl;
    myflood.flowRec(startR,startC);
    myflood.print();
    if(myflood.isComplete())
    {
      cout<<"Flood complete.\n";
    }
    else{
      cout<<"Flood ran out of water.\n";
    }
  }
}
