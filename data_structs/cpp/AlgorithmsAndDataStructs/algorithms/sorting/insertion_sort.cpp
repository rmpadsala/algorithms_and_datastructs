//
//  insertion_sort.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/21/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "insertion_sort.h"


namespace algo_ns {
    
    void InsertionSort::sort(std::vector<int>& collection) {
        int i = 0;
        for (; i < collection.size()-1; ++i) {
            int j = i;
            for(; j >= 0; --j) {
                if (collection[j] < collection[j-1]) {
                    int temp = collection[j-1];
                    collection[j-1] = collection[j];
                    collection[j] = temp;
                } else break;
            }
        }
    }
}