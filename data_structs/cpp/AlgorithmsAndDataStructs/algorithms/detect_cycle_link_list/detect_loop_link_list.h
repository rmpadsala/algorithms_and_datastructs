//
//  detect_loop_link_list.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/14/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__detect_loop_link_list__
#define __AlgorithmsAndDataStructs__detect_loop_link_list__

#include <iostream>

#include "deque.h"

namespace algo_ns {
    class DetectLoop {
        
    public:
        template <typename T>
        static bool is_cyclic(const adt_ns::Deque<T>& list);
    };
    
    class DetectLoopClient {
    public:
        static void run_client();
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__detect_loop_link_list__) */
