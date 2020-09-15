/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:process.cpp
@Date:9/23/2018
@Brief: this file is using stack as fundation to statisfy multiple function.
------------------------------------------------------------------------------*/
#include  "process.h"
process::process(string pname)
{
  name = pname;
  MyProcess = new stack<string>;
  MyProcess->push("main");
}

void process::setFunction(string function)
{
  MyProcess->push(function);
}

string process::getName()
{
  return(name);
}

string process::getFunction()
{
  return(MyProcess->peek());
}

void process::start()const
{
  cout<<name<<" added to queue\n";
}

void process::call()
{
  cout<<name<<" calls "<< getFunction()<<endl;
}

void process::ret()
{
  if(MyProcess->peek()!="main")
  {
    cout<<name<<" returns from "<< getFunction()<<endl;
    MyProcess->pop();
  }
  else
  {
    cout<<name<<" returns from main\n";
    MyProcess->pop();
    cout<<name<<" process has ended\n";
  }
}

void process::clear()
{
  while(MyProcess->isEmpty()!=true)
  MyProcess->pop();
  name = "";
}
