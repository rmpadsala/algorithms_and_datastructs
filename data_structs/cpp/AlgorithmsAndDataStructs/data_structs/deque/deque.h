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
    
    template <typename T>
    class Deque {
    public:
        Deque();
        ~Deque();
        // Todo....copy ctor and assignment operator
        
        bool empty() const;
        void insert_front(T value);
        void insert_back(T value);
        void remove_front();
        void remove_back();
        void clear();
        
        inline const Node<T>* first() const;
        inline const Node<T>* last() const;
        inline size_t length() const;
        
        friend std::ostream& operator << (std::ostream& stream, const Deque<T>& list) {
            const Node<T>* node = list.first();
            while(node) {
                stream << *node << ", ";
                node = node->_next;
            }
            stream << std::endl;
            return stream;
        }
        
    private:
        Node<T>* _head;
        Node<T>* _tail;
        size_t _size;
    };
    
    template <typename T>
    size_t Deque<T>::length() const {
        return _size;
    }
    
    template <typename T>
    const Node<T>* Deque<T>::first() const {
        return _head;
    }
    
    template <typename T>
    const Node<T>* Deque<T>::last() const {
        return _tail;
    }
    
    class DequeClient {
    public:
        static void run_client();
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__Deque__) */
