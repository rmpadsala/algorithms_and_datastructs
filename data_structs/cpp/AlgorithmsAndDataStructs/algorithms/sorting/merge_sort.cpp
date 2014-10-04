//
//  merge_sort.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 10/2/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "merge_sort.h"

namespace algo_ns {
    
    void MergeSort::sort(std::vector<int>& collection) {
        std::vector<int> aux_ary(collection.size());
        sort(collection, aux_ary, 0, collection.size()-1);
    }
    
    void MergeSort::sort(std::vector<int>&collection, std::vector<int>& aux_ary,
                     size_t low, size_t high) {
        
        if (low >= high) return;
        
        auto mid = low + (high - low)/2;
        sort(collection, aux_ary, low, mid);
        sort(collection, aux_ary, mid+1, high);
        merge(collection, aux_ary, low, mid, high);
    }
    
    void MergeSort::merge(std::vector<int>& collection,
                      std::vector<int>& aux_ary,
                      size_t low, size_t mid, size_t high) {
        
        //copy collection to aux_ary
        for (auto i = low; i <= high; ++i) {
            aux_ary[i] = collection[i];
        }
        
        auto i = low;
        auto j = mid+1;
        
        for (auto k=low; k <= high; k++) {
            if (i > mid) collection[k] = aux_ary[j++];
            else if(j > high) collection[k] = aux_ary[i++];
            else if(aux_ary[i] < aux_ary[j]) collection[k] = aux_ary[i++];
            else collection[k] = aux_ary[j++];
        }
    }

}
