//
//  bst.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__bst__
#define __AlgorithmsAndDataStructs__bst__

#include <iostream>

#include "bst_node.h"

namespace bst_ns {
    class BST {
    public:
        BST();
        ~BST();
        
        void clear();
        void insert(int value);
        BSTNode* find(int value) const;
        void remove(int value);
        
        //todo
        //print childern
        
        /// helper functions
        inline size_t count() const;
        inline bool empty() const;
        void print_in_order() const;
        BSTNode* find_largest(BSTNode* node) const;
        void print_children(BSTNode* node) const;
        
    private:
        BSTNode* _root;
        int _count;
        
        void insert(int value, BSTNode* node);
        void remove(int value, BSTNode* parent);
        BSTNode* find(int value, BSTNode* node) const;
        void delete_node(BSTNode* nodeToDelete, BSTNode* parent, bool leftChild);
        void destroy_node(BSTNode* node);
        void clear(BSTNode* node);
        
        /// helper functions
        inline bool leafnode(BSTNode* node) const;
        void print_in_order(BSTNode* node) const;
        BSTNode* createnode(int value);
    };
    
    inline size_t BST::count() const {
        return _count;
    }
    
    inline bool BST::empty() const {
        return _root == nullptr;
    }
    
    inline bool BST::leafnode(BSTNode* node) const {
        return node->_left == nullptr && node->_right == nullptr;
    }
    
    class BSTClient {
    public:
        static void run_client();
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__bst__) */
