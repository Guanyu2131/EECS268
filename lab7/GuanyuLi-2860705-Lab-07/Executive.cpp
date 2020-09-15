#include "Executive.h"
Executive::Executive(string si, string seq, string sor)
{
  size = stoi(si);
  sequence = seq;
  sort = sor;
  array = new double[size];
}

Executive::~Executive()
{
  delete[] array;
  size = 0;
  sequence = "";
  sort = "";
}

void Executive::run()
{
  clock_t t;
  getArray();
  if(sort=="bubble")
  {
    t = clock();
    bubbleSort(array,size);
    t = clock()-t;
  }
  else if(sort=="insertion")
  {
    t = clock();
    insertionSort(array,size);
    t = clock()-t;
  }
  else if(sort=="merge")
  {
    t = clock();
    mergeSort(array,size);
    t = clock()-t;
  }
  else if(sort=="quick")
  {
    t = clock();
    quickSort(array,0,size-1);
    t = clock()-t;
  }
  else if(sort=="selection")
  {
    t = clock();
    selectionSort(array,size);
    t = clock()-t;
  }
  cout<<size<<" "<<sequence<<" "<<sort<<" "<<((float)t)/CLOCKS_PER_SEC<<endl;
}

void Executive::getArray()
{
  if(sequence=="random")
    randomeArray();
  else if(sequence=="ascending")
    ascendArray();
  else if(sequence=="descending")
    descendArray();
}

void Executive::randomeArray()
{
  for(int i=0;i<size;i++)
  {
    double temp = drand48()*100000;
    array[i]=temp;
  }
}

void Executive::ascendArray()
{
  for(int i=0;i<size;i++)
  array[i] = 0.001*static_cast<double>(i)*200;
}

void Executive::descendArray()
{
  for(int i=0;i<size;i++)
  array[i] = 0.001*static_cast<double>(size-i-1)*200;
}
