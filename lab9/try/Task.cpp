#include "Task.h"
Task::Task(int i,string n,int e,int TAB, int TS)
{
  taskID=i;
  taskName=n;
  estimatedTimeToComplete=e;
  timeAddedToBST=TAB;
  timeStarted=TS;
}

void Task::clear()
{
  taskID=0;
  taskName=nullptr;
  estimatedTimeToComplete=0;
  timeAddedToBST=0;
  timeStarted=0;
}

void Task::print()const
{
  cout<<"TaskID: "<<taskID<<endl;
  cout<<"Taskname: "<<taskName<<endl;
  cout<<"Estimate time: "<<estimatedTimeToComplete<<endl;
  cout<<"Time add to BST: "<<timeAddedToBST<<endl;
  cout<<"Time Started: "<<timeStarted<<endl;
}

void Task::setTimeStarted(int TS)
{
  timeStarted=TS;
}

int Task::getTaskID()const
{
  return(taskID);
}

string Task::getTaskName()const
{
  return(taskName);
}

int Task::getEstimatedTimeToComplete()const
{
  return(estimatedTimeToComplete);
}

int Task::getTimeAddedToBST()const
{
  return(timeAddedToBST);
}

int Task::getTimeStarted()const
{
  return(timeStarted);
}

bool Task::operator==(const int& key)
{
  if(taskID==key)
    return(true);
  return(false);
}

bool Task::operator>(const int& key)
{
  if(taskID>key)
    return(true);
  return(false);
}

bool Task::operator>(const Task& T)
{
  if(taskID>T.getTaskID())
    return(true);
  return(false);
}
