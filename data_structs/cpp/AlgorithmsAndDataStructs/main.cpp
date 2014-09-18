//
//  main.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include <iostream>

#include "deque.h"
#include "bst.h"
#include "queue_two_stacks.h"
#include "stack_with_max.h"
#include "anagram.h"
#include "binary_search.h"

#include <map>

using namespace std;
using namespace adt_ns;
using namespace bst_ns;
using namespace algo_ns;

int partition(int* a, int start, int end) {
    int pivot = a[end];
    int p_index = 0;
    
    for (int i=0; i<end; ++i) {
        if (a[i] <= pivot) {
            std::swap(a[i], a[p_index]);
            p_index += 1;
        }
    }
    std::swap(a[p_index], a[end]);
    return p_index;
}

void quick_sort(int *a, int start, int end) {
    if (start < end) {
        int pivot_index = partition(a, start, end);
        quick_sort(a, 0, pivot_index-1);
        quick_sort(a, pivot_index+1, end);
    }
}

int main(int argc, const char * argv[])
{
    DequeClient::run_client();
    
    BSTClient::run_client();
    
    QueueTwoStacksClient::run_client();
    
    StackWithMaxClient::run_client();
    
    AnagramClient::run_client();
    
    BinarySearchClient::run_client();
    
    int a[] = { 12, 2, 4,6, 7, 9, 10, 11 };
    quick_sort(a, 0, sizeof(a)/sizeof(int));
    
    std::for_each(a, a+sizeof(a)/sizeof(int), [&](int c) {
        std::cout << c << ",";
    });
    
    std::cout << std::endl;
    
    return 0;
}
