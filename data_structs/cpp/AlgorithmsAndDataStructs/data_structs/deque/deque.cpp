//
//  Deque.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include <vector>
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
    
    void DequeClient::run_client() {
        cout << "**********************************************" << endl;
        cout << "************RUNNING DEQUE CLIENT**************" << endl;
        cout << "**********************************************" << endl;
        
        // Linked list test;
        Deque list;
        
        //should print list is empty
        list.remove_front();
        //should print list is empty
        list.remove_back();
        
        vector<int> back = { 10, 12, 45, 17, 39, 20, 25, 28 };
        
        for_each(back.begin(), back.end(), [&](int item) {
            list.insert_back(item);
        });
        
        vector<int> front = { -5, -65, 0, 1, 2, 55, 7, 96 };
        
        for_each(front.begin(), front.end(), [&](int item) {
            list.insert_front(item);
        });
        
        //should print 96, 7, 55, 2, 1, 0, -65, -5, 10, 12, 45, 17, 39, 20, 25, 28
        cout << "list contents: " << list << ", size: " << list.length() << endl;
        
        list.remove_front();
        list.remove_back();
        list.remove_front();
        
        //should print 55, 2, 1, 0, -65, -5, 10, 12, 45, 17, 39, 20, 25
        cout << "list contents: " << list << ", size: " << list.length() << endl;
    }
}