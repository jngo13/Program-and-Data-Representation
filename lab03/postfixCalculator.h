// Justin Ngo
// jmn4fms
//  postfixCalculator.h
//  
//
//  Created by Justin on 2/3/20.
//

#ifndef postfixCalculator_h
#define postfixCalculator_h

#include <stdio.h>
#include <iostream>
//#include <stack>
#include <cstdlib>

#include "stack.h"

using namespace std;

class Stack;

class PostfixCalculator{
public:
    PostfixCalculator();
    
    Stack *calcstack; //stack<int> calcstack;
    
    //This adds the passed element to the top of the stack.
    void push(int e);
    
    //This returns the element on the top of the stack. It does not remove that element from the top. If the stack is empty, then somehow an error must be indicated -- printing an error message and exiting is fine for reporting errors for this lab.
    int top();
    
    //This removes the element on the top of the stack, but does not return it. If the stack is empty, then somehow an error must be indicated -- for this lab, you can just print out an error message and then exit.
    void pop();
    
    //This tells whether there are any elements left in the stack (false) or not (true).
    bool empty();
    
    void add();
    void subtract();
    void multiply();
    void divide();
    void negate();
    
};

#endif /* postfixCalculator_h */
