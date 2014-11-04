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
#include "detect_loop_link_list.h"
#include "sorting.h"

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
    
    DetectLoopClient::run_client();
    
    SortingClient::run_client();
    
//    int a[] = { 12, 2, 4,6, 7, 9, 10, 11 };
//    quick_sort(a, 0, sizeof(a)/sizeof(int));
//    
//    std::for_each(a, a+sizeof(a)/sizeof(int), [&](int c) {
//        std::cout << c << ",";
//    });
//    
//    std::cout << std::endl;
    
    return 0;
}

/**
 * File: generate-mnemonics.cpp
 * ----------------------------
 * This is an application that compiles phone numbers (or, more generally,
 * numbers) to mnemonics, where the digit-to-letter mappins are consistent
 * with those listed on a traditional telephone keypad.
 */

//#include <string>    // for string
//#include <iostream>  // for cout, endl
//using namespace std;
//
////#include "console.h"
////#include "simpio.h"  // for getLine
//#include <vector> // for the Vector class template
//#include <map>     // for the Map class template
//#include <set>
//
//static void buildMappings(map<char, string>& mappings);
//static bool isAllPositiveDigits(const string& response);
//static string getPhoneNumber();
//static void generateMnemonics(string rest, map<char, string>& mappings, vector<string>& mnemonics);
//static void setUpMnemonics(const string& number, map<char, string>& mappings, vector<string>& mnemonics);
//
//int lengthOfLongestSubstring(string s) {
//    int length = s.length();
//    
//    if (length == 0) return 0;
//    if (length == 1) return 1;
//    
//    int max_length = 1;
//    char c = s[0];
//    int max_sub_length = 1;
//    std::map<char, int> char_set;
//    char_set[c] = 0;
//    for (int index=1; index < length; ++index) {
//        if (char_set.find(s[index]) == char_set.end()) {
//            max_sub_length += 1;
//        } else {
//            if (max_length < max_sub_length) {
//                max_length = max_sub_length;
//            }
//            max_sub_length = 1; //reset the length
//            index = char_set[s[index]] + 1;
//            char_set.clear();
//        }
//        c = s[index];
//        char_set[c] = index;
//        
//    }
//    
//    if (max_length < max_sub_length) {
//        max_length = max_sub_length;
//    }
//    
//    return max_length;
//}
//
//int lengthOfLongestSubstringv2(string s) {
//    int n = s.length();
//    int i = 0, j = 0;
//    int maxLen = 0;
//    bool exist[256] = { false };
//    while (j < n) {
//        if (exist[s[j]]) {
//            maxLen = max(maxLen, j-i);
//            while (s[i] != s[j]) {
//                exist[s[i]] = false;
//                i++;
//            }
//            i++;
//            j++;
//        } else {
//            exist[s[j]] = true;
//            j++;
//        }
//    }
//    maxLen = max(maxLen, n-i);
//    return maxLen;
//}
//
//int maxProfit(vector<int> &prices) {
//    int max_profit = 0;
//    int min = 0;
//    
//    for (int index = 0; index < prices.size(); ++index) {
//        if (prices[min] > prices[index]) {
//            min = index;
//        }
//        
//        int diff = prices[index] - prices[min];
//        
//        if (diff > max_profit) {
//            max_profit = diff;
//        }
//    }
//    
//    return max_profit;
//}
//
//int main() {
//    map<char, string> mappings;
//    buildMappings(mappings);
//    //while (true) {
//        string number = getPhoneNumber();
//        //if (number.empty()) break;
//        vector<string> mnemonics;
//        setUpMnemonics(number, mappings, mnemonics);
//        cout << "These are the possible mnemonics: " << endl << endl;
//        int count = 0;
//        std::for_each(mnemonics.begin(), mnemonics.end(), [&](std::string& str) {
//            cout << "  " << str;
//            count = (count + 1) % 9;
//            if (count % 9 == 0) cout << endl;
//        });
//        cout << endl;
//    //}
//    
//    //string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
//    //int len =lengthOfLongestSubstring(s);
//    //int len2 = lengthOfLongestSubstringv2(s);
//    
//    //vector<int> v = { 2, 1, 2, 0, 1 };
//    //maxProfit(v);
//    return 0;
//}
//
//
//
//static void setUpMnemonics(const string& number, map<char, string>& mappings, vector<string>& mnemonics) {
//    char startkey = number[0];
//    string rest = number.substr(1);
//    string start = mappings[startkey];
//    for (int i = 0; i < start.size(); i++) {
//        string stub = start.substr(i, 1);// turn the start string into stubs
//        mnemonics.push_back(stub);// and add to the mnemonics vector
//    }
//    generateMnemonics(rest, mappings, mnemonics);
//}
//
//static void generateMnemonics(string rest, map<char, string>& mappings, vector<string>& mnemonics) {
//    if (rest == "") {// base case- wait till "rest" (all the keys) is gone and then return
//        return;
//    } else {
//        vector<string> temporary;// if results are stored in mnemonics during the loop it'll be infinite
//        char key = rest[0];
//        string next = mappings[key];
//        if (rest.size() > 1) {// remove the current number from the string of keys
//            rest = rest.substr(1);
//        }
//        else {
//            rest = "";
//        }
//        for (int stub = 0; stub < mnemonics.size(); stub++) {// pull the stubs from mnemonics
//            string current = mnemonics[stub];
//            for (int nextone = 0; nextone < next.length(); nextone++) {// cycle through next characters and add to the stubs
//                string character = next.substr(nextone, 1);
//                string result = current + character;
//                temporary.push_back(result);// add results to temporary
//            }
//        }
//        mnemonics = temporary;// copy temporary on to mnemonics
//        generateMnemonics(rest, mappings, mnemonics);
//    }
//}
//
//static string getPhoneNumber() {
//    while (true) {
//        string response = "325";
//        if (isAllPositiveDigits(response)) return response;
//        cout << "Whatever you enter, make sure it includes only digit characters in ['2', '9'].  ";
//        cout << "Please try again." << endl;
//    }
//}
//
//static bool isAllPositiveDigits(const string& response) {
//    for (int i = 0; i < response.size(); i++) {
//        if (response[i] < '2' || response[i] > '9') {
//            return false;
//        }
//    }
//    
//    return true;
//}
//
//static void buildMappings(map<char, string>& mappings) {
//    const string options[] = {
//        "ABC", "DEF", "GHI", "JKL",
//        "MNO", "PQRS", "TUV", "WXYZ"
//    };
//    
//    for (int i = 0; i < sizeof(options)/sizeof(options[0]); i++) {
//        mappings['2' + i] = options[i];
//    }
//}
