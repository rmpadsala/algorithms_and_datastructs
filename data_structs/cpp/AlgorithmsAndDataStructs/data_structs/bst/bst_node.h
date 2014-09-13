//
//  tree_node.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef AlgorithmsAndDataStructs_tree_node_h
#define AlgorithmsAndDataStructs_tree_node_h

namespace bst_ns {
    class BSTNode {
    public:
        BSTNode(int value, BSTNode* left=nullptr, BSTNode* right=nullptr)
        : _value(value)
        , _left(left)
        , _right(right)
        {}

        ~BSTNode() {
            _left = nullptr;
            _right = nullptr;
        }
        
        int _value;
        BSTNode* _left;
        BSTNode* _right;
    };
}

#endif
