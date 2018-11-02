#ifndef Node_H
#define Node_H
#include <iostream>
using namespace std;

template<class T>
class Node
{
  public:
    Node();
    Node(T d);
    ~Node();

    T data;
    Node<T> *next;
    Node<T> *prev;
};

template<class T>
Node<T>::Node()
{

}

template<class T>
Node<T>::Node(T d)
{
  data = d;
  next=NULL;
  prev=NULL;
}

template<class T>
Node<T>::~Node()
{
  next=NULL;
  prev=NULL;
}
#endif
