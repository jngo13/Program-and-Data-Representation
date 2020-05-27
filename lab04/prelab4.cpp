// Justin Ngo
// jmn4fms
// prelab4.cpp
// Created by Justin on 2/10/20.

#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

void sizeOfTest();
void outputBinary(unsigned int x);
void overflow();

int main(){
    int val;
    cout << "Enter a single integer value: " << endl;
    cin >> val;
    cout << "" << endl;
    sizeOfTest();
    cout << "" << endl;
    outputBinary(val);
    cout << "" << endl;
    overflow();
    return 0;
}

void sizeOfTest(){
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of bool: " << sizeof(bool) << endl;
    cout << "size of int*: " << sizeof(int*) << endl;
    cout << "size of char*: " << sizeof(char*) << endl;
    cout << "size of double*: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x){
    string str = "";
    for(int i = 32; i>0; i--){
        if((x/(int)pow(2,i-1)) != 0){
            str+="1";
            x=x-pow(2,i-1);
        }
        else str +="0";
        if((i-1)%4==0){
            str+=" ";
        }
    }
    cout << str << endl;
}

void overflow(){
    //What do you think will happen when you add 1 to a variable containing the maximum value of a type?
    //
    //What happens when you add 1 to an unsigned int variable containing the maximum value of an unsigned int?
    //Does the program halt?
    //What answer do you get?
    //Why does this happen?
    
    unsigned int x = UINT_MAX;
    cout << x << endl;
    x = UINT_MAX + 1;
    cout << "Adding 1: " << x << endl;
    
    cout << "This happens because the max unsigned int is 32 bit binary integer that has a 1 in every place value. Adding 1 to an unsigned max int is 0 because the 32 bits allocated for the max unsigned int are filled for the max int and by adding 1 it causes an integer overflow. The computer then delete all the bits to handle the overflow making it go back to 0" << endl;
}
