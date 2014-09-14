//
//  Node.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef AlgorithmsAndDataStructs_Node_h
#define AlgorithmsAndDataStructs_Node_h

namespace adt_ns {
    
    class Node {
    public:
        explicit Node(int value, Node* next = nullptr)
        : _value(value)
        , _next(next)
        {}
        
        ~Node() {}
        
        int _value;
        Node * _next;
        friend std::ostream& operator << (std::ostream& stream, const Node& node);
    };
}

#endif
