/*------------------------------------------------------------------------------
@File Name:Queue.cpp
@Author:Guanyu Li
@Data:9/19/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as add to the back, remove the front, getentry at front.
------------------------------------------------------------------------------*/
template<typename T>
Queue<T>::Queue()
{
  m_front=nullptr;
  m_back=nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
  while(isEmpty()!=true)
    dequeue();
}

// template<typename T>
// Queue<T>& Queue<T>::operator=(const Queue<T>& original)
// {
//   // if(this ==&myQ){return *this;}
//   // else{
//   // Node<T>* origin = myQ.m_front;
//   // if(origin == nullptr)
//   //   {
//   //     m_front=nullptr;
//   //   }
//   //   else{
//   //     m_front = new Node<T>;
//   //     m_front->setEntry(origin->getEntry());
//   //     Node<T>* temp = m_front;
//   //     while(origin != nullptr)
//   //     {
//   //       Node<T>* temp = origin->getNext();
//   //       T next = origin->getEntry();
//   //       Node<T>* temp2 = new Node<T>(next);
//   //       temp->setNext(temp2);
//   //       temp=temp->getNext();
//   //     }
//   //     temp->setNext(nullptr);
//   //   }
//   //   return(*this);
//   // }
//   while(!isEmpty){dequeue();}
//   m_front = new Node<T>(original.peekFront());
//   Node<T>* temp = m_front;
//   original.pop();
//   while(m_front->peekFront()!= nullptr)
//   {temp->setNext(new Node<T>(original.peekFront()));
//   original.pop();}
// }

template<typename T>
bool Queue<T>::isEmpty()const
{
  if(m_front==nullptr)
  return(true);
  else
  return(false);
}

template<typename T>
void Queue<T>::enqueue(const T& newEntry) throw (PrecondViolatedExcep)
{
  Node<T>* temp = new Node<T>(newEntry);
  if(isEmpty() == true)
  {
    m_front=temp;
    m_back=temp;
  }
  else{
    m_back->setNext(temp);
    m_back=temp;
  }
}

template<typename T>
void Queue<T>::dequeue() throw (PrecondViolatedExcep)
{
  if(isEmpty()==true)
  {
    throw PrecondViolatedExcep("The Queue is empty, cannot dequeue.\n");
  }
  else{
    Node<T>* temp = m_front->getNext();
    delete m_front;
    m_front = temp;
  }
}

template<typename T>
T Queue<T>::peekFront() const throw (PrecondViolatedExcep)
{
  if(isEmpty()==true)
  {
    throw PrecondViolatedExcep("The Queue is empty, cannot peek.\n");
  }
  else{
    return(m_front->getEntry());
  }
}
