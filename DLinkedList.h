#include "Node.h"

template<class T>
class DLinkedList
{
  public:
    DLinkedList();
    ~DLinkedList()

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removePos(int pos);
    int find(T d);

    void print();
    unsigned int getSize();
  private:
    Node<T> *front;
    Node<T> *back;
    unsigned int size;
};

template<class T>
DLinkedList<T>::DLinkedList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

template<class T>
DLinkedList<T>::~DLinkedList()
{
  while(front != NULL)
  {
    ListNode<T> *current = front;
    front = front->next;
    delete current;
  }
}

template<class T>
void DLinkedList<T>::insertFront(T d)
{
  Node<T> *node = new Node<T>(d);
  if(size == 0)
  {
    front = node;
    back = node;
  }
  else
  {
    front->prev = node;
    node->next = front;
    front = node;
  }
  ++size;
}

template<class T>
void DLinkedList<T>::insertBack(T d)
{
  Node<T> *node = new Node<T>(d);
  if(size == 0)
  {
    front = node;
    back = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
    back = node;
  }
  ++size;
}

template<class T>
T DLinkedList<T>::removeFront()
{
  --size;
  Node<T> *node = front;
  if(front == NULL)
  {
    back = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }
  front = front->next;
  node->next = NULL;
  T data = node->data;
  delete node;
  return data;
}

template<class T>
T DLinkedList<T>::removeBack()
{
  --size;
  Node<T> *node = back;
  if(back == NULL)
  {
    front = NULL;
  }
  else
  {
    back->prev->next = NULL;
  }
  back = back->prev;
  node->prev = NULL;
  T data = node->data;
  delete node;
  return data;
}

template<class T>
T DLinkedList::removePos(int pos)
{
  int i = -1;
  Node<T> *current = front;
  Node<T> *previous = front;
  if(pos == 0)
  {
    T d = front->data;
    front = curr->next;
    front->prev = NULL;
    size--;
    delete current;
    return d;
  }

  while(i != pos)
  {
    previous = current;
    current = current->next;
    if(curr == NULL)
    {
      cerr << "Error out of bounds" << endl;
      return -1;
    }
  }

  ++i;

  if(current->next == NULL)
  {
    back = previous;
  }

  previous->next = current->next;
  if(current->next == NULL)
  {
    back = previous;
  }
  else
  {
    current->next->prev = previous;
  }
  current->next = NULL;
  curr->prev = NULL;
  T d = curr->data;
  size--;
  delete curr;
  return d;
}

template<class T>
int DLinkedList::find(T d)
{
  int i = -1;
  Node<T> *current = front;
  while(current != NULL)
  {
    ++i;
    if(current->data == d)
    {
      break;
    }
    else
    {
      current = current->next;
    }
  }

  if(current == NULL)
  {
    i = -1;
  }
  return i;
}

template<class T>
void DLinkedList::print()
{
  Node<T> *current = front;
  while(current != NULL)
  {
    cout << current->data <<endl;
    current = current->next;
  }
}

template<class T>
unsigned int DLinkedList::getSize()
{
  return size;
}
