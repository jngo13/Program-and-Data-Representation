// Justin Ngo
// jmn4fms
// 4/14/20
// heapNode.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heapNode.h"
#include <string>
#include <vector>
using namespace std;

heapNode::heapNode() {
    left = NULL;
    right = NULL;
    val = '\0';
    count = 0;
}

heapNode::heapNode(char v, int c) {
    val = v;
    count = c;
    left = NULL;
    right = NULL;
}

int heapNode::getCount() {
  return count;
}

void heapNode::setCount(int c){
    count = c;
}

void heapNode::countPlusPlus(){
    count++;
}

heapNode* heapNode::getLeft() {
  return left;
}

heapNode* heapNode::getRight() {
  return right;
}

void heapNode::setLeft(heapNode* node) {
  left = node;
}

void heapNode::setRight(heapNode* node) {
  right = node;
}

char heapNode::getVal() {
  return val;
}

void heapNode::setVal(char c) {
  val = c;
}
