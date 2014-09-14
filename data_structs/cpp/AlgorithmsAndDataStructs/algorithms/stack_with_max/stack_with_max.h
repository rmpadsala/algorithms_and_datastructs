//
//  stack_with_max.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__stack_with_max__
#define __AlgorithmsAndDataStructs__stack_with_max__

#include <iostream>
#include <stack>

namespace algo_ns {
    template <typename T>
    class StackWithMax {
    public:
        StackWithMax(): _count(0) {}
        ~StackWithMax() {}
        
        void push(T item);
        T top() const;
        void pop();
        T max() const;
        size_t size() const;
        
        friend std::ostream& operator << (std::ostream& stream, const StackWithMax<T>& container) {
            stream << "inbox stack: ";
            
            std::stack<T> inbox_print(container._inbox);
            while (!inbox_print.empty()) {
                std::cout << inbox_print.top() << ", ";
                inbox_print.pop();
            }
            std::cout << std::endl;
            stream << "max stack: ";
            
            std::stack<T> max_print(container._max);
            while (!max_print.empty()) {
                std::cout << max_print.top() << ", ";
                max_print.pop();
            }
            std::cout << std::endl;
            
            return stream;
        }
        
    private:
        void compare_and_push(T item);
        
        size_t _count;
        std::stack<T> _inbox;
        std::stack<T> _max;
    };
    
    class StackWithMaxClient {
    public:
        static void run_client();
    };
    
    template <typename T>
    size_t StackWithMax<T>::size() const {
        return _count;
    }
}


#endif /* defined(__AlgorithmsAndDataStructs__stack_with_max__) */
