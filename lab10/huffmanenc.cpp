// Justin Ngo
// jmn4fms
// 4/14/20
// huffmanenc.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapNode.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void printCode(heapNode* n,string c,map<char,string> &m);

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Command line input error " << endl;
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    // if the file does not exist or is not found, terminate
    if ( fp == NULL ) {
      cout << "Error: '" << argv[1] << "' cannot be found or does not exist" << endl;
      exit(2);
    }

    vector<int> f(128,0);
    vector<char> listOfChars;
    char g;
    int total = 0;
    int gnum;

    while ((g = fgetc(fp)) != EOF){
        gnum = (int)g;
        if (gnum >= 32 && gnum <= 126){
            f[(int)g] += 1;
            total++;
        }
    }

    // creates and fills heap of chars
    heap h;
    heapNode* temp;
    
    for (int i = 31; i <= 126; i++){
        char ichar = (char)i;
        
        if (f[i] >= 1) {
            temp = new heapNode(ichar,f[i]);
            h.insert(temp);
            listOfChars.push_back(ichar);
        }
    }

    // creates huffman tree
    heapNode* leftChild;
    heapNode* rightChild;
    heapNode* parent;
    int lrcount = 0;
    
    while (h.size() > 1) {
        leftChild = h.deleteMin();
        rightChild = h.deleteMin();
        
        lrcount = leftChild->count+rightChild->count;
        
        parent = new heapNode('\0',lrcount);
        
        parent->left = leftChild;
        parent->right = rightChild;
        
        h.insert(parent);
    }

    // maps huffman code to char, prefix
    map<char, string> codes;
    printCode(h.findMin(), "", codes);

    // prints chars and encodings
    string s;
    int i = 0;
    
    while(i < listOfChars.size()){
        if (listOfChars[i] == ' '){
           s = "space";
        }
        else{
          s = listOfChars[i];
        }
        cout << s << " " << codes[listOfChars[i]] << endl;
        i++;
    }
    
    cout << "----------------------------------------" << endl;

    // reread file and print encoded message
    rewind(fp);
    string message = "";
    int len = 0;
    while ((g = fgetc(fp)) != EOF ){
        message += codes[g] + " ";
        len += codes[g].size();
    }
    cout << message << endl;
    
    cout << "----------------------------------------" << endl;

    // calculate compression ratio
    double td = (double)(total*8.0);
    double ld = (double)len;
    double compressionRatio = td/ld;
  
    cout << "Compression ratio: " << compressionRatio << endl;
    
    // calculate huffman tree cost
    double cost = 0.0;
    int index = 0;
    
    while(index < listOfChars.size()){
        cost += ((double)f[(int)listOfChars[index]]*(double)codes[listOfChars[index]].size()/(double)total);
        index++;
    }

    cout << "Cost: " << cost << " bits per character" << endl;

    //cout << "There are " << total << " symbols that are encoded." << endl;
    
    fclose(fp);
    return 0;
}

void printCode(heapNode* n,string c,map<char,string> &m){
    if(!n){
        return;
    }
    if((n->left==NULL) && (n->right==NULL)){
        m[n->val] = c;
    }
    printCode(n->left,c+"0",m);
    printCode(n->right,c+"1",m);
};
