#ifndef FIXEDSIZESTACK_H
#define FIXEDSIZESTACK_H

#include<iostream>


template<class T>
class FixedSizeStack{
private:
    T *items;
    int n;
    int capacity;

public:
    FixedSizeStack(int capacity);
    void push(T items);
    bool pop(T &out);
    int size();
    bool isEmpty();

    ~FixedSizeStack();
};

template<class T>
FixedSizeStack<T>::FixedSizeStack(int capacity)
{
    this -> capacity = capacity;
    items = new T[capacity];
    n = 0;
}

template<class T>
void FixedSizeStack<T>::push(T elt)
{
    if (n == capacity) {
      throw std::overflow_error("Stack overflow: cannot push to full stack");

    }
    items[n++] = elt;

}


template<class T>
bool FixedSizeStack<T>::pop(T &out)
{
   if (n==0) return false;
   out = items[--n];
   return true;
}


template<class T>
bool FixedSizeStack<T>::isEmpty()
{
   return n == 0;
}

template<class T>
int FixedSizeStack<T>::size()
{
   return n;
}

template<class T>
FixedSizeStack<T>::~FixedSizeStack()
{
  delete [] items;
}


#endif
