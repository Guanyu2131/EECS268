/*------------------------------------------------------------------------------
@File Name:flood.h
@Author:Guanyu Li
@Data:10/4/2018
@Description:this file will call flood, bool iscomplete, insert and flowRec
@ function.which will copy the exactly the same map from txt and then fill it up.
------------------------------------------------------------------------------*/
#ifndef FLOOD_H
#define FLOOD_H
#include <iostream>
using namespace std;

class flood
{
private:
  char** map;
  int rows;
  int cols;
  int contt;

public:
  /** constructor allows create new 2D array type
      heap memory when the flood is called. Need size and water capacity */
  flood(int r,int c, int cont);

  /** Destructor allows concrete implementations to clean up
     heap memory when the flood is discarded. */
  ~flood();

  /**
  * @pre this function is to check if flood complete its job
  * @post if we read '~' and there are some area near by it was blank space,
  * @it will return false
  * @if we check all the map and area connect with '~'was fill up with water,
  * @ it will return true
  **/
  bool isComplete();

  /**
  * @pre r and c are the rows and columns position we are goint to check
  * @post if up, right, down, left does not have blank space, return true.
  * @ Otherwise, return false
  * @param r: rows position
  * @param c: columns position
  **/
  bool isFull(int r, int c);

  /**
  * @pre r and c are rows and columns, they are not suppose to over the size of map.
  * @post add the terrain to the given position
  * @param r: r>=0 && r<rows
  * @param c: c>=0 && c<cols
  * @param terrain: terrain is a char and either 'H' or ' '
  **/
  void insert(int r, int c, char terrain);

  /**
  * @pre get to position array[current_r][current_c]and insert something
  * @post this function will call itself until the contt==0 or fill all the space
  * @param current_r: rows position
  * @param current_c: columns position
  **/
  void flowRec(int current_r, int current_c);

  /**
  *@print all the node
  **/
  void print() const;
};
#endif
