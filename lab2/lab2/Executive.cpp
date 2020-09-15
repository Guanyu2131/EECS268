/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:Executive.cpp
@Date:9/14/2018
@Brief: this file is use for reading command from file and run the command from
@browser.h
------------------------------------------------------------------------------*/
void Executive::run(string file)
{
  string address = "";
  string comand = "ABC";
  ifstream inFile;
  inFile.open(file);

  while(comand != "")
  {
    inFile >> comand;
    if(inFile.eof())
    break;
    if(comand=="NAVIGATE")
    {
      inFile >> address;
      mybrows.navigateTo(address);
    }
    if(comand=="BACK")
    {
      mybrows.back();
    }
    if(comand=="FORWARD")
    {
      mybrows.forward();
    }
    if(comand=="HISTORY")
    {
      mybrows.print();
    }
  }
}

/*Executive::Executive()
{
  string address = "";
  string comand = "ABC";
  ifstream inFile;
  inFile.open(file);

  while(comand != "")
  {
    inFile >> comand;
    if(inFile.eof())
    break;
    if(comand=="NAVIGATE")
    {
      inFile >> address;
      mybrows.navigateTo(address);
    }
    if(comand=="BACK")
    {
      mybrows.back();
    }
    if(comand=="FORWARD")
    {
      mybrows.forward();
    }
    if(comand=="HISTORY")
    {
      mybrows.print();
    }
  }
}

void Executive::history()
{

}

  while(address != "")
  {
    if(inFile.eof())
    break;
    mybrows.navigateTo(address);
  }
  */
