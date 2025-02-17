// Justin Ngo
// jmn4fms
// wordPuzzle.cpp
// Created by Justin on 3/2/20.
//

#include "hashTable.h"
#include "timer.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <cmath>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);

//forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
bool readInWords (string filename, HashTable &table);

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while (!checkprime(++n));
    return n; // all your primes are belong to us
    }

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

/*
Main Method
*/

int main(int argc, char *argv[]){
  
    //If command line parameters are less than 2 then exit out
    // argv[] array. argc contains 1 more than the number of command
    if(argc != 3){
        cout << "Need 2 parameters" << endl;
        exit(1);
    }
    
    string dictionary = argv[1];
    string grid = argv[2];
    int amount = getNextPrime(10000);
    
    HashTable dictionaryList(amount);
    
    //Puts words into dictionaryList
    readInWords(argv[1],dictionaryList);

    int rows, cols; //Will hold the number of rows and columns in input file
    bool result = readInGrid (argv[2], rows, cols); //Reads file
    
    //If error trying to read file, exits
    if (!result) {
        cout << "Could not read file" << endl;
        exit(1);
    }
    
    string direction[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    int position = 0;
    
    //Create and start timer
    timer t;
    t.start();
    
    for (int i = 0; i < rows; i++ ){
        for(int j = 0; j<cols; j++){
            for(int k = 0; k < 8; k++){
                for(int l = 3; l<22; l++){
                    string checkWord =(getWordInGrid(i,j,k,l,rows,cols));
                    if(dictionaryList.check(checkWord)){
                        position+=1;
                        cout<<direction[k]<<" "<<"("<<i<<", "<<j<<"): "<< checkWord << endl;
                    }

                    if(getWordInGrid(i,j,k,l+1,rows,cols)==checkWord)
                        break;
                }
            }
        }
    }
    t.stop();
    cout << position << " words found" <<endl;
    cout << "Found all words in "<< t << " seconds" << endl;
    cout << (int)(stod(t.toString())*1000) << endl;
    return 0;
}

bool readInWords (string filename, HashTable &table){
    string line;
    string word;
    
    ifstream file(filename.c_str());
    
    if (!file.is_open() ){
        return false;
    }
    
    while(getline(file,line)){
        word = line;
        table.insert(word);
    }
    
    file.close();
    return true;
}
