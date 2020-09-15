template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if(subTreePtr==NULL)
  {
    return(0);
  }
  else if(getHeightHelper(subTreePtr->getLeftChildPtr())>=getHeightHelper(subTreePtr->getRightChildPtr()))
    return(1+getHeightHelper(subTreePtr->getLeftChildPtr()));
  else{
    return(1+getHeightHelper(subTreePtr->getRightChildPtr()));
  }
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if(subTreePtr!=NULL)
  {
    return(1+getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())+getNumberOfNodesHelper(subTreePtr->getRightChildPtr()));
  }
  else
    return(0);
}

// Recursively deletes all nodes from the tree.
template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if(!isEmpty())
  {
    if(subTreePtr->getLeftChildPtr()!= nullptr)
      destroyTree(subTreePtr->getLeftChildPtr());
    if(subTreePtr->getRightChildPtr()!= nullptr)
      destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

// Copies the tree rooted at treePtr and returns a pointer to
// the copy.
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* newTreePtr = nullptr;
  if(treePtr != nullptr)
  {
    newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(),nullptr,nullptr);
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return(newTreePtr);
}
// Recursive traversal helper methods:
template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    ItemType theItem = treePtr->getItem();
    visit(theItem);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType theItem = treePtr->getItem();
    visit(theItem);
  }
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
{
  rootPtr = nullptr;
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr,const BinaryNodeTree<ItemType>* rightTreePtr)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
  if(rootPtr==nullptr)return(true);
  return(false);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
  return(getHeightHelper(rootPtr));
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
  return(getNumberOfNodesHelper(rootPtr));
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcep)
{
  if(rootPtr == nullptr)
  {
    throw(PrecondViolatedExcep("Empty tree."));
  }
  return(rootPtr->getItem());
}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
  rootPtr->setItem(newData);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit,rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit,rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit,rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rightHandSide)
{
  if(!this->isEmpty())
  {
    this->clear();
  }
  this->rootPtr=copyTree(rightHandSide.rootPtr);
  return(*this);
}
