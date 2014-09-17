//
//  binary_search.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/16/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__binary_search__
#define __AlgorithmsAndDataStructs__binary_search__

#include <iostream>
#include <vector>

namespace algo_ns {
    
    template <typename T>
    class BinarySearch {
    public:
        static bool search(T item, T collection[], T high, T low);
    };
    
    class BinarySearchClient {
    public:
        static void run_client();
    };
    
}


#endif /* defined(__AlgorithmsAndDataStructs__binary_search__) */
