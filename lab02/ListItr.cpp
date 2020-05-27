// Justin Ngo, jmn4fms
// ListItr.cpp
// Created by Justin on 1/26/20.

#include <stdio.h>
#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
#include "List.h"

using namespace std;

ListItr::ListItr(){
    current = NULL;
}

ListItr::ListItr(ListNode* theNode){
    current = theNode;
}

bool ListItr:: isPastEnd() const{
    if((*current).next==NULL){
        return true;
    }
    return false;
}

bool ListItr:: isPastBeginning() const{
    if((*current).previous==NULL){
        return true;
    }
    return false;
}

void ListItr:: moveForward(){
    if(isPastEnd()==true){
        return; //exits method
    }
    current = (*current).next;
}

void ListItr:: moveBackward(){
    if(isPastBeginning()==true){
        return; //exits method
    }
    current = (*current).previous;
}

// Returns the value of the item in the current position of the list
int ListItr:: retrieve() const{
    return (*current).value;
}
