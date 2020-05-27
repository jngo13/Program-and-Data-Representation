// Justin Ngo, jmn4fms
// List.cpp
// Created by Justin on 1/26/20.

#include <stdio.h>
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

List:: List(){
    head = new ListNode();
    tail = new ListNode();
    (*head).next = tail;
    (*tail).previous = head;
    
    count=0; //see if this is necessary
}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
    makeEmpty(); //deletes everything inside
    delete head;
    delete tail;
}


// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

 
bool List:: isEmpty() const{
    if(count==0){
        return true;
    }
    return false;
}

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
void List:: makeEmpty(){
    //needs to be implemented

    while(isEmpty()==false){
        remove(first().retrieve());
    }
    
    (*head).next =tail;
    (*tail).previous=head;
    count=0;
}

 
// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first(){
    return ListItr((*head).next);
}


ListItr List::last(){
    return ListItr((*tail).previous);
}

void List:: insertAfter(int x, ListItr position){
    ListNode *node = new ListNode(x);
    
    (*node).next = (*(position.current)).next;
    (*node).previous = position.current; //current node is the one that it will be inserted after
    
    //Connects the existing list to the new node
    (*(position.current)).next = node;
    position.current->next->previous  = node;
    
    count++; //adding a node to the list
}

void List:: insertBefore(int x, ListItr position){
    ListNode *node = new ListNode(x);
    
    (*node).next = position.current;
    (*node).previous = (*(position.current)).previous;
    
    //Connects the existing list to the new node
    position.current->previous->next  = node;
    (*(position.current)).previous = node;
    
    count++; //adding a node to the list
}
 
void List:: insertAtTail(int x){
    ListNode *node = new ListNode(x);
    //Sets up where the new node is
    (*node).next = tail;
    (*node).previous = (*tail).previous;
    
    //Connects the existing list to the new node
    (*((*tail).previous)).next = node;
    (*tail).previous = node;
    
    count++; //adding a node to the list
}

// Returns an iterator that points to the first occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List:: find(int x){

    ListItr iterator((*head).next); //starts after dummy variable
    
    while(iterator.retrieve()!=x){
        if(iterator.isPastEnd()==false){
            iterator.moveForward();
        }
        else break;
    }
    if(iterator.current==NULL){
      iterator.current = tail; //so the method can return pointer to dummy tail
    }
    return iterator;
}

// Removes the first occurrence of x
void List:: remove(int x){
    ListItr *occ = new ListItr(find(x)); //creates a list iterator pointer to the first occurence of the parameter value
    
    occ->current->previous->next = occ->current->next;
    occ->current->next->previous = occ->current->previous;
    delete occ;
    count--;
    
}

int List::size() const{
    return count; //every time constructor called, count++. excludes dummy head/tail
}

ListNode* List::getHead(){
  return head;
}

ListNode* List::getTail(){
  return tail;
}

 
// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!
void printList(List& source, bool forward){
    if(forward == true){
        ListItr iterator((*source.getHead()).getNext()); //iterator
        while((iterator).isPastEnd()==false){
            cout << iterator.retrieve() << endl;
            iterator.moveForward();
        }
    }
    else {
        ListItr iterator((*source.getTail()).getPrevious()); //iterator
    while((iterator).isPastBeginning()==false){
        cout << iterator.retrieve() << endl;
        iterator.moveBackward();
    }
    }
}
