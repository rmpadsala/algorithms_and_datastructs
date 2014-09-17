//
//  anagram.h
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/16/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#ifndef __AlgorithmsAndDataStructs__anagram__
#define __AlgorithmsAndDataStructs__anagram__

#include <iostream>

namespace algo_ns {
    
    class AnagramClient {
        static bool is_anagram(const std::string& one, const std::string& two);
    public:
        static void run_client();
    };
}

#endif /* defined(__AlgorithmsAndDataStructs__anagram__) */
