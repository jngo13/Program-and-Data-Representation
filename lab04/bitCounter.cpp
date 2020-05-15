// Justin Ngo
// jmn4fms
//  bitCounter.cpp
//  Created by Justin on 2/13/20.

#include <stdio.h>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int recursiveOnes(int n);

int main(int argc, char **argv){
    if(argc!=2){
        exit(1); //exits if not one parameter
    }
    int cnum = atof(argv[1]); //Converts char to double
    int output = recursiveOnes(cnum);
    cout<< output <<endl;
}

int recursiveOnes(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return recursiveOnes(n/2)+recursiveOnes(n%2);
}
