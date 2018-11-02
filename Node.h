template<class T>
class Node
{
  public:
    Node():
    Node(T d);
    ~Node();

    T data;
    Node<T> *next;
    Node<T> *prev;
};

template<class T>
Node<T>::Node() //default
{
  data = NULL:
}

template<class T>
Node<T>::Node(T d) //constructor
{
  data = d;
  next = NULL:
  prev = NULL;
}

template<class T>
Node<T>::~Node()
{
  //destructor
}
