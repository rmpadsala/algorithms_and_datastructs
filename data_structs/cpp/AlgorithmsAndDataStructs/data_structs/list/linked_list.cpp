//
//  LinkedList.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "linked_list.h"

using namespace std;

namespace list_ns {
    LinkedList::LinkedList()
    : _head(nullptr)
    , _tail(nullptr)
    , _size(0)
    {}
    
    LinkedList::~LinkedList()  {
        clear();
    }
    
    bool LinkedList::empty() const {
        return _head == nullptr;
    }
    
    void LinkedList::insert(int value) {
        insert_back(value);
    }
    
    void LinkedList::insert_back(int value) {
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
    
    void LinkedList::insert_front(int value) {
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
    
    void LinkedList::remove_front() {
        if (empty() == false) {
            Node* front = _head;
            _head = _head->_next;
            delete front;
            --_size;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    void LinkedList::remove_back() {
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
    
    void LinkedList::clear() {
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
    
    std::ostream& operator << (std::ostream& stream, const LinkedList& list) {
        const Node* node = list.first();
        while(node) {
            stream << *node << ", ";
            node = node->_next;
        }
        stream << endl;
        return stream;
    }
}