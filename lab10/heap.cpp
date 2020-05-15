// Justin Ngo
// jmn4fms
// 4/14/20
// heap.cpp
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapNode.h"
#include <string>
#include <vector>
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    binaryHeap.push_back(0);
}

/*// builds a heap from an unsorted vector
heap::heap(vector<heapNode*> vec) : heap_size(vec.size()) {
    binaryHeap = vec;
    binaryHeap.push_back(heap[0]);
    binaryHeap[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}
*/

// the destructor doesn't need to do much
heap::~heap(){
}

void heap::insert(heapNode* x) {
    // a vector push_back will resize as necessary
    binaryHeap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapNode* x = binaryHeap[hole];
    int y = x->count;
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (y < binaryHeap[hole/2]->count); hole /= 2 )
        binaryHeap[hole] = binaryHeap[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    binaryHeap[hole] = x;
}

heapNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    heapNode* ret = binaryHeap[1];
    // move the last inserted position into the root
    binaryHeap[1] = binaryHeap[heap_size--];
    // make sure the vector knows that there is one less element
    binaryHeap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    /*
    int hole2 = hole->count;
    
    int y = binaryHeap[hole2]->count;
    int x = y;
    */
    heapNode* x = binaryHeap[hole];
    
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (binaryHeap[child+1]->count < binaryHeap[child]->count) )
            child++;
        // if the child is greater than the node...
        if ( x->count > binaryHeap[child]->count ) {
            binaryHeap[hole] = binaryHeap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    
    /*heapNode hN = hole;
    hole->count = x;
    binaryHeap[hole2] = &hole;
     */
    binaryHeap[hole] = x;
}

heapNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return binaryHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    binaryHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << binaryHeap[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << binaryHeap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
