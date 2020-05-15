// Justin Ngo
// jmn4fms
//  testPostfixCalc.cpp
//  
//
//  Created by Justin on 2/3/20.
//

#include <stdio.h>
#include <iostream>
#include "postfixCalculator.h"
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
    PostfixCalculator p;
    
    string token;
    while(cin >> token){
        
        //Digit
        if(isdigit(token[0])){
            p.push(stoi(token));
            cout << "new token pushed is a digit. top: " << p.top() <<endl;
        }
        
        //Not a digit
        else{
            //cout << "entered not a digit else statement" <<endl;
            int negcheck;
            
            //Operators
            if(token[0]=='+'){
                p.add();
                cout << "add called " <<endl;
            }
            else if(token[0]=='-'){
                if(stringstream(token)>>negcheck){
                    p.push(negcheck);
                    cout << "pushed " << negcheck <<endl;
                }
                else{
                    p.subtract();
                    cout << "subtract called " <<endl;
                }
            }
            else if(token[0]=='*'){
                p.multiply();
                cout << "multiply called " <<endl;
            }
            else if(token[0]=='/'){
                p.divide();
                cout << "divide called " <<endl;
            }
            else if(token[0]=='~'){
                p.negate();
                cout << "negate called " <<endl;
            }
            cout << "Top: " << p.top() <<endl;
        }
        
        //Empty Stack
        if(p.calcstack->empty()){
            exit(-1);
            cout << "Result is: " << p.top() <<endl;
        }
        
        //cout << token <<endl;
    }
    cout << "Final result is: " << p.top() << endl;
    
    /*
    //Pre-lab Tests
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "Result is: " << p.top() << endl;
    
    p.pop();
    
    //Exits the program properly when the stack is empty
    //cout << "Result is: " << p.top() << endl;
    //cout << "Result is: " << p.top() << endl;
    
    //empty() tests
    cout << "empty() test 1. Expected: 1 , Actual: " << p.empty()<< endl;
    
    p.push(2);
    p.push(4);
    p.push(6);
    p.push(8);
    p.push(10);
    
    //Stack: 2 4 6 8 10
    cout << "empty() test 2. Expected: 0 , Actual: " << p.empty()
    << endl;

    
    //pop() test
    //Stack: 2 4 6 8 10
    p.pop();
    cout << "pop() test. Expected: 8 , Actual: " << p.top()<< endl;
    
    //subtract() tests
    //Stack: 2 4 6 8
    p.subtract();
    cout << "subtract() test 1. Expected: -2 , Actual: " << p.top()<< endl;
    
    //subtracting a negative number
    //Stack: 2 4 -2
    p.subtract(); //4-(-2)=6
    cout << "subtract() test 2. Expected: 6 , Actual: " << p.top()<< endl;
    
    //negate() tests
    //Stack: 2 6
    p.negate();
    cout << "negate() test 1. Expected: -6 , Actual: " << p.top()<< endl;

    //Stack: 2 4 -6
    p.negate();
    cout << "negate() test 2. Expected: 6 , Actual: " << p.top()<< endl;
    
    p.pop();
    p.pop();
    //Stack:
    
    p.push(3);
    p.push(5);
    p.push(6);
    p.push(8);
    p.push(4);
    //Stack: 3 5 6 8 4
    
    p.multiply();
    cout << "multiply() test. Expected: 32 , Actual: " << p.top()<< endl;
    
    //Stack: 3 5 6 32
    p.pop();
    
    //Stack: 3 5 6
    p.push(3);
    //Stack: 3 5 6 3
    
    p.divide();
    cout << "divide() test. Expected: 2 , Actual: " << p.top()<< endl;
    //Stack: 3 5 3
    
    p.multiply();
    cout << "multiply() test 2. Expected: 15 , Actual: " << p.top()<< endl;
    //Stack: 3 15
    
    p.push(5);
    //Stack: 3 15 5
    
    p.divide();
       cout << "divide() test 2. Expected: 3 , Actual: " << p.top()<< endl;
    
    //Stack: 3 3
    
    p.pop();
    cout << "pop() test. Expected: 3 , Actual: " << p.top()<< endl;
    */
    
    return 0;
}
