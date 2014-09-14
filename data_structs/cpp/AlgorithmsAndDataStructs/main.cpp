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

using namespace std;
using namespace adt_ns;
using namespace bst_ns;
using namespace algo_ns;

int main(int argc, const char * argv[])
{
    DequeClient::run_client();
    
    BSTClient::run_client();
    
    QueueTwoStacksClient::run_client();
    
    return 0;
}

