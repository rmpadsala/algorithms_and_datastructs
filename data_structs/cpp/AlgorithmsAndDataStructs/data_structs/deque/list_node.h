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
    
    template <typename T>
    class Node {
    public:
        explicit Node(T value, Node<T>* next = nullptr)
        : _value(value)
        , _next(next)
        {}
        
        ~Node() {}
        
        T _value;
        Node<T> * _next;
        friend std::ostream& operator << (std::ostream& stream, const Node<T>& node) {
            stream << node._value;
            return stream;
        }
    };
}

#endif
