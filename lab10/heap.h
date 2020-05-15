// Justin Ngo
// jmn4fms
// 4/14/20
// heap.h
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "heapNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<heapNode*> vec);
    ~heap();

    vector<heapNode*> vec();
    void insert(heapNode* x); // inserts at vector tail
    heapNode* findMin(); // return element with lowest count
    heapNode* deleteMin(); // returns new element with lowest count
    unsigned int size(); // returns size of heap
    void makeEmpty(); //
    bool isEmpty();
    void print();
    
    vector<heapNode*> binaryHeap; // contains elements in heap
    unsigned int heap_size; // number of elements in binary heap

    void percolateUp(int hole);
    void percolateDown(int hole);

private:

};
#endif
