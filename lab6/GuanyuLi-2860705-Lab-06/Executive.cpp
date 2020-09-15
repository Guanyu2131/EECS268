/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.cpp
@Date:10/12/2018
@Brief: this file will get file name from user and read the file through functions in Grammer
------------------------------------------------------------------------------*/
#include "Executive.h"
Executive::Executive(string filename_1,string filename_2)
{
  string command = "A";
  Grammer Question(filename_1);
  Grammer Answer(filename_2);
  cout<<"Enter command: ";
  cin>>command;
  while(command!="Q")
  {
    if(command!="A")
    {
      cout<<"Invalid command! ";
    }
    else
    cout<<Question.Reply()<<endl;
    cout<<Answer.Reply()<<endl;
    cout<<"Enter command: ";
    cin>>command;
    Question.clear();
    Answer.clear();
  }
}
