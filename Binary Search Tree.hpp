#include <iostream>
template <class T>
struct TreeNode {
    T keys;
    TreeNode *left, *right;
    TreeNode (T data, TreeNode *left, TreeNode *right){
        this -> data = data;
        this -> left = left;
        this -> right = right;
    }
};

template <class T>
class BST
{
    private:
        TreeNode<T> *root;
    
    public:
        BST ();
        void insert(T key);
        bool del(T key);
        bool search(T key, TreeNode<T> *node);
        void PrintTree();
};

template <class T>
void BST<T> :: insert(T key){
    TreeNode *node = new TreeNode(key, nullptr, nullptr);
    if (root == nullptr){
        root = node;
    }
    else {
        TreeNode *temp = root;
        TreeNode *father = nullptr;

        while(temp != nullptr){
            father = temp;
            if (key < temp -> key){
                temp = temp -> left;
            }
            else if (key >= temp -> key){
                temp = temp -> right;
            }
            
        }
        if (father -> key > key){
                father -> left = node;
            }
        else {
            father -> right = node;
        }
    }
}

template <class T>
bool BST<T> :: search(T key, TreeNode<T> *node){
    if (node == nullptr) return false;
    if (node -> key == key) return true;
    else if (key < node -> key) return search(key, node -> left);
    else return search(key, node -> right);
}

