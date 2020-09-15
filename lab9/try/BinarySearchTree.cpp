template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,BinaryNode<ItemType>* newNode,bool& success)
{
  if(subTreePtr==NULL)
    {
      success=true;
      return(newNode);
    }
  else if(subTreePtr->getItem()>newNode->getItem())
  {
    BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(),newNode,success);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(),newNode,success);
    subTreePtr->setRightChildPtr(tempPtr);
  }
  return(subTreePtr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr)const
{
  if(subTreePtr==NULL)
  {
    return(0);
  }
  else if(getHeightHelper(subTreePtr->getLeftChildPtr())>=getHeightHelper(subTreePtr->getRightChildPtr()))
  {
    return(1+getHeightHelper(subTreePtr->getLeftChildPtr()));
  }
  return(1+getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr)const
{
  if(subTreePtr==NULL)
  {
    return(0);
  }
  return(1+getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())+getNumberOfNodesHelper(subTreePtr->getRightChildPtr()));
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  if(treePtr==nullptr)
  {
    return(nullptr);
  }
  BinaryNode<ItemType>* temp = new BinaryNode<ItemType>(treePtr->getItem());
  temp->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
  temp->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
   if(!isEmpty())
   {
     if(subTreePtr->getLeftChildPtr()!=nullptr)
      destroyTree(subTreePtr->getLeftChildPtr());
     if(subTreePtr->getRightChildPtr()!=nullptr)
      destroyTree(subTreePtr->getRightChildPtr());
   }
   delete subTreePtr;
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,KeyType aKey,bool& success)
{
  if(subTreePtr==NULL)
  {
    success=false;
    return(nullptr);
  }
  else if(subTreePtr->getItem()==aKey)
  {
    success=true;
    subTreePtr=removeNode(subTreePtr);
    return(subTreePtr);
  }
  else if(subTreePtr->getItem()>aKey)
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(),aKey,success);
    subTreePtr->setLeftChildPtr(tempPtr);
    delete tempPtr;
    return(subTreePtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(),aKey,success);
    subTreePtr->setRightChildPtr(tempPtr);
    delete tempPtr;
    return(subTreePtr);
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  if(nodePtr->isLeaf()==true)
  {
    delete nodePtr;
    nodePtr=nullptr;
    return(nodePtr);
  }
  else if((nodePtr->getLeftChildPtr()==NULL&&nodePtr->getRightChildPtr()!=NULL)||(nodePtr->getLeftChildPtr()!=NULL&&nodePtr->getRightChildPtr()==NULL))
  {
    BinaryNode<ItemType>* NodeChild;
    if(nodePtr->getLeftChildPtr()==NULL)
      NodeChild=nodePtr->getRightChildPtr();
    else
      NodeChild=nodePtr->getLeftChildPtr();
    delete nodePtr;
    nodePtr=nullptr;
    return(NodeChild);
  }
  else{
    ItemType replace;
    BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), replace);
    nodePtr->setRightChildPtr(tempPtr);
    nodePtr->setItem(replace);
    delete tempPtr;
    return(nodePtr);
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,ItemType& inorderSuccessor)
{
  if(subTreePtr->getLeftChildPtr()==NULL)
  {
    inorderSuccessor=subTreePtr->getItem();
    return(removeNode(subTreePtr));
  }
  else
    return(removeLeftmostNode(subTreePtr->getLeftChildPtr(),inorderSuccessor));
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr,KeyType aKey) const
{
  if(treePtr==nullptr)
    return(nullptr);
  else if(treePtr->getItem()==aKey)
    return(treePtr);
  else if(treePtr->getItem()>aKey)
    return(findNode(treePtr->getLeftChildPtr(),aKey));
  else
    return(findNode(treePtr->getRightChildPtr(),aKey));
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    ItemType theItem = treePtr->getItem();
    visit(theItem);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if(treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType theItem = treePtr->getItem();
    visit(theItem);
  }
}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
  rootPtr = nullptr;
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
  clear();
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
  if(rootPtr==nullptr)
  {
    return(true);
  }
  return(false);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const
{
  return(getHeightHelper(rootPtr));
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const
{
  return(getNumberOfNodesHelper(rootPtr));
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry)
{
  bool suc = false;
  BinaryNode<ItemType>* insertion = new BinaryNode<ItemType>(newEntry);
  rootPtr = insertInorder(rootPtr,insertion,suc);
  return(suc);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey)
{
  bool suc = false;
  rootPtr = removeValue(rootPtr, aKey, suc);
  return(suc);
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
  BinaryNode<ItemType>* search = findNode(rootPtr,aKey);
  if(search==NULL)
    throw (NotFoundException("Did not found key."));
  else
    return(search->getItem());
}

// An entry in a BST can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const throw(NotFoundException, InvalidSetEntryRequest)
{
  if(!(item == aKey))
  {
    throw (InvalidSetEntryRequest("Invalid set entry."));
  }
  else
  {
    BinaryNode<ItemType>* search = findNode(rootPtr,aKey);
    if(search==NULL)
    {
      throw (NotFoundException("Did not found key."));
    }
    search->setItem(item);
  }
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const
{
  if(findNode(rootPtr,aKey)!=nullptr)
    return(true);
  else
    return(false);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit,rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit,rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit,rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide)
{
  if(!this->isEmpty())
  {
    this->clear();
  }
  this->rootPtr=copyTree(rightHandSide.rootPtr);
  return(*this);
}
