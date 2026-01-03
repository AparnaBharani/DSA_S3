#ifndef LIST_HPP
#define LIST_HPP

template <class T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;
    Node* tail; 
    Node* iter;

public:
    List() : head(nullptr), tail(nullptr), iter(nullptr) {} 

    
    void add(T elt) {
        Node* newNode = new Node(elt);
        if (head == nullptr) {
            
            head = newNode;
            tail = newNode;
        } else {
            
            tail->next = newNode;
            
            tail = newNode;
        }
    }

    
    bool begin(T& out) {
        iter = head;
        if (iter) {
            out = iter->data;
            return true;
        }
        return false;
    }

    
    bool getNext(T& out) {
        if (iter && iter->next) {
            iter = iter->next;
            out = iter->data;
            return true;
        }
        return false;
    }

    
    ~List() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
};

#endif