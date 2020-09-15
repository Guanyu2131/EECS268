/*------------------------------------------------------------------------------
@File Name:parenthesis.h
@Author:Guanyu Li
@Data:9/27/2018
@Description:recursion function is isBalenced(char* sample, int count), char*
@sample is a pointer can move from left to right to count if it is balence.
------------------------------------------------------------------------------*/
#ifndef PARENTHESIS_H
#define PARENTHESIS_H
#include <string>
#include <iostream>
using namespace std;

class parenthesis
{
private:
public:
/**
* @pre The sample is a pointer, and count is an integer
* @post will read entry at * and return true or false
* @param sample: is a pointer type value
* @param Entry: A count to save how many time the (())read
**/
  bool isBalenced(char* sample,int count);
};
#endif
