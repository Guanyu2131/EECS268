#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <string>
#include <fstream>
#include "BinaryNodeTree.h"
#include "stack.h"

using namespace std;
class Executive
{
public:
  /**
  * @pre filename is a txt type document, should be as a string style
  * @post read file from File and satisfy all kinds of function
  **/
  Executive(string command, string filename);

  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~Executive(){};

  /**
  * @pre get a open file ifstream from calling function
  * @post this function will open the file each time it call itself and store
  * them in BinaryNodeTree. It will stop when it finsh all the read.
  * @param in: opened file
  **/
  BinaryNodeTree<string>* setPrefix(istream& in);

  /**
  * @pre get a open file ifstream from calling function
  * @post this function can read file and decide which string should be the
  * parent in BinaryNodeTree and others become leaf, it will save them in stack
  * and redevelop them in BinaryNodeTree.
  * @param in: opened file
  **/
  BinaryNodeTree<string>* setPostfix(istream& in);

  /**
  *@print string a.
  *@param a: string
  **/
  static void print(string& a);

  /**
  * @pre this function will print BinaryNodeTree bt in preorderTraverse.
  * @post it will call function from BinaryNodeTree the read it with preorder
  * @sequence.
  * @ it will return nothing
  * @param bt: BinaryNodeTree<string>
  **/
  void printTreePreorder(BinaryNodeTree<string> bt);

  /**
  * @pre this function will print BinaryNodeTree bt in inorderTraverse.
  * @post it will call function from BinaryNodeTree the read it with ineorder
  * @sequence.
  * @ it will return nothing
  * @param bt: BinaryNodeTree<string>
  **/
  void printTreeInorder(BinaryNodeTree<string> bt);

  /**
  * @pre this function will print BinaryNodeTree bt in postorderTraverse.
  * @post it will call function from BinaryNodeTree the read it with postorder
  * @sequence.
  * @ it will return nothing
  * @param bt: BinaryNodeTree<string>
  **/
  void printTreePostorder(BinaryNodeTree<string> bt);

  /**
  * @pre this function will print BinaryNodeTree t in three traverse:inorder, preorder, postorder
  * @post it will call function printTreeInorder, printTreePostorder, printTreePreorder.
  * @ it will return nothing
  * @param t: BinaryNodeTree<string>
  **/
  void run(BinaryNodeTree<string>* t);
private:

};
#endif
