//
//  SelectionSort.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/21/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "selection_sort.h"
#include <utility>

namespace algo_ns {
    
    void SelectionSort::sort(std::vector<int>& collection) {
        int i=0;
        for (; i < collection.size()-1; ++i) {
            int min = i;
            
            int j = i+1;
            for (; j < collection.size(); ++j) {
                if (collection[j] < collection[min]) {
                    min = j;
                }
            }
            
            if (min != i) {
                int temp = collection[min];
                collection[min] = collection[i];
                collection[i] = temp;
            }
        }
    }
}
