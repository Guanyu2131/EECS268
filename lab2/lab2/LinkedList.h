/*------------------------------------------------------------------------------
@File Name:LinkedList.h
@Author:Guanyu Li
@Data:9/10/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as insert, remove, replace.
------------------------------------------------------------------------------*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListInterface.h"
#include "Node.h"

template <typename T>
class LinkedList: public ListInterface<T>
{
private:
  int m_length;
  Node<T>* m_front;
  void clear();

public:

  /**
  * @post All memory allocated by the implementing class should be freed.
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
  ~LinkedList();

  /**
  *@pre nothing is there
  *@post initialize the Linkedlist
  **/
  LinkedList();

  /**
  *@pre do not know is there anything in linkedlist
  *@post know if it is empty or not
  *@return 1 or 0
  **/
  bool isEmpty() const;

  /**
  *@pre do not know what is length for linkedlist
  *@post know the length
  *@return std::cout length.
  **/
  int getLength() const;

  /**
  * @pre The position is between 1 and the list's length+1
  * @post add the entry at the given position
  * @param position:  1<= position <= length+1
  * @param Entry: A new entry to put in the list
  * @throw std::runtime_error if the position is invalid.
  **/
  void insert(int position, T entry) throw (std::runtime_error);

  /**
  * @pre The position is between 1 and the list's length
  * @post Remove the entry at the given position
  * @param position:  1<= position <= length
  * @throw std::runtime_error if the position is invalid.
  **/
  void remove(int position) throw (std::runtime_error);

  /**
  * @pre The position is between 1 and the list's length
  * @post Show the entry at the given position
  * @param position:  1<= position <= length
  * @throw std::runtime_error if the position is invalid.
  **/
  T getEntry(int position) const throw (std::runtime_error);

  /**
  * @pre The position is between 1 and the list's length
  * @post The entry at the given position is replaced with the new entry
  * @param position:  1<= position <= length
  * @param newEntry: A new entry to put in the list
  * @throw std::runtime_error if the position is invalid.
  **/
  void replace(int position, T newEntry) throw (std::runtime_error);
};

#include "LinkedList.cpp"
#endif
