//Justin Ngo
//jmn4fms
//  stack.h
//  
//
//  Created by Justin on 2/7/20.
//

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include "postfixCalculator.h"

using namespace std;

class Stack{
public:
    Stack();
    ~Stack();
    void push(int e);
    void pop();
    int top();
    bool empty();
    
private:
    List *stack;
    ListItr iterator;
    int count;
};
#endif /* STACK_H */
