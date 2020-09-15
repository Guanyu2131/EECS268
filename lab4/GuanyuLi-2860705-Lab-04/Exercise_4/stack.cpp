/*------------------------------------------------------------------------------
@File Name:stack.cpp
@Author:Guanyu Li
@Data:9/19/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as add to the back, remove back, and look at back.
------------------------------------------------------------------------------*/
template<typename T>
stack<T>::stack()
{
  top=nullptr;
}

template<typename T>
stack<T>::~stack()
{
  while(isEmpty()!=true)
  {
    pop();
  }
}

template<typename T>
bool stack<T>::isEmpty() const
{
  if(top==nullptr)
  return(true);
  else
  return(false);
}

template<typename T>
void stack<T>::push(const T newEntry) throw (PrecondViolatedExcep)
{
  Node<T>* temp = new Node<T>(newEntry);
  if(isEmpty()==true)
  {
    top=temp;
  }
  else
  {
  temp->setNext(top);
  top=temp;
  }
}

template<typename T>
void stack<T>::pop() throw (PrecondViolatedExcep)
{
  if(isEmpty()==true)
  {
    throw PrecondViolatedExcep("The list is empty, cannot pop.");
  }
  else{
    Node<T>* temp = top->getNext();
    delete top;
    top=temp;
  }
}

template<typename T>
T stack<T>::peek() const throw (PrecondViolatedExcep)
{
  if(isEmpty()==true)
  {
    throw PrecondViolatedExcep("The list is empty, cannot peek.");
  }
  else{
    return(top->getEntry());
  }
}
