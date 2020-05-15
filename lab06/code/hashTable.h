// Justin Ngo
// jmn4fms
//  hashTable.h
//  Created by Justin on 3/2/20.
//

#ifndef hashTable_h
#define hashTable_h

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

class HashTable{
public:
    HashTable(int size); //constructor takes in size
    ~HashTable();
    
    void insert(string word);
    bool check(string word);
    int hash(string word);
    
private:
    vector<list<string> > table;
    int tableSize;
    
};

#endif /* hashTable_h */
