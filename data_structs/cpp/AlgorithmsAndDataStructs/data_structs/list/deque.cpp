//
//  Deque.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "deque.h"

using namespace std;

namespace adt_ns {
    Deque::Deque()
    : _head(nullptr)
    , _tail(nullptr)
    , _size(0)
    {}
    
    Deque::~Deque()  {
        clear();
    }
    
    bool Deque::empty() const {
        return _head == nullptr;
    }
    
    void Deque::insert(int value) {
        insert_back(value);
    }
    
    void Deque::insert_back(int value) {
        Node *node = new Node(value);
        if (empty()) {
            _head = node;
            _tail = node;
        } else {
            _tail->_next = node;
            _tail = node;
        }
        ++_size;
    }
    
    void Deque::insert_front(int value) {
        Node *node = new Node(value);
        if (empty()) {
            _head = node;
            _tail = node;
        } else {
            node->_next = _head;
            _head = node;
        }
        ++_size;
    }
    
    void Deque::remove_front() {
        if (empty() == false) {
            Node* front = _head;
            _head = _head->_next;
            delete front;
            --_size;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    void Deque::remove_back() {
        if (empty() == false) {
            if (_head->_next == nullptr) {
                delete _head;
                _head = nullptr;
            } else {
                Node* prev = _head;
                Node* current = _head->_next;
                
                while (current->_next != nullptr) {
                    prev = current;
                    current = current->_next;
                }
                
                prev->_next = current->_next;
                _tail = prev;
                delete current;
            }
            --_size;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    void Deque::clear() {
        Node * node = _head;
        while (node) {
            node = node->_next;
            _head = node;
            delete node;
            --_size;
        }
    }
    
    std::ostream& operator << (std::ostream& stream, const Node& node) {
        stream << node._value;
        return stream;
    }
    
    std::ostream& operator << (std::ostream& stream, const Deque& list) {
        const Node* node = list.first();
        while(node) {
            stream << *node << ", ";
            node = node->_next;
        }
        stream << endl;
        return stream;
    }
}