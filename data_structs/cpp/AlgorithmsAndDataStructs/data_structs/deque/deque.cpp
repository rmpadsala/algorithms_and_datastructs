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
    
    template <typename T>
    Deque<T>::Deque()
    : _head(nullptr)
    , _tail(nullptr)
    , _size(0)
    {}
    
    template <typename T>
    Deque<T>::~Deque()  {
        clear();
    }
    
    template <typename T>
    bool Deque<T>::empty() const {
        return _head == nullptr;
    }
    
    template <typename T>
    void Deque<T>::insert_back(T value) {
        Node<T> *node = new Node<T>(value);
        if (empty()) {
            _head = node;
            _tail = node;
        } else {
            _tail->_next = node;
            _tail = node;
        }
        ++_size;
    }
    
    template <typename T>
    void Deque<T>::insert_front(T value) {
        Node<T> *node = new Node<T>(value);
        if (empty()) {
            _head = node;
            _tail = node;
        } else {
            node->_next = _head;
            _head = node;
        }
        ++_size;
    }
    
    template <typename T>
    void Deque<T>::remove_front() {
        if (empty() == false) {
            Node<T>* front = _head;
            _head = _head->_next;
            delete front;
            --_size;
        } else {
            cout << "List is empty" << endl;
        }
    }
    
    template <typename T>
    void Deque<T>::remove_back() {
        if (empty() == false) {
            if (_head->_next == nullptr) {
                delete _head;
                _head = nullptr;
            } else {
                Node<T>* prev = _head;
                Node<T>* current = _head->_next;
                
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
    
    template <typename T>
    void Deque<T>::clear() {
        Node<T> * node = _head;
        while (node) {
            node = node->_next;
            _head = node;
            delete node;
            --_size;
        }
    }
    
    void DequeClient::run_client() {
        cout << "**********************************************" << endl;
        cout << "************RUNNING DEQUE CLIENT**************" << endl;
        cout << "**********************************************" << endl;
        
        // Linked list test;
        Deque<int> list;
        
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