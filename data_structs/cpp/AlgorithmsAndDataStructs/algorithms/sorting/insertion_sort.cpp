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
        for (auto i=0; i < collection.size(); ++i) {
            auto value = collection[i];
            auto lowest_index = i;
            
            while (lowest_index > 0 && collection[lowest_index-1] > value) {
                collection[lowest_index] = collection[lowest_index-1];
                lowest_index--;
            }
            
            collection[lowest_index] = value;
        }
    }
}