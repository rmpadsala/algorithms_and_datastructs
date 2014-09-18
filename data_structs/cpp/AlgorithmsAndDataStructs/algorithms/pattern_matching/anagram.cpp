//
//  anagram.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/16/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include "anagram.h"

#include <map>

using namespace std;

namespace algo_ns {
    
    void AnagramClient::run_client() {
        cout << "viral, liar is_anagram = " << (is_anagram("viral", "liar") ? "true" : "false") << std::endl;
        cout << "creative, reactive is_anagram = " << (is_anagram("creative", "reactive") ? "true" : "false") << std::endl;
        cout << "add, dad is_anagram = " << (is_anagram("add", "dad") ? "true" : "false") << std::endl;
        cout << "aaca, aca is_anagram = " << (is_anagram("aaca", "aca") ? "true" : "false") << std::endl;
    }
    
    bool AnagramClient::is_anagram(const std::string& one, const std::string& two) {
        if (one.length() != two.length()) return false;
        
        typedef std::map<char, int> MapT;
        MapT map;
        
        for_each(one.begin(), one.end(), [&](char c) {
            MapT::iterator it = map.find(c);
            
            if (it != map.end()) {
                map[c] = ++it->second;
            } else {
                map.insert(std::make_pair(c, 1));
            }
        });
        
        for_each(two.begin(), two.end(), [&](char c) {
            MapT::iterator it = map.find(c);
            
            if (it != map.end()) {
                if (--it->second == 0) {
                    map.erase(it);
                }
            } else {
                map.insert(std::make_pair(c, 1));
            }
        });
        
        return map.empty();
    }
}