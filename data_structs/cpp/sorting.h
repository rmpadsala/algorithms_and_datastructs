//
//  sorting.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/21/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef AlgorithmsAndDataStructs_sorting_h
#define AlgorithmsAndDataStructs_sorting_h

#include <iostream>

#include "selection_sort.h"

namespace algo_ns {
    
    template <typename SortingStrategyT>
    class SortingImpl {
    public:
        static void sort(std::vector<int>& collection) {
            SortingStrategyT::sort(collection);
        }
    };
    
    class SortingClient {
    public:
        static void run_client() {
            std::cout << "Running selection sort...." << std::endl;
            
            std::vector<int> collection = { 10, 22, 13, 23, 48, 42, 95 };
            
            std::cout << "Collection before running sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            SortingImpl<SelectionSort>::sort(collection);
            
            std::cout << "Collection after running sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            std::cout << "End selection sort....." << std::endl;
        }
    };
}

#endif
