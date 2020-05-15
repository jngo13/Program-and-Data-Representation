// Justin Ngo
// jmn4fms
// 4/14/20
// heapNode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class heapNode {
public:
    
    int count; // int count
    char val; // character value of node
    
    heapNode(); // constructor
    heapNode(char v, int c); // another constructor
    
    heapNode* left; // left
    heapNode* right; // right
    
    char getVal(); // returns character value stored in node
    void setVal(char c); // sets the char value of node
    
    int getCount(); // returns count value stored in node
    void setCount(int c); // sets count value in node
    void countPlusPlus(); // increments count value in node
    
    heapNode* getLeft(); // returns left child node
    heapNode* getRight(); // returns right child of node
    void setLeft(heapNode* node); // sets left child of node
    void setRight(heapNode* node); // sets right child of node

private:
    // no private bc complicated
};
#endif
