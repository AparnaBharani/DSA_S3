#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<iostream>
#include<stdexcept>

template <class T>
class PriorityQueue{
    private:

    T *items;
    int capacity;
    int n;


    void fixUp(int k);
    void fixDown(int k);

    public:

    PriorityQueue(int capacity);
    bool insert(T elt);
    bool getmax(T &elt);
    bool isEmpty();
    int size();
    ~PriorityQueue();
};

template<class T>
PriorityQueue<T>::PriorityQueue(int capacity){
    this -> capacity = capacity;
    items = new T[capacity];
    n = 0;
};

template <class T>
bool PriorityQueue<T> ::insert(T elt){
    if (n >= capacity) return false;
    items[n++] = elt;
    fixUp(n);
    return true;
};




template <class T>
bool PriorityQueue<T> ::getmax(T& elt){
    if (isEmpty()) return false;
    elt = items[0];
    std::swap(items[0], items[n - 1]);
    n--;
    fixDown(0);
    return true;
};



template <class T>
void PriorityQueue<T> ::fixUp(int index){
    T value = items[index];
    while(index > 0){
        int parent  = (index - 1)/ 2;
        if (value <= items[parent]) break;
        items[index] = items[parent];
        index = parent;
    }
    items[index] = value;
};

template <class T>
void PriorityQueue<T> ::fixDown(int index){
    T value = items[index];
    while(2 * index + 1 < n){
        int child = 2 * index + 1;
        if (child < n && items[child + 1] > items[child]){
            child ++;
        }
        if (value >= items[child]) break;
        items[index] = items[child];
        index = child;
    }
    items[index] = value;
};


template <class T>
bool PriorityQueue<T> ::isEmpty(){
    return n == 0;
};


template <class T>
int PriorityQueue<T>:: size(){
    return n;
}


template <class T>
PriorityQueue<T>::~PriorityQueue(){
    delete [] items;
}

#endif