#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class DoublyLinkedList
{

  public:
    unsigned int size;
    Node<T> *front;
    Node<T> *back;

    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertBack(T data);
    T removeFront();
    Node<T>* getFront();
    void printList();
    void deletePos(int pos);
    bool isEmpty();
    unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

}


template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
  Node<T> *node = new Node<T>(data);

   if(size == 0)
   {
       front = node;
   }

   else
   {
       back->next = node;
       node->prev = back;
   }
   back = node;
   ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront()
 {
  if(!isEmpty())
  {
    Node<T> *node = front;

    if(front->next == NULL)
    {
      front = NULL;
      back = NULL;
    }
    else
    {
      front->next->prev = NULL;
      front = front->next;
    }

    T temp = node->data;
    delete node;
    size;
    return temp;
  }
  else
  {
    return T();
  }
}

template <class T>
Node<T>* DoublyLinkedList<T>::getFront()
{
  return front;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  Node<T> *curr = front;
  while(true)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos)
{
  int idx = 0;
  Node<T> *curr = front;
  Node<T> *prev = front;

   while(idx != pos)
   {
     prev = curr;
     curr = curr->next;
     idx++;
   }

   prev->next = curr->next;
   curr->next->prev = prev;
   curr->next = NULL;

   size--;
   delete curr;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}
#endif
