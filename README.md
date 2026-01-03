# DSA_S3

# C++ Data Structures & Algorithms Library

A comprehensive collection of template-based C++ implementations for fundamental data structures and algorithms. This library provides reusable, generic components for Stacks, Queues, Trees, Graphs, and Sorting algorithms, designed for educational understanding and modular application.

##  Project Structure

The project is organized into header files (`.hpp`) for reusable templates and demonstration source files (`.cpp`).

### 1. Linear Data Structures
* **`Stack.hpp`**: Dynamic stack implementation using a **Linked List**.
* **`FixedSizeStack.hpp`**: Static stack implementation using a **Dynamic Array** with a fixed capacity.
* **`Queue.hpp`**: Dynamic queue implementation using a **Linked List** (FIFO).
* **`List.hpp`**: A Singly Linked List implementation (primarily used as a helper for the Graph adjacency list).

### 2. Tree & Heap Structures
* **`BST.hpp`**: A Dictionary-style **Binary Search Tree** storing Key-Value pairs (`K`, `V`). Supports recursive/iterative insertion and deletion.
* **`PriorityQueue.hpp`**: A Max-Priority Queue implemented using a **Binary Heap** (Array-based).
* **`Binary Search Tree.hpp`**: A basic BST implementation focusing on simple keys (alternative to `BST.hpp`).

### 3. Graph Data Structures
* **`Graph.hpp`**: An Adjacency List implementation of a Graph.
    * Supports loading graph data from a file.
    * Includes **BFS** (Breadth-First Search) and **DFS** (Depth-First Search) traversal algorithms.
    * *Dependencies:* Requires `Queue.hpp`, `Stack.hpp`, and `List.hpp`.

### 4. Algorithms
* **`HeapSort.hpp`**: Implementation of the Heap Sort algorithm using generic arrays.
* **`heap.cpp`**: A standalone demonstration file showing the logic of `fixUp` (sift up) and `fixDown` (sift down) heap operations.

---

## 🛠 Usage & Implementation Details

All data structures (except `heap.cpp`) are implemented as C++ **Templates**, allowing them to handle any data type (e.g., `int`, `float`, `std::string`, or custom objects).

### Stack (Linked List vs. Fixed Array)
```cpp
#include "Stack.hpp"
#include "FixedSizeStack.hpp"

