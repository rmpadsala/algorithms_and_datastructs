//
//  queue_two_stacks.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__queue_two_stacks__
#define __AlgorithmsAndDataStructs__queue_two_stacks__

#include <iostream>
#include <stack>

namespace algo_ns {
    
    template <typename T>
    class QueueTwoStacks {
    public:
        QueueTwoStacks();
        ~QueueTwoStacks();
        
        //interface
        void enque(T item);
        T deque();
        
        const std::stack<T>& inbox() const { return _one; }
        const std::stack<T>& outbox() const { return _two; }

        void print_contents(const std::stack<T>& stack) const;
    private:
        void move_stack(std::stack<T>& source, std::stack<T>& dest);
    
        std::stack<T> _one;
        std::stack<T> _two;
    };
    
    class QueueTwoStacksClient {
    public:
        static void run_client();
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__queue_two_stacks__) */
