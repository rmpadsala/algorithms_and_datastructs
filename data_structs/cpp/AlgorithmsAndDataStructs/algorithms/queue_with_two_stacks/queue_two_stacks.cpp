//
//  queue_two_stacks.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "queue_two_stacks.h"

namespace algo_ns {
    template <typename T>
    QueueTwoStacks<T>::QueueTwoStacks() {
    }
    
    template <typename T>
    QueueTwoStacks<T>::~QueueTwoStacks<T>() {
    }
    
    template <typename T>
    void QueueTwoStacks<T>::enque(T item) {
        _one.push(item);
    }
    
    template <typename T>
    T QueueTwoStacks<T>::deque() {
        if (_two.empty()) {
            move_stack(_one, _two);
        }
        
        if (!_two.empty()) {
            T item = _two.top();
            _two.pop();
            return item;
        }
        
        std::cout << "queue is empty" << std::endl;
        return 0;
    }
    
    template <typename T>
    void QueueTwoStacks<T>::move_stack(std::stack<T>& source, std::stack<T>& dest) {
        while (!source.empty()) {
            dest.push(source.top());
            source.pop();
        }
    }
    
    template <typename T>
    void QueueTwoStacks<T>::print_contents(const std::stack<T>& stack) const {
        std::stack<T> to_print(stack);
        while (!to_print.empty()) {
            std::cout << to_print.top() << ", ";
            to_print.pop();
        }
        std::cout << std::endl;
    }
    
    void QueueTwoStacksClient::run_client() {
        QueueTwoStacks<int> q;
        q.deque();
        q.enque(10);
        q.enque(20);
        q.enque(30);
        q.enque(40);
        q.enque(50);
        q.enque(60);
 
        // should print 10 and 20
        std::cout << q.deque() << std::endl;
        std::cout << q.deque() << std::endl;
        
        q.enque(70);
        q.enque(80);
        
        // should print 30 and 40
        std::cout << q.deque() << std::endl;
        std::cout << q.deque() << std::endl;
        
        std::cout << "Inbox" << std::endl;
        q.print_contents(q.inbox());
        std::cout << "Outbox" << std::endl;
        q.print_contents(q.outbox());
    }
}
