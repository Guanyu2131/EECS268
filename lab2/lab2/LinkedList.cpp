/*------------------------------------------------------------------------------
@File Name:LinkedList.cpp
@Author:Guanyu Li
@Data:9/10/2018
@Description: this file includes functions to do some thing to Nodes we have,
@such as insert, remove, replace.
------------------------------------------------------------------------------*/
template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
LinkedList<T>::LinkedList()
{
  m_front=nullptr;
  m_length=0;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
  if(m_front==nullptr)
  return(true);
  else
  return(false);
}

template<typename T>
int LinkedList<T>::getLength() const
{
  return(m_length);
}

template<typename T>
void LinkedList<T>::insert(int position, T entry) throw (std::runtime_error)
{
  if(position>m_length+1||position<1)
  {
    throw(std::runtime_error("Invalid Position for insert()."));
  }
  else
  {
    Node<T>* temp = new Node<T>(entry);
    if(position == 1)
    {
      temp->setNext(m_front);
      m_front=temp;
    }
    else if(position == m_length+1)
    {
      Node<T>* temp2 = m_front;
      while(temp2->getNext()!=nullptr)
      temp2=temp2->getNext();
      temp2->setNext(temp);
    }

    else
    {
      Node<T>* temp2 = m_front;
      Node<T>* temp3 = m_front;
      for(int i=1; i<position-1; i++)
      temp2=temp2->getNext();
      for(int i=1; i<position; i++)
      temp3=temp3->getNext();
      temp2->setNext(temp);
      temp2->getNext()->setNext(temp3);
    }
    m_length++;
  }
}

template<typename T>
void LinkedList<T>::remove(int position) throw (std::runtime_error)
{
  if(position>m_length||position<1)
  {
    throw(std::runtime_error("Invalid Position for remove()."));
  }
  else
  {
    if(position == 1)
    {
      Node<T>* temp = m_front->getNext();
      delete m_front;
      m_front = temp;
    }
    else if(position == m_length)
    {
      Node<T>* temp = m_front;
      Node<T>* temp2 = m_front;
      for(int i=1; i<position; i++)
      {
        temp2=temp;
        temp=temp->getNext();
      }
      temp2->setNext(nullptr);
      delete temp;
    }
    else
    {
      Node<T>* temp = m_front;
      Node<T>* temp2 = m_front;
      for(int i=1; i<position-1; i++)
      temp = temp->getNext();                  //get to position one before remove postion.
      for(int i=1; i<position+1; i++)
      temp2 = temp2->getNext();
      delete temp->getNext();
      temp->setNext(temp2);
    }
    m_length--;
  }
}

template<typename T>
void LinkedList<T>::clear()
{
  while(isEmpty()==false)
  {
    remove(1);
    // for(int i=1; i<=m_length; i++)
    // {
    //   Node<T>* temp = m_front;
    //   Node<T>* temp2 = m_front;
    //   while(temp->getNext()!=nullptr)
    //   {
    //     temp2=temp;
    //     temp=temp->getNext();
    //   }
    //   temp2->setNext(nullptr);
    //   delete temp;
    // }
  }
}

template<typename T>
T LinkedList<T>::getEntry(int position) const throw (std::runtime_error)
{
  if(position>m_length||position<1)
  {
    throw(std::runtime_error("Invalid Position for getEntry()."));
    return(m_front->getEntry());
  }
  else
  {
    Node<T>* temp = m_front;
    for(int i=1; i<position; i++)
    {
      temp=temp->getNext();
    }
    return(temp->getEntry());
  }
}

template<typename T>
void LinkedList<T>::replace(int position, T newEntry) throw (std::runtime_error)
{
  if(position>m_length||position<1)
  {
    throw(std::runtime_error("Invalid Position for replace()."));
  }
  else
  {
    Node<T>* temp = m_front;
    for(int i=1; i<position; i++)
    temp = temp->getNext();                  //get to position one before remove postion.
    temp->setEntry(newEntry);
  }
}
