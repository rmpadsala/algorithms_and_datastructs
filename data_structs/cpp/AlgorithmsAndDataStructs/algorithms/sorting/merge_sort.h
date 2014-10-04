//
//  merge_sort.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 10/2/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__merge_sort__
#define __AlgorithmsAndDataStructs__merge_sort__

#include <stdio.h>
#include <vector>

namespace algo_ns {
    class MergeSort {
    public:
        static void sort(std::vector<int>& collection);
        
    private:
        static void sort(std::vector<int>&collection, std::vector<int>& aux_ary,
                         size_t low, size_t high);
        
        static void merge(std::vector<int>& collection,
                          std::vector<int>& aux_ary,
                          size_t low, size_t mid, size_t high);
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__merge_sort__) */
