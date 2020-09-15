/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.h
@Date:10/26/2018
@Brief: this file will get file name from user and read the file through functions in Grammer
------------------------------------------------------------------------------*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"
#include <string>

class Executive
{
private:
  double* array;
  int size;
  string sequence;
  string sort;
  
public:
  /** Cestructor allows function create new Executive type
    @heap memrory. It will create a new array and store size, sequence, sort type.*/
  Executive(string si, string seq, string sor);

  /** Destructor allows concrete implementations to clean up
    heap memory when the Executive is discarded. */
  ~Executive();

  /**
  *@run the command line(size, sequence,sort) and print final time consuming.
  **/
  void run();

  /**
  *@get array from sequence, there are three types of sequence: random, ascending, descending
  **/
  void getArray();

  /**
  *@obtain randome sequence array with given size
  **/
  void randomeArray();

  /**
  *@obtain ascending sequence array with given size
  **/
  void ascendArray();

  /**
  *@obtain descending sequence array with given size
  **/
  void descendArray();
};
#endif
