//
//  bst.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include <vector>

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
    
    void BST::print_in_order() const {
        print_in_order(_root);
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
        cout << "Node key = " << node->_value;
        
        if (leafnode(node)) {
            cout << ", leaf node";
        } else {
            if (node->_left != nullptr) {
                cout << ", L: " << node->_left->_value;
            }
            if (node->_right != nullptr) {
                cout << ", R: " << node->_right->_value;
            }
        }
        cout << endl;
    }
    
    // private methods
    void BST::destroy_node(BSTNode* node) {
        --_count;
        delete node;
        node = nullptr;
    }
    
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
    
    void BST::print_in_order(BSTNode* node) const {
        if (empty()) {
            cout << "Tree is currently empty" << endl;
        } else {
            if (node->_left != nullptr) {
                print_in_order(node->_left);
            }
            cout << node->_value << " ";
            if (node->_right != nullptr) {
                print_in_order(node->_right);
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
        // case - 1 remove leaf node
        if (leafnode(nodeToDelete)) {
            (leftChild) ? parent->_left = nullptr : parent->_right = nullptr;
            destroy_node(nodeToDelete);
        } else if (nodeToDelete->_right == nullptr) {
            // case - 2 right tree is null
            (leftChild) ? parent->_left = nodeToDelete->_left : parent->_left = nodeToDelete->_right;
            destroy_node(nodeToDelete);
        } else if (nodeToDelete->_left == nullptr) {
            // case - 3 left tree is null
            (leftChild) ? parent->_right = nodeToDelete->_left : parent->_right = nodeToDelete->_right;
            destroy_node(nodeToDelete);
        } else {
            // case - 4 node has both left and right subtree
            // find largest node in left subtree, delete the node and
            // swap the value with node to be deleted
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
    
    void BSTClient::run_client() {
        cout << "**********************************************" << endl;
        cout << "*************RUNNING BST CLIENT***************" << endl;
        cout << "**********************************************" << endl;
        
        BST bst;
        vector<int> items = { 50, 25, 35, 17, 37, 32, 20, 16, 19, 8, 70, 57, 80, 52, 59, 53, 62, 75, 85, 73, 77, 89 };
        
        for_each(items.begin(), items.end(), [&](int item) {
            bst.insert(item);
        });
        
        // should print 8 16 17 19 20 25 32 35 37 50 52 53 57 59 62 70 73 75 77 80 85 89
        bst.print_in_order();
        std::cout << "Total nodes " << bst.count() << endl;
        
        for_each(items.begin(), items.end(), [&](int item) {
            bst.print_children(bst.find(item));
        });
        
        // updating items vector is just for validation purpose
        bst.remove(89); items.erase(std::remove(items.begin(), items.end(), 89), items.end());
        bst.remove(16); items.erase(std::remove(items.begin(), items.end(), 16), items.end());
        bst.remove(59); items.erase(std::remove(items.begin(), items.end(), 59), items.end());
        bst.remove(57); items.erase(std::remove(items.begin(), items.end(), 57), items.end());
        bst.remove(50); items.erase(std::remove(items.begin(), items.end(), 50), items.end());
        
        // should print: 8 17 19 20 25 32 35 37 52 53 62 70 73 75 77 80 85
        bst.print_in_order();
        std::cout << "Total nodes " << bst.count() << endl;
        
        for_each(items.begin(), items.end(), [&](int item) {
            bst.print_children(bst.find(item));
        });
    }
}