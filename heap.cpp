#include <iostream>


void fixUp(int arr[], int size, int index) {
    int value = arr[index]; 
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (value <= arr[parent]) break;
        arr[index] = arr[parent];  
        index = parent;
    }
    arr[index] = value;  
}


void fixDown(int arr[], int size, int index) {
    int value = arr[index];  
    while (2 * index + 1 < size) {
        int child = 2 * index + 1;  
        if (child + 1 < size && arr[child + 1] > arr[child]) {
            child++; 
        }
        if (value >= arr[child]) break;
        arr[index] = arr[child];  
        index = child;
    }
    arr[index] = value; 
}

int main() {
    int items[] = {100, 90, 80, 85, 87, 70, 75};
    int size = 7;

    
    items[5] = 170;
    fixUp(items, size, 5);

    std::cout << "After fixUp:\n";
    for (int i = 0; i < size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << "\n";

    
    items[0] = 60;
    fixDown(items, size, 0);

    std::cout << "After fixDown:\n";
    for (int i = 0; i < size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
