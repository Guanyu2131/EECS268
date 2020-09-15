#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include<string>
#include<iostream>
#include<fstream>
#include "BinarySearchTree.h"

using namespace std;
class Executive
{
private:
  int timer;
  BinarySearchTree<int,Task>* BST;
  void add(int id,string name,int estimaT);
  void finish(int id);
  void started(int id);
  void start(int id,int t);
  void taskPresent(int id);
  // static void flush(Task& kkk);
public:
  Executive();
  void run(string filename);
  ~Executive(){BST->clear();delete BST;};
};
#endif
