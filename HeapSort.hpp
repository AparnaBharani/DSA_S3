#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>

template<class T>
class HeapSort {
public:
    HeapSort(){} ;
    void sort(T* arr, int size);

private:
    void fixDown(T* array, int k, int n);
    void heapify(T* array, int n);
};

template<class T>
void HeapSort<T>::heapify(T* array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        fixDown(array, i, n);
    }
}

template<class T>
void HeapSort<T>::sort(T* arr, int size) {
    heapify(arr, size); 

    for (int i = 0; i < size - 1; i++) {
        T temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[0];
        arr[0] = temp;
        // std::swap(arr[size-1-i], arr[0]); 
        fixDown(arr, 0, size-1-i);         
    }
}

template<class T>
void HeapSort<T>::fixDown(T* array, int k, int n) {
    T temp;
    while(k<n/2){
        int child = 2*k+1;
        if(child+1<n && array[child]<array[child+1]){
            child++;
        }
        if(array[k]>=array[child]){
            break;
        }
        temp = array[k];
        array[k] = array[child];
        array[child] = temp;
        k = child;
    }
}
#endif
