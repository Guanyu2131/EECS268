//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Modified by JRM (several changes, including making this be a two-parameter template)

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "Task.h"
#include "BinaryNode.h"
#include "NotFoundException.h"
#include "InvalidSetEntryRequest.h"

template<typename KeyType, typename ItemType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode,bool& success);
   int getHeightHelper(BinaryNode<ItemType>* subTreePtr)const;
   int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr)const;
   BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
   void destroyTree(BinaryNode<ItemType>* subTreePtr);
   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, KeyType aKey, bool& success);

   // Removes a given node from a tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const;

   // Recursive traversal helper methods:
   void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const ItemType& rootItem);
   BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree);
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   bool add(const ItemType& newEntry);
   bool remove(const KeyType& aKey);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   // An entry in a BST can be set if and only if "item == aKey".
   // If this is not the case, throw InvalidSetEntryRequest.
   // If "aKey" does not exist in the tree, throw NotFoundException.
   void setEntry(const KeyType& aKey, const ItemType& item) const throw(NotFoundException, InvalidSetEntryRequest);
   bool contains(const KeyType& aKey) const;
   void clear();

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinarySearchTree<KeyType, ItemType>& operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide);
   bool operator>(const KeyType& rhs);
   bool operator>(const ItemType& rhs);
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif