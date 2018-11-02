#ifndef Queue_H
#define Queue_H
#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

template <class T>
class Queue
{
  public:
    unsigned int elements;
    Node<T> *front;
    Node<T> *back;

    Queue();
    ~Queue();

    void insert(T d);
    T remove();

    T peek();
    T bPeek();

    void print();
    bool isEmpty();
    unsigned int getSize();
};

template <class T>
Queue<T>::Queue()
{
  elements = 0;
  front = NULL;
  back = NULL;
}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::insert(T d)
{
  Node<T> *node = new Node<T>(d);
  if(elements == 0)
  {
      front = node;
  }
  else
  {
      back->next = node;
      node->prev = back;
  }

  back = node;
  ++elements;
}

template <class T>
T Queue<T>::remove()
{

  if(!isEmpty()) {
    Node<T> *node = front;

    T temp = node->data;

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

    delete node;
    elements--;
    return temp;
  }
  else
  {
    return T();
  }
}

template <class T>
T Queue<T>::peek()
 {
  if(isEmpty() == false)
  {
    return front->data;
  }
  return T();
}

template <class T>
T Queue<T>::bPeek()
{
  if(isEmpty() == false)
  {
    return back->data;
  }
  return T();
}

template <class T>
void Queue<T>::print()
{
  if(isEmpty() == false)
  {
    Node<T> *curr = front;
    while(true)
    {
      if(curr != NULL)
      {
        curr = curr->next;
      }
      else
      {
        break;
      }
    }
  }
  else
  {
    cout << "Queue is empty!" << endl;
  }
}

template <class T>
bool Queue<T>::isEmpty()
{
  return (elements == 0);
}

template <class T>
unsigned int Queue<T>::getSize()
{
  return elements;
}
#endif
