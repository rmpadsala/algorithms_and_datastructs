//
//  detect_loop_link_list.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "detect_loop_link_list.h"

using namespace adt_ns;
using namespace std;

namespace algo_ns {
    
    template <typename T>
    bool DetectLoop::is_cyclic(const Deque<T>& list) {
        Node<T>* first = const_cast<Node<T> *>(list.first());
        Node<T>* second = const_cast<Node<T> *>(list.first());
        
        while (first != nullptr && second != nullptr) {
            first = first->_next;
            // to do: this may carsh
            second = second->_next->_next;
            
            if (first == second) {
                return true;
            }
        }
        return false;
    }
    
    void DetectLoopClient::run_client() {
        adt_ns::Deque<int> list;
        list.insert_back(10);
        list.insert_back(15);
        list.insert_back(20);
        list.insert_back(13);
        list.insert_back(30);
        //list.insert_back(18);
        list.insert_back(12);
        
        std::cout << "List has loop? " << DetectLoop::is_cyclic(list) << endl;
        
        //add cycle
        Node<int>* last = const_cast<Node<int> *>(list.last());
        Node<int>* first = const_cast<Node<int> *>(list.first());
        
        last->_next = new Node<int>(7,
            new Node<int>(6, new Node<int>(5, new Node<int> (4, first->_next))));
        
        std::cout << "List has loop? " << DetectLoop::is_cyclic(list) << endl;
        
//        TODO figure out the crash in linked list dtor
        return;
    }

}
