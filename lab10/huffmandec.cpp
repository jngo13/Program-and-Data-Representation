// Justin Ngo
// jmn4fms
// 4/16/20
// huffmandec.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapNode.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

heapNode* tree = NULL;
// Construct huffman tree with char and bits
void makeTree(heapNode* &root, char c, string prefix, int x);
// Decode bits
void decode(string bits);

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '"
             << prefix << "'" << endl;
        
        // Make huffman tree from chars and prefix code
        makeTree(tree, character[0], prefix, 0);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // close the file before exiting
    file.close();

    // Takes in bits and recurses tree to decode message
    decode(allbits);
    return 0;
}

void makeTree(heapNode* &root, char c, string prefix, int x){
    if (prefix.length() == x) {
        root = new heapNode();
        root->val = c;
    }
    else{
        if (root == NULL){
            root = new heapNode();
        }
        if (prefix.at(x) == '0'){
            makeTree(root->left, c, prefix, x+1);
        }
        if (prefix.at(x) == '1'){
            makeTree(root->right, c, prefix, x+1);
        }
    }
}

void decode(string bits){
    heapNode* currentTree = tree;
    int i = 0;
    while(i<bits.length()){
        if (bits.at(i) == '0'){
            currentTree = currentTree->left;
        }
        if (bits.at(i) == '1'){
            currentTree = currentTree->right;
        }
        if (currentTree->left == NULL && currentTree->right == NULL){
            cout << currentTree->val;
            currentTree = tree;
        }
        i++;
    }
    cout << endl;
};
