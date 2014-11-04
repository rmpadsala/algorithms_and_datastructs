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
#include "insertion_sort.h"
#include "merge_sort.h"

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
            
            std::vector<int> collection = { 10, 22, 13, 23, 23, 48, 42, 95, 8, 8, 6 };
            
            std::cout << "Collection before running selection sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            SortingImpl<SelectionSort>::sort(collection);
            
            std::cout << "Collection after running selection sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            // using built-in random generator:
            std::srand ( unsigned ( std::time(0) ) );
            std::random_shuffle ( collection.begin(), collection.end() );

            std::cout << "Collection before running insertion sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            SortingImpl<InsertionSort>::sort(collection);
            
            std::cout << "Collection after running insertion sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            
            // using built-in random generator:
            std::srand ( unsigned ( std::time(0) ) );
            std::random_shuffle ( collection.begin(), collection.end() );
            
            std::cout << "Collection before running merge sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
            SortingImpl<MergeSort>::sort(collection);
            
            std::cout << "Collection after running merge sort..." << std::endl;
            
            std::for_each(collection.begin(), collection.end(), [](int i) {
                std::cout << i << ",";
            });
            std::cout << std::endl;
            
        }
    };
}

#endif
