//
//  bst.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "bst.h"

using namespace std;

namespace bst_ns {
    
    BST::BST()
        : _root(nullptr)
        , _count(0)
    {}
    
    BST::~BST() {
        clear();
    }
    
    void BST::clear() {
        clear(_root);
    }

    void BST::clear(BSTNode* node) {
        if (node != nullptr) {
            if (leafnode(node)) {
                delete node;
                --_count;
            }
            clear(node->_left);
            clear(node->_right);
        }
    }
    
    void BST::insert(int value) {
        insert(value, _root);
    }
    
    void BST::printInOrder() const {
        printInOrder(_root);
        cout << endl;
    }
    
    BSTNode* BST::find(int value) const {
        return find(value, _root);
    }
    
    void BST::remove(int value) {
        remove(value, _root);
    }
    
    BSTNode* BST::find_largest(BSTNode* node) const {
        while (node->_right) {
            node = node->_right;
        }
        return node;
    }
    
    void BST::print_children(BSTNode* node) const {
        cout << "node key = " << node->_value << endl;;
        
        if (leafnode(node)) {
            cout << "node has no child" << endl;
        } else {
            if (node->_left != nullptr) {
                cout << "left child = " << node->_left->_value << endl;
            }
            if (node->_right != nullptr) {
                cout << "right child = " << node->_right->_value << endl;
            }
        }
    }
    
    // private methods
    
    BSTNode* BST::createnode(int value) {
        // use smart_ptrs instead of raw ptrs
        _count++;
        return new BSTNode(value);
    }
    
    void BST::insert(int value, BSTNode* node) {
        if (empty()) {
            _root = createnode(value);
        } else if (value < node->_value) {
            // left subtree
            if (node->_left != nullptr) {
                insert(value, node->_left);
            } else {
                node->_left = createnode(value);
            }
        } else if (value > node->_value) {
            // right subtree
            if (node->_right != nullptr) {
                insert(value, node->_right);
            } else {
                node->_right = createnode(value);
            }
        } else {
            cout << "Key already present." << endl;
        }
    }
    
    void BST::printInOrder(BSTNode* node) const {
        if (empty()) {
            cout << "Tree is currently empty" << endl;
        } else {
            if (node->_left != nullptr) {
                printInOrder(node->_left);
            }
            cout << node->_value << " ";
            if (node->_right != nullptr) {
                printInOrder(node->_right);
            }
        }
    }
    
    BSTNode* BST::find(int value, BSTNode* node) const {
        if (node != nullptr) {
            if (node->_value == value) {
                return node;
            } else {
                if (value < node->_value) {
                    return find(value, node->_left);
                } else if (value > node->_value) {
                    return find(value, node->_right);
                }
            }
        }
        return nullptr;
    }
    
    void BST::delete_node(BSTNode* nodeToDelete, BSTNode* parent, bool leftChild) {
        cout << "Ready to delete node with value = " << nodeToDelete->_value << endl;
        
        // case - 1 remove leaf node
        if (leafnode(nodeToDelete)) {
            (leftChild) ? parent->_left = nullptr : parent->_right = nullptr;
            --_count;
            delete nodeToDelete;
        } else if (nodeToDelete->_right == nullptr) {
            // case - 2 right tree is null
            (leftChild) ? parent->_left = nodeToDelete->_left : parent->_left = nodeToDelete->_right;
            --_count;
            delete nodeToDelete;
        } else if (nodeToDelete->_left == nullptr) {
            // case - 3 left tree is null
            (leftChild) ? parent->_right = nodeToDelete->_left : parent->_right = nodeToDelete->_right;
            --_count;
            delete nodeToDelete;
        } else {
            // case - 4 node has both left and right subtree
            BSTNode* largest_node = find_largest(nodeToDelete->_left);
            remove(largest_node->_value, nodeToDelete);
            nodeToDelete->_value = largest_node->_value;
        }
    }
    
    void BST::remove(int value, BSTNode* node) {
        if (empty() == false) {
            if (value == _root->_value) {
                // for root node no parents, so pass nullptr
                delete_node(_root, nullptr, false);
            } else {
                if (value < node->_value && node->_left != nullptr) {
                    value == node->_left->_value ?
                        delete_node(node->_left, node, true) :
                        remove(value, node->_left);
                } else if (value > node->_value && node->_right != nullptr) {
                    value == node->_right->_value ?
                        delete_node(node->_right, node, false) :
                        remove(value, node->_right);
                } else {
                    cout << "Key not found." << endl;
                }
            }
        } else {
            cout << "Tree is empty." << endl;
        }
    }
}