// Justin Ngo jmn4fms 
//  ListNode.cpp
//  
//
//  Created by Justin on 1/26/20.
//

#include <stdio.h>
#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode:: ListNode(){
    //What goes in the constructor?
    next=NULL;
    previous=NULL;
    value=0;
}

ListNode:: ListNode(int val){
    value=val;
    next=NULL;
    previous=NULL;
}

//Getters for next and previous
ListNode* ListNode::getNext(){
    return next;
}

ListNode* ListNode::getPrevious(){
    return previous;
}
