/*------------------------------------------------------------------------------
@File Name:Queue.h
@Author:Guanyu Li
@Data:9/19/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as add to the back, remove the front, getentry at front.
------------------------------------------------------------------------------*/
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <stdexcept>
#include "QueueInterface.h"

template<typename T>
class Queue: public QueueInterface<T>
{
private:
  Node<T>* m_front;
  Node<T>* m_back;
public:
  /** Cestructor allows function create new node type
      heap memory when the Queue is called. */
  Queue();

  /** Destructor allows concrete implementations to clean up
      heap memory when the Queue is discarded. */
  ~Queue();

  // Queue<T>& operator=(const Queue<T>& original);

  /** Sees whether this queue is empty.
   @return True if the queue is empty, or false if not. */
  bool isEmpty()const;

  /** Adds a new entry to the back of this queue.
   @post If the operation was successful, newEntry is at the back of the queue.
   @param newEntry  The object to be added as a new entry.
   @throw PrecondViolatedExcep if no memory available for the new item */
  void enqueue(const T& newEntry) throw (PrecondViolatedExcep);

  /** Removes the front of this queue.
   @post If the operation was successful, the front of the queue has been removed.
   @throw PrecondViolatedExcep if the queue is empty when called */
  void dequeue() throw (PrecondViolatedExcep);

  /** Returns the front of this queue.
   @pre The queue is not empty.
   @post The front of the queue has been returned, and the queue is unchanged.
   @throw PrecondViolatedExcep if the queue is empty when called */
  T peekFront() const throw (PrecondViolatedExcep);

};
#include "Queue.cpp"
#endif
