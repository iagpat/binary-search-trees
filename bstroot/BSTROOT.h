//Binary Search Tree—insert at root (BSTROOT)
//Whenever an item is added to the map, a new node is allocated to hold it; whenever an item is removed, the node that held it is deallocated. 
//Data are inserted at the root. [Use the process described in lecture on 11/07]

#ifndef BSTROOT_H
#define BSTROOT_H
#include <stdexcept>
#include <iostream>
#include <iterator>
#include "node.h"

namespace cop3530 {

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    class BSTROOT {
    public:
        //The big five:
        BSTROOT(); //Constructor
        BSTROOT(BSTROOT&); //copy constructor
        BSTROOT(BSTROOT&& other); //move constructor
        ~BSTROOT(); //Destructor
        BSTROOT & operator=(BSTROOT & other);
        BSTROOT & operator=(BSTROOT&& other);

        //Required Map Operations
        void insert(key, value); //Adds the specified key-value pair to the map
        void remove(key); //Removes the specified key-value pair associated with the key
        value & lookup(key); //Returns a reference to the value associated with the key

        //Bonus functions
        bool contains(key);
        bool is_empty();
        bool is_full();
        size_t size();
        void clear();
        int height();
        int balance();


    private:
        //Bonus helper functions
        bool do_contains(node<key, value>* &, key);
        int do_size(node<key, value>*);
        int do_height(node<key, value>*&);
        int do_balance(node<key, value>*&);

        void print();
        node<key, value> *root;
        void do_copy(node<key, value>*&, BSTROOT&);
        void do_destruct(node<key, value> *&);
        value & do_lookup(node<key, value>*&, key); //Returns a reference to the value associated with the key
        void do_insert(node<key, value>*&, key, value);
        void do_print(node<key, value>* node);
        node<key, value>* do_remove(node<key, value>*, key);
        void rotate_right(node<key, value>*&);
        void rotate_left(node<key, value>*&);
    };

    //Bonus functions

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    BSTROOT<key, value, compare, equals>::contains(key node_key) {
        return do_contains(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    BSTROOT<key, value, compare, equals>::do_contains(node<key, value>* &root, key node_key) {
        if (!root) return false;
        else if (equals(root->node_key, node_key)) return true;
        else if (compare(node_key, root->node_key)) return do_lookup(root->left, node_key);
        else return do_lookup(root->right, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    BSTROOT<key, value, compare, equals>::is_empty() {
        if (!root) return true;
        return false;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    bool
    BSTROOT<key, value, compare, equals>::is_full() {
        return false;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    size_t
    BSTROOT<key, value, compare, equals>::size() {
        return do_size(root);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    BSTROOT<key, value, compare, equals>::do_size(node<key, value>* root) {
        if (!root) {
            return 0;
        } else {
            return 1 + do_size(root->left) + do_size(root->right);
        }
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::clear() {
        do_destruct(this->root);
        this->root = nullptr;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    BSTROOT<key, value, compare, equals>::height() {
        return do_height(root) - 1;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    BSTROOT<key, value, compare, equals>::do_height(node<key, value>* &root) {
        if (!root)
            return 0;
        if (do_height(root->left) > do_height(root->right))
            return 1 + do_height(root->left);
        else
            return 1 + do_height(root->right);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    BSTROOT<key, value, compare, equals>::balance() {
        return do_balance(root);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    int
    BSTROOT<key, value, compare, equals>::do_balance(node<key, value>* &root) {
        if (!root) return 0;
        return do_height(root->left) - do_height(root->right);
    }


    //==============================================================================
    // ------- constructor  

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals>::BSTROOT() {
        root = nullptr;
    }

    //==============================================================================
    // ------- copy constructor 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals>::BSTROOT(BSTROOT& other) {
        root = nullptr;
        other.do_copy(other.root, *this);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::do_copy(node<key, value>* &root, BSTROOT& newer) {
        if (!root) return;
        do_copy(root->left, newer);
        newer.insert(root->node_key, root->node_value);
        do_copy(root->right, newer);
    }

    //==============================================================================
    // ------- copy-assignment operator 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals> &
    BSTROOT<key, value, compare, equals>::operator=(BSTROOT & other) {
        root = nullptr;
        other.do_copy(other.root, *this);
        return *this;
    }

    //==============================================================================
    // ------  move constructor

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals>::BSTROOT(BSTROOT&& other) {
        root = other.root;
        other.root = nullptr;
    }

    //==============================================================================
    // ------- move assignment operator 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals> &
    BSTROOT<key, value, compare, equals>::operator=(BSTROOT && other) {
        root = other.root;
        other.root = nullptr;
        return *this;
    }

    //==============================================================================
    // ------  destructor 

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    BSTROOT<key, value, compare, equals>::~BSTROOT() {
        do_destruct(this->root);
        this->root = nullptr;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::do_destruct(node<key, value> *&node) {
        if (!node) return;
        do_destruct(node->left);
        do_destruct(node->right);
        delete node;
    }

    //============================================================================================================================================================
    // --------- insert()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::insert(key node_key, value node_value) {
        do_insert(root, node_key, node_value);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::do_insert(node<key, value>*& root, key node_key, value node_value) {
        if (!root) {
            root = new node<key, value>(node_key, node_value);
            return;
        } else if (root->node_key == node_key) {
            root->node_value = node_value;
        } else if (compare(node_key, root->node_key)) {
            do_insert(root->left, node_key, node_value);
            rotate_right(root);
        } else {
            do_insert(root->right, node_key, node_value);
            rotate_left(root);
        }
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::rotate_right(node<key, value>* &root) {
        node<key, value>* temp = root;
        root = root->left;
        temp->left = root->right;
        root->right = temp;
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::rotate_left(node<key, value>* &root) {
        node<key, value>* temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
    }


    //==============================================================================
    // --------- remove()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::remove(key node_key) {
        root = do_remove(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    node<key, value>*
    BSTROOT<key, value, compare, equals>::do_remove(node<key, value>* curr, key node_key) {
        if (!curr)throw std::runtime_error("Key not found");
        if (compare(node_key, curr->node_key)) {
            curr->left = do_remove(curr->left, node_key);
        } else if (compare(curr->node_key, node_key)) {
            curr->right = do_remove(curr->right, node_key);
        } else {
            if (curr->left == nullptr) {
                node<key, value> *temp = curr->right;
                delete curr;
                return temp;
            }
            if (curr->right == nullptr) {
                node<key, value> *temp = curr->left;
                delete curr;
                return temp;
            }
            node<key, value> *minNode = curr->right;
            while (minNode->left != nullptr) minNode = minNode->left;
            curr->node_key = minNode->node_key;
            curr->node_value = minNode->node_value;
            curr->right = do_remove(curr->right, minNode->node_key);
        }

        return curr;
    }

    //==============================================================================
    // --------- lookup()

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    value &
    BSTROOT<key, value, compare, equals>::lookup(key node_key) {
        return do_lookup(root, node_key);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    value &
    BSTROOT<key, value, compare, equals>::do_lookup(node<key, value>* &root, key node_key) {
        if (!root) throw std::runtime_error("Key not found");
        else if (equals(root->node_key, node_key)) return root->node_value;
        else if (compare(node_key, root->node_key)) return do_lookup(root->left, node_key);
        else return do_lookup(root->right, node_key);
    }


    //==============================================================================
    // --------- print()  

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::print() {
        do_print(root);
    }

    template<typename key, typename value, bool (*compare) (const key&, const key&), bool (*equals) (const key&, const key&) >
    void
    BSTROOT<key, value, compare, equals>::do_print(node<key, value>* root) {
        if (!root) {
            return;
        }
        do_print(root->left);
        std::cout << root->node_value << std::endl;
        do_print(root->right);
    }
}

#endif /* BSTROOT_H */

