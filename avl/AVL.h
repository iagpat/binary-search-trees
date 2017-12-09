//Binary Search Tree—self balancing (AVL)
//Whenever an item is added to the map, a new node is allocated to hold it; whenever an item is removed, the node that held it is deallocated. 
//Data are inserted/removed using Adelson-Velski & Landis's techniques to ensure the tree is AVL balanced.

#ifndef AVL_H
#define AVL_H
#include <stdexcept>
#include <iostream>
#include <iterator>
#include "node.h"

namespace cop3530 {

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    class AVL {
    public:
        //The big five:
        AVL(); //Constructor
        AVL(AVL& other); //copy constructor
        AVL(AVL&& other); //move constructor
        ~AVL(); //Destructor
        AVL & operator=(AVL & other); //Copt assignment operator
        AVL & operator=(AVL&& other); //Move assignment operator

        //Required Map Operations
        void insert(key, value); //Adds the specified key-value pair to the map
        void remove(key); //Removes the specified key-value pair associated with the key
        value & lookup(key); //Returns a reference to the value associated with the key
        void print();
        void do_print(node<key, value>* node); //Print function for debugging purposes

        //Bonus functions
        bool contains(key);
        bool is_empty();
        bool is_full();
        size_t size();
        void clear();
        int height();
        int balance();

    private:
        bool do_contains(node<key, value>* &, key);
        int do_size(node<key, value>*);

        node<key, value> *root; //Tree root
        void do_destruct(node<key, value> *&); //Helper function for the destructor
        void do_copy(node<key, value>*&, AVL&); //Helper function for copy constructor and copy assignment operator
        value & do_lookup(node<key, value>*&, key); //Returns a reference to the value associated with the key

        node<key, value>* do_insert(node<key, value>*&, key, value); //Helper function for insert method
        node<key, value>* right_rotate(node<key, value>*&); //Right rotation
        node<key, value>* left_rotate(node<key, value>*&); //Left rotation
        node<key, value>* do_remove(node<key, value>*&, key); //Helper function for remove function
        int do_balance(node<key, value>*&);
        int do_height(node<key, value>*&);
    };
    
    //Bonus functions

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    AVL<key, value, compare, equals>::contains(key node_key) {
        return do_contains(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    AVL<key, value, compare, equals>::do_contains(node<key, value>* &root, key node_key) {
        if (!root) return false;
        else if (equals(root->node_key, node_key)) return true;
        else if (compare(node_key, root->node_key)) return do_lookup(root->left, node_key);
        else return do_lookup(root->right, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    AVL<key, value, compare, equals>::is_empty() {
        if (!root) return true;
        return false;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    AVL<key, value, compare, equals>::is_full() {
        return false;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    size_t
    AVL<key, value, compare, equals>::size() {
        return do_size(root);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    AVL<key, value, compare, equals>::do_size(node<key, value>* root) {
        if (!root) {
            return 0;
        } else {
            return 1 + do_size(root->left) + do_size(root->right);
        }
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::clear() {
        do_destruct(this->root);
        this->root = nullptr;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    AVL<key, value, compare, equals>::height() {
        return do_height(root) - 1;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    AVL<key, value, compare, equals>::balance() {
        return do_balance(root);
    }

   


    //============================================================================================================================================================
    // ------- constructor  

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals>::AVL() {
        root = nullptr;
    }

    //============================================================================================================================================================
    // ------- copy constructor 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals>::AVL(AVL& other) {
        root = nullptr;
        other.do_copy(other.root, *this);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::do_copy(node<key, value>* &root, AVL& newer) {
        if (!root) return;
        do_copy(root->left, newer);
        newer.insert(root->node_key, root->node_value);
        do_copy(root->right, newer);
    }

    //============================================================================================================================================================
    // ------- copy-assignment operator 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals> &
    AVL<key, value, compare, equals>::operator=(AVL & other) {
        root = nullptr;
        other.do_copy(other.root, *this);
        return *this;
    }

    //============================================================================================================================================================
    // ------  move constructor

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals>::AVL(AVL&& other) {
        root = other.root;
        other.root = nullptr;
    }

    //============================================================================================================================================================
    // ------- move assignment operator 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals> &
    AVL<key, value, compare, equals>::operator=(AVL && other) {
        root = other.root;
        other.root = nullptr;
        return *this;
    }

    //============================================================================================================================================================
    // ------  destructor 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    AVL<key, value, compare, equals>::~AVL() {
        do_destruct(this->root);
        this->root = nullptr;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::do_destruct(node<key, value> *&node) {
        if (!node) return;
        do_destruct(node->left);
        do_destruct(node->right);
        delete node;
    }

    //============================================================================================================================================================
    // --------- insert()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::insert(key node_key, value node_value) {
        root = do_insert(root, node_key, node_value);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    node<key, value>*
    AVL<key, value, compare, equals>::do_insert(node<key, value>* &root, key node_key, value node_value) {
        if (!root) {
            return new node<key, value>(node_key, node_value);
        } else if (root->node_key == node_key) {
            root->node_value = node_value;
            return root;
        } else if (compare(node_key, root->node_key)) {
            root->left = do_insert(root->left, node_key, node_value);
        } else if (compare(root->node_key, node_key)) {
            root->right = do_insert(root->right, node_key, node_value);
        } else { //Change value
            root->node_value = node_value;
        }
        int bf = do_balance(root);
        if (bf < -1 && node_key > root->right->node_key) {
            return left_rotate(root);
        } else if (bf < -1 && node_key < root->right->node_key) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        } else if (bf > 1 && node_key < root->left->node_key) {
            return right_rotate(root);
        } else if (bf > 1 && node_key > root->left->node_key) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
        return root;

    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    AVL<key, value, compare, equals>::do_balance(node<key, value>* &root) {
        if (!root) return 0;
        return do_height(root->left) - do_height(root->right);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    AVL<key, value, compare, equals>::do_height(node<key, value>* &root) {
        if (!root)
            return 0;
        if (do_height(root->left) > do_height(root->right))
            return 1 + do_height(root->left);
        else
            return 1 + do_height(root->right);
    }

    //============================================================================================================================================================
    //--------- rotations()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    node<key, value>*
    AVL<key, value, compare, equals>::left_rotate(node<key, value>* &root) {
        node<key, value>* temp1 = root->right;
        node<key, value>* temp2 = temp1->left;
        temp1->left = root;
        root->right = temp2;
        return temp1;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    node<key, value>*
    AVL<key, value, compare, equals>::right_rotate(node<key, value>* &root) {
        node<key, value>* temp1 = root->left;
        node<key, value>* temp2 = temp1->right;
        temp1->right = root;
        root->left = temp2;
        return temp1;
    }


    // --------- remove()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::remove(key node_key) {
        root = do_remove(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    node<key, value>*
    AVL<key, value, compare, equals>::do_remove(node<key, value>*& root, key node_key) {
        if (!root) { //Empty tree or subtree
            return root;
        }
        if (compare(node_key, root->node_key)) { //Search left
            root->left = do_remove(root->left, node_key);
        } else if (compare(root->node_key, node_key)) { //Search right
            root->right = do_remove(root->right, node_key);
        } else { //If we have found the vertex that we want to delete
            if (root->left == nullptr || root->right == nullptr) { //If we have 0 children or one child
                //For the following line, if the node has a left child, temp will be the node's
                // left child. If the node has a right child, temp will be the node's right child.
                // If the node doesn't have children, temp will be a nullptr.
                node<key, value> *temp = root->left ? root->left : root->right;
                if (!temp) { //If temp is a nullptr (because the node had 0 children)
                    temp = root;
                    delete root;
                    root = nullptr;
                } else {

                    *root = *temp;
                    delete temp;

                }

            } else { //If we have two children
                node<key, value> *minNode = root->right;
                while (minNode->left != nullptr) minNode = minNode->left;
                root->node_key = minNode->node_key;
                root->node_value = minNode->node_value;
                root->right = do_remove(root->right, minNode->node_key);
            }
        }
        if (!root) {
            return root;
        }
        int bf = do_balance(root);
        if (bf < -1 && do_balance(root->right) <= 0) {
            return left_rotate(root);
        }
        if (bf < -1 && do_balance(root->right) > 0) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
        if (bf > 1 && do_balance(root->left) >= 0) {
            return right_rotate(root);
        }
        if (bf > 1 && do_balance(root->left) < 0) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }
        return root;
    }
    //============================================================================================================================================================
    // --------- lookup()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    value &
    AVL<key, value, compare, equals>::lookup(key node_key) {
        return do_lookup(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    value &
    AVL<key, value, compare, equals>::do_lookup(node<key, value>* &root, key node_key) {
        if (!root) throw std::runtime_error("Key not found");
        else if (equals(root->node_key, node_key)) return root->node_value;
        else if (compare(node_key, root->node_key)) return do_lookup(root->left, node_key);
        else return do_lookup(root->right, node_key);
    }

    //============================================================================================================================================================
    // --------- print()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::print() {
        do_print(root);

    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    AVL<key, value, compare, equals>::do_print(node<key, value>* root) {
        if (!root) {
            return;
        }

        do_print(root->left);
        std::cout << root->node_value << std::endl;

        do_print(root->right);
    }
}


#endif /* AVL_H */

