// Justin Ngo
// jmn4fms
// inlab4.cpp
// Created by Justin on 2/11/20.

#include <stdio.h>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

//Edited main for in-lab
int main(){
    //In-lab Part 1
    bool b = true;
    char c = 'c';
    int i = 1;
    double d = 1.0;
    int* ip = &i;
    
    cout << b <<endl;
    cout << c <<endl;
    cout << i <<endl;
    cout << d <<endl;
    cout << ip <<endl;
    
    //In-lab Part 2
    int IntArray[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    char CharArray[10] = {'a','b','c','d','e','f','g','h','i','j'};
    int IntArray2D[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
    char CharArray2D[6][5] = {{'a','b','c','d','e'},{'f','g','h','i','j'},{'k','l','m','n','o'},{'A','B','C','D','E'},{'F','G','H','I','J'},{'K','L','M','N','O'}};
    
    return 0;
}
