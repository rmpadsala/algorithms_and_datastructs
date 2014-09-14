//
//  Deque.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__Deque__
#define __AlgorithmsAndDataStructs__Deque__

#include <iostream>

#include "list_node.h"

namespace adt_ns {
    
    class Deque {
    public:
        Deque();
        ~Deque();
        // Todo....copy ctor and assignment operator
        
        bool empty() const;
        void insert (int value);
        void insert_front(int value);
        void insert_back(int value);
        void remove_front();
        void remove_back();
        void clear();
        
        inline const Node* first() const;
        inline const Node* last() const;
        inline size_t length() const;
        
        friend std::ostream& operator << (std::ostream& stream, const Deque& list);
        
    private:
        Node* _head;
        Node* _tail;
        size_t _size;
    };
    
    size_t Deque::length() const {
        return _size;
    }
    
    const Node* Deque::first() const {
        return _head;
    }
    
    const Node* Deque::last() const {
        return _tail;
    }
}

#endif /* defined(__AlgorithmsAndDataStructs__Deque__) */
