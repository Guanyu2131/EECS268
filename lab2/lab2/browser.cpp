/*------------------------------------------------------------------------------
@Author: Guanyu Li
@File:browser.cpp
@Date:9/14/2018
@Brief: this file is connect the function from LinkedList.h to satisfy more
@precise function, such as forward, back, navigate, print.
------------------------------------------------------------------------------*/
browser::~browser()
{
  delete myhistory;
  current = 0;
}

browser::browser()
{
  myhistory = new LinkedList<string>;
  current = 0;
}

void browser::navigateTo(string url)
{
  // myhistory->insert(1,url);
  // current = 1;
  for(int i=myhistory->getLength();i>current;i--)
  myhistory->remove(i);
  current=myhistory->getLength()+1;
  myhistory->insert(current,url);

}

void browser::forward()
{
  if(current<myhistory->getLength())
  {
    current++;
  }
}

void browser::back()
{
  if(current>1)
  {
    current--;
  }
}

string browser::currentURL() const
{
  return(myhistory->getEntry(current));
}

void browser::print()
{
  cout<<"Oldest\n";
  cout<<"===========\n";
  // for(int i=myhistory->getLength(); i>0; i--)
  // {
  //   if(myhistory->getEntry(current)==myhistory->getEntry(i))
  //   cout<<myhistory->getEntry(i)<<"<==current\n";
  //   else{cout<<myhistory->getEntry(i)<<endl;}
  // } this one will print the opposite direction.
  for(int i=1; i<=myhistory->getLength(); i++)
  {
    if(myhistory->getEntry(current)==myhistory->getEntry(i))
    cout<<myhistory->getEntry(i)<<" <==current\n";
    else{cout<<myhistory->getEntry(i)<<endl;}
  }
  cout<<"===========\n";
  cout<<"Newest\n\n";
}

void browser::copyCurrentHistory(ListInterface<string>& destination)
{
  for(int i = destination.getLength(); i>0; i--)
  {
    myhistory->insert(1,destination.getEntry(i));
  }
}
