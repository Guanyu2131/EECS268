#include "Executive.h"
Executive::Executive()
{
  BST = new BinarySearchTree<int,Task>;
}

void Executive::run(string filename)
{
  string command;
  int T_ID;
  string T_name;
  int T_estimatedtime;
  ifstream fin;
  fin.open(filename);
  if(fin.fail())
  {
    cout<<"Open File Error.\n";
  }
  while(fin>>command)
  {
    if(command=="add")
    {
      fin>>T_ID;
      fin>>T_name;
      fin>>T_estimatedtime;
      add(T_ID, T_name, T_estimatedtime);
      cout<<endl;
    }
    else if(command=="finish")
    {
      fin>>T_ID;
      finish(T_ID);
      cout<<endl;
    }
    else if(command=="started")
    {
      fin>>T_ID;
      started(T_ID);
      cout<<endl;
    }
    else if(command=="start")
    {
      fin>>T_ID;
      start(T_ID,timer);
      cout<<endl;
    }
    else if(command=="taskPresent")
    {
      fin>>T_ID;
      taskPresent(T_ID);
      cout<<endl;
    }
    else if(command=="height")
    {
      cout<<"The height of this tree is "<<BST->getHeight()<<endl;
      cout<<endl;
    }
    else if(command=="numberNodes")
    {
      cout<<"The number of nodes for this tree is "<<BST->getNumberOfNodes()<<endl;
      cout<<endl;
    }
    else if(command=="flush")
    {
      // BST->postorderTraverse(flush);
    }
    timer++;
  }
}

void Executive::add(int id, string name, int estimaT)
{
  if(BST->contains(id)==1)
    cout<<"ERROR! Task "<<id<<" already exist.\n";
  else{
    cout<<"Task: "<<id<<" has added to BST.\n";
    Task t(id,name,estimaT,timer,-1);
    BST->add(t);
  }
}

void Executive::finish(int id)
{
  if(BST->contains(id)!=1)
    cout<<"ERROR! Task "<<id<<" does not exist.\n";
  else
  {
    if(BST->getEntry(id).getTimeStarted()==-1)
      cout<<"ERROR! Task "<<id<<" has not start yet.\n";
    else
      BST->getEntry(id).print();
      cout<<"Task "<<id<<" has finished.\n";
      BST->remove(id);
  }
}

void Executive::started(int id)
{
  if(BST->contains(id)==1)
  {
    if(BST->getEntry(id).getTimeStarted()>-1)
      cout<<"Task "<<id<< " has started.\n";
    else
      cout<<"Task "<<id<<" has not started.\n";
  }
  else
    cout<<"ERROR! Task "<<id<<" does not exist.\n";
}

void Executive::start(int id,int t)
{
  if(BST->contains(id)!=1)
    cout<<"ERROR! Task "<<id<<" does not exist.\n";
  else
  {
    if(BST->getEntry(id).getTimeStarted()>-1)
      cout<<"ERROR! Task "<<id<<" has started.\n";
    else
    {
      BST->getEntry(id).setTimeStarted(t);
      cout<<"Task "<<id<<" has started.\n";
      BST->getEntry(id).print();
    }
  }
}

void Executive::taskPresent(int id)
{
  if(BST->contains(id))
    BST->getEntry(id).print();
  else
    cout<<"This task "<<id<<" is not present in BST.\n";
}
//
// void Executive::flush(Task& kkk)
// {
//   if(kkk.getTimeStarted()==-1)
//   {
//     cout<<"Task "<<kkk.getTaskID()<<" has not start.\n";
//     kkk.setTimeStarted(6);
//     cout<<"Task "<<kkk.getTaskID()<<" has started.\n";
//     kkk.print();
//   }
//   kkk.print();
//   cout<<"Task "<<kkk.getTaskID()<<" has finished.\n";
//   kkk.clear();
// }
