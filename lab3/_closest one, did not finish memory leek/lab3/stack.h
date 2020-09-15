/*------------------------------------------------------------------------------
@File Name:stack.h
@Author:Guanyu Li
@Data:9/19/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as add to the back, remove back, and look at back.
------------------------------------------------------------------------------*/
#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <stdexcept>
#include "StackInterface.h"
using namespace std;

template<typename T>
class stack: public StackInterface<T>
{
private:
  Node<T>* top;
public:
  /** constructor allows create new node type
      heap memory when the Stack is called. */
  stack();

  /** Destructor allows concrete implementations to clean up
  heap memory when the Stack is discarded. */
  ~stack();

  /** Sees whether this stack is empty.
  @return True if the stack is empty, or false if not. */
  bool isEmpty() const;

  /** Adds a new entry to the top of this stack.
  @post If the operation was successful, newEntry is at the top of the stack.
  @param newEntry The object to be added as a new entry.
  @throw PrecondViolatedExcep if no memory available for the new item */
  void push(const T newEntry)throw (PrecondViolatedExcep);

  /** Removes the top of this stack.
	@pre The stack is not empty.
  @post If the operation was successful, the top of the stack has been removed.
  @throw PrecondViolatedExcep if the stack is empty when called */
  void pop()throw(PrecondViolatedExcep);

  /** Returns the top of this stack.
  @pre The stack is not empty.
  @post The top of the stack has been returned, and the stack is unchanged.
  @return The top of the stack.
  @throw PrecondViolatedExcep if the stack is empty when called */
  T peek()const throw(PrecondViolatedExcep);
};
#include "stack.cpp"
#endif
