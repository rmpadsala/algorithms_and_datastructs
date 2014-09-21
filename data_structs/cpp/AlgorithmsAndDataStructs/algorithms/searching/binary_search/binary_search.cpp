//
//  binary_search.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/16/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "binary_search.h"

using namespace std;

namespace algo_ns {
    
    template <typename T>
    bool BinarySearch<T>::search(T key, T collection[], T high, T low) {
        
        while (high >= low) {
            int mid = (high + low)/2;
        
            if (key == collection[mid]) {
                return true;
            } else if (key > collection[mid]) {
                return search(key, collection, high, mid+1);
            } else {
                return search(key, collection, mid-1, low);
            }
        }
        
        return false;
    }
    
    void BinarySearchClient::run_client() {
        int collection[] = { 1,2,3,4,5,6,7,8,20,21,23,35,45,56 };
        //int collection[] =  { 56, 45, 34, 23, 34, 8, 7, 6, 5, 4 };
        int high = sizeof(collection)/sizeof(int);
        int low = 0;
        
        std::cout << "3 present in collection? " << BinarySearch<int>::search(3, collection, high, low) << endl;
        std::cout << "23 present in collection? " << BinarySearch<int>::search(23, collection, high, low) << endl;
        std::cout << "300 present in collection? " << BinarySearch<int>::search(300, collection, high, low) << endl;
        std::cout << "35 present in collection? " << BinarySearch<int>::search(35, collection, high, low) << endl;
        std::cout << "350 present in collection? " << BinarySearch<int>::search(350, collection, high, low) << endl;
    }
}
