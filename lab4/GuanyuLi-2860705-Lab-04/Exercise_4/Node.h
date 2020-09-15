/*------------------------------------------------------------------------------
@File Name:Node.h
@Author:Guanyu Li
@Data:9/10/2018
@Description: this file is creat small nodes and connect them together.
------------------------------------------------------------------------------*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
  T m_entry;
  Node<T>* m_next;

public:

  /**
  *@pre the Node does not exist
  *@post create a new node that has no value and point to nothing
  *@return next->nullptr
  **/
  Node(); //default construcftor

  /**
  *@pre the Node does not exist
  *@post create a new node that its value is entry
  *@return next->nullptr
  **/
  Node(T entry);

  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~Node(){}

  /**
  * @pre we do not know what is the entry in current node
  * @post to present the velue in this node
  * @return show the entry in current node
  **/
  T getEntry()const;

  /**
  * @pre we do not know what is the next entry
  * @post to present the next node
  * @return show the entry in next node
  **/
  Node<T>* getNext()const;

  /**
  * @pre give a value to the node
  * @post this node have this value
  **/
  void setEntry(T value);

  /**
  * @pre let node right here point to another node
  * @post two node connect together, node1->node2
  **/
  void setNext(Node<T>* next);

};

#include "Node.cpp"
#endif
