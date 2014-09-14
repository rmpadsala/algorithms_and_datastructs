//
//  stack_with_max.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include <vector>
#include "stack_with_max.h"

using namespace std;

namespace algo_ns {
    
    template <typename T>
    void StackWithMax<T>::push(T item) {
        
        if (_inbox.empty()) {
            _max.push(item);
        } else {
            compare_and_push(item);
        }
        _inbox.push(item);
        ++_count;
    }
    
    template <typename T>
    void StackWithMax<T>::pop() {
        if (_inbox.empty())
            cout << "Stack empty" << endl;
        else {
            _inbox.pop();
            _max.pop();
        }
    }
    
    template <typename T>
    T StackWithMax<T>::top() const {
        if (!_inbox.empty()) {
            return _inbox.top();
        }
        
        cout << "Stack empty" << endl;
        return 0;
    }
    
    template <typename T>
    T StackWithMax<T>::max() const {
        if (!_max.empty())
            return _max.top();
        
        cout << "Stack empty" << endl;
        return 0;
    }
    
    template <typename T>
    void StackWithMax<T>::compare_and_push(T item) {
        if (_max.top() >= item) {
            _max.push(_max.top());
        } else {
            _max.push(item);
        }
    }
    
    void StackWithMaxClient::run_client() {
        cout << "**********************************************" << endl;
        cout << "********RUNNING Stack with MAX CLIENT*********" << endl;
        cout << "**********************************************" << endl;
        
        StackWithMax<int> container;
        
        vector<int> items = { 10, 20, 12, 8, 9, 25, 18 };
        for_each(items.begin(), items.end(), [&] (int item) {
            container.push(item);
        });
        
        //should print
        //inbox stack: 18, 25, 9, 8, 12, 20, 10,
        //max stack: 25, 25, 20, 20, 20, 20, 10,
        cout << container << endl;
        
        container.push(27);
        container.push(35);
        
        //should print 35
        cout << "max: " << container.max() << endl;
        
        container.pop();
        container.push(23);
        container.pop();
        container.pop();
        
        //should print 25
        cout << "max: " << container.max() << endl;
    }
}