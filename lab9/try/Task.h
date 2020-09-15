#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
using namespace std;

class Task
{
private:
  int taskID;
  string taskName;
  int estimatedTimeToComplete;
  int timeAddedToBST;
  int timeStarted;

public:
  Task(){};
  Task(int i,string n,int e,int TAB, int TS);
  void clear();
  ~Task(){};
  void print()const;
  void setTimeStarted(int TS);
  int getTaskID()const;
  string getTaskName()const;
  int getEstimatedTimeToComplete()const;
  int getTimeAddedToBST()const;
  int getTimeStarted()const;
  bool operator==(const int& key);
  bool operator>(const int& key);
  bool operator>(const Task& T);
};
#endif
