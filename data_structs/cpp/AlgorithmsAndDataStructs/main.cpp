//
//  main.cpp
//  AlgorithmsAndDataStructs
//
//  Created by Rakesh Patel on 9/5/14.
//  Copyright (c) 2014 Rakesh Patel. All rights reserved.
//

#include <iostream>

#include "linked_list.h"
#include "bst.h"

using namespace std;
using namespace list_ns;
using namespace bst_ns;

int main(int argc, const char * argv[])
{
    // Linked list test;
    LinkedList list;
    list.remove_front();
    list.remove_back();
    list.insert(10);
    cout << list;
    
    list.remove_front();
    cout << list;
    
    list.insert(11);
    cout << list;
    
    list.remove_back();
    cout << list;
    
    list.insert(10);
    cout << list;
    
    list.insert(12);
    list.insert(13);
    cout << list;
    
    list.remove_back();
    cout << list;
    
    list.insert(14);
    cout << list;
    cout << "front: " << list.first()->_value << endl;
    cout << "last: " << list.last()->_value << endl;

    list.remove_back();
    cout << list;
    
    cout << "length: " << list.length() << endl;
    list.clear();
    cout << list;
    
    cout << "length: " << list.length() << endl;
    
    BST bst;
    cout << "Before insert: ";
    bst.printInOrder();
    bst.insert(10);
    bst.insert(15);
    bst.insert(13);
    bst.insert(8);
    bst.insert(9);
    bst.insert(7);
    bst.insert(6);
    bst.insert(5);
    
    BSTNode* node13 = bst.find(13);
    if (node13) { cout << "found node with value=13" << endl; }  else  { cout << "13 not found. " << endl; }
    
    BSTNode* node12 = bst.find(12);
    if (node12) { cout << "found node with vlaue=12" << endl; } else  { cout << "12 not found. " << endl; }
    
    cout << "After insert: ";
    bst.printInOrder();
    
    cout << "count: " << bst.count() << endl;
    
    bst.remove(13);
    cout << "After deleting 13: ";
    bst.printInOrder();
    
    bst.insert(23); bst.insert(24);
    cout << "After insert(23): ";
    bst.printInOrder();
    
    bst.remove(23);
    cout << "After deleting 23: ";
    bst.printInOrder();
    
    bst.remove(7);
    cout << "After deleting 7: ";
    bst.printInOrder();
    
    bst.insert(7);
    bst.printInOrder();
    
    BSTNode* node = bst.find_largest(bst.find(8));
    cout << "largest element of tree strating with key 8 " << node->_value << endl;
    
    cout << "Before deleting 8: ";
    bst.printInOrder();
    
    bst.remove(8);
    cout << "After deleting 8: ";
    bst.printInOrder();
    
    cout << "Before deleting 10: ";
    bst.printInOrder();
    
    bst.remove(10);
    cout << "After deleting 10: ";
    bst.printInOrder();
    
    cout << "count: " << bst.count() << endl;
    
    return 0;
}

