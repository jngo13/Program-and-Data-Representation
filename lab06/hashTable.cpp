// Justin Ngo
// jmn4fms
// hashTable.cpp
// Created by Justin on 3/2/20.
//

#include "hashTable.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

HashTable::HashTable(int size){
    tableSize = size;
    list<string> list;
    
    for(int i=0; i<tableSize; i++){
        table.push_back(list);
    }
}

HashTable::~HashTable(){
    //delete table;
}

void HashTable::insert(string word){
    if(word.length() >= 3){
        int index = hash(word);
        table[index].push_back(word);
    }
    else;
}

bool HashTable::check(string word){
    int index = hash(word);
    
    if(table[index].front() == word){
        return true;
    }
    
    else{
    list<string>::iterator itr = table[index].begin();
    while(*itr!=word && itr!=table[index].end()){
      itr++;
    }
        
    if(*itr == word){
      return true;
    }
    else{
      return false;
    }
  }
}

int HashTable::hash(string word){
    
    int index = 0;
    
    unsigned long long hash = 7;
    
    for(int i = 0; i<word.length(); i++){
        hash = hash*31 + ((int)word[i]);
    }
    
    index = hash % tableSize;
    return index;
}
