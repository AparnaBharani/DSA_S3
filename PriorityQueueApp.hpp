#ifndef PRIORITYQUEUEAPP_HPP
#define PRIORITYQUEUEAPP_HPP

#include <iostream>
#include "PriorityQueue.hpp"

namespace PriorityQueueSpace {

void Demo() {
    std::cout << "\n--- Priority Queue---\n";

    PriorityQueue<int> pq(10);  
    std::cout << "Inserting elements: 15, 10, 20, 5\n";
    pq.insert(15);
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);

    std::cout << "Size of queue: " << pq.size() << "\n";

    std::cout << "Removing elements in priority order:\n";
    int maxVal;
    while (!pq.isEmpty()) {
        pq.getmax(maxVal);
        std::cout << maxVal << " ";
    }
    std::cout << "\nQueue empty? " << (pq.isEmpty() ? "Yes" : "No") << "\n";
}

} 
#endif
