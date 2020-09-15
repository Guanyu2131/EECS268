#include "Executive.h"
Executive::Executive(string command, string filename)
{
  // test(visit);
  ifstream inFile;
  inFile.open(filename);
  if(command == "prefix")
  {
    BinaryNodeTree<string>* tree = setPrefix(inFile);
    cout<<"Prefix:\n";
    run(tree);
    delete tree;
  }
  else if(command == "postfix")
  {
    BinaryNodeTree<string>* tree2 = setPostfix(inFile);
    cout<<"Postfix:\n";
    run(tree2);
    delete tree2;
  }
}

BinaryNodeTree<string>* Executive::setPrefix(istream& in)
{
  string read;
  if(!in.eof())
  {
    in >> read;
    if(read=="*"||read=="+"||read=="-"||read=="/")
      return new BinaryNodeTree<string>(read, setPrefix(in), setPrefix(in));
    return new BinaryNodeTree<string>(read);
  }
  return new BinaryNodeTree<string>("hhh");
}

BinaryNodeTree<string>* Executive::setPostfix(istream& in)
{
  string read;

  BinaryNodeTree<string>* left;
  BinaryNodeTree<string>* right;
  BinaryNodeTree<string>* result;
  BinaryNodeTree<string>* temp;
  stack< BinaryNodeTree<string>* > history;
  while(in>>read)
  {
    if(read=="*"||read=="+"||read=="-"||read=="/")
    {
      right = history.peek();
      history.pop();
      left = history.peek();
      history.pop();
      result = new BinaryNodeTree<string>(read, left, right);
      history.push(result);
    }
    else
    {
      temp = new BinaryNodeTree<string>(read);
      history.push(temp);
    }
  }
  delete temp;
  delete left;
  delete right;
  return(history.peek());
}

void Executive::print(string& a)
{
  cout<<a<<"\t";
}

void Executive::printTreePreorder(BinaryNodeTree<string> bt)
{
  cout<<"Preorder: ";
  bt.preorderTraverse(print);
}
void Executive::printTreeInorder(BinaryNodeTree<string> bt)
{
  cout<<"\nInorder: ";
  bt.inorderTraverse(print);
}
void Executive::printTreePostorder(BinaryNodeTree<string> bt)
{
  cout<<"\nPostorder: ";
  bt.postorderTraverse(print);
}

void Executive::run(BinaryNodeTree<string>* t)
{
  printTreePreorder(*t);
  printTreeInorder(*t);
  printTreePostorder(*t);
  cout<<"\n";
}
