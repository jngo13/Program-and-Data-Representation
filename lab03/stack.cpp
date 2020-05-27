// Justin Ngo
// jmn4fms
// stack.cpp
// Created by Justin on 2/7/20.

#include "stack.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include "postfixCalculator.h"

using namespace std;

Stack::Stack(){
    stack = new List();
    count = 0;
}

Stack::~Stack(){
    delete stack;
}

void Stack::push(int e){
    if(empty()){
        iterator = stack->first();
    }
        stack->insertBefore(e,iterator);
    count++;
}

void Stack::pop(){
    int topelement = top();
    stack->remove(topelement); //count will decrease
}

int Stack:: top(){
    iterator.moveBackward();
    int top = iterator.retrieve();
    iterator.moveForward();
    return top;
}

bool Stack:: empty(){
    if(count==0){
        return true;
    }
    return false;
}
