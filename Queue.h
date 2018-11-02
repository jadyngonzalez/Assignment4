#include "DLinkedList.h"

template<class T>
class Queue
{
  public:
    Queue();
    ~Queue();

    void insert(T data);
    T remove();
    bool isEmpty();
    unsigned int getSize();
  private:
    int size;
    DLinkedList<T> *myQueue;
};

template<class T>
Queue<T>::Queue()
{
  size = 0;
  myQueue = new DLinkedList<T>();
}

template<class T>
Queue<T>::~Queue()
{
  delete myQueue;
}

template<class T>
void Queue<T>::insert(T data)
{
  myQueue->insertBack(data);
  ++size;
}

template<class T>
T Queue<T>::remove()
{
  if(size < 1)
  {
    cerr << "cannot remove on an empty queue" << endl;
    exit(0);
  }
  else
  {
    return myQueue->removeFront();
    --size;
  }
}

template<class T>
bool Queue<T>::isEmpty()
{
  return size == 0;
}

template<class T>
int Queue<T>getSize()
{
  return size;
}
