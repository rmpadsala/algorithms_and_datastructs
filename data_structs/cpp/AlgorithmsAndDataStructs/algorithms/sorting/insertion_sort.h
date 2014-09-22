//
//  insertion_sort.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/21/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__insertion_sort__
#define __AlgorithmsAndDataStructs__insertion_sort__

#include <stdio.h>
#include <vector>

namespace algo_ns {
    class InsertionSort {
    public:
        static void sort(std::vector<int>& collection);
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__insertion_sort__) */
