// Justin Ngo
// jmn4fms
//  postfixCalculator.cpp
//  
//
//  Created by Justin on 2/3/20.
//

#include "postfixCalculator.h"
#include <stdio.h>
#include <iostream>
//#include <stack>
#include <cstdlib>

#include "stack.h"

using namespace std;

PostfixCalculator::PostfixCalculator(){
    calcstack = new Stack();
}

//This adds the passed element to the top of the stack.
void PostfixCalculator::push(int e){
    calcstack->push(e); //calcstack.push(e)
}

//This returns the element on the top of the stack. It does not remove that element from the top. If the stack is empty, then somehow an error must be indicated -- printing an error message and exiting is fine for reporting errors for this lab.
int PostfixCalculator::top(){
    /*if(calcstack.empty()==true){
        exit(-1);
    }*/
    if(calcstack->empty()==true){
        exit(-1);
    }
    return calcstack->top(); //calcstack.top();
}

//This removes the element on the top of the stack, but does not return it. If the stack is empty, then somehow an error must be indicated -- for this lab, you can just print out an error message and then exit.
void PostfixCalculator:: pop(){
    if(calcstack->empty()==true){
        exit(-1);
    }
    calcstack->pop(); //calcstack.pop();
}

//This tells whether there are any elements left in the stack (false) or not (true).
/*bool PostfixCalculator:: empty(){
    return calcstack.empty();
}*/

void PostfixCalculator::add(){
    int val1 = calcstack->top(); //int val1 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    int val2 = calcstack->top(); //int val2 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    calcstack->push(val1 + val2); //calcstack.push(val1 + val2);
}

void PostfixCalculator::subtract(){
    //int flag;
    int val1 = calcstack->top(); //int val1 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    int val2 = calcstack->top(); //int val2 = calcstack.top();
    calcstack->pop();
    /*if(val1==val2){
        calcstack->pop();
        if(calcstack->top()!=0){
            val2 = calcstack->top();
            flag = 1;
        }
        //flag = 1;
    }
    cout << val2 << " - " << val1 <<endl;
    if(flag==1){
        calcstack->push(val1);
    }*/
    calcstack->push(val2-(val1)); //calcstack.push(val2-val1);
}

void PostfixCalculator::multiply(){
    int val1 = calcstack->top(); //int val1 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    int val2 = calcstack->top(); //int val2 = calcstack.top();
    calcstack->pop();//calcstack.pop();
    calcstack->push(val1*val2);//calcstack.push(val1*val2);
}

void PostfixCalculator::divide(){
    int val1 = calcstack->top(); //int val1 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    int val2 = calcstack->top(); //int val2 = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    calcstack->push(val2/val1); //calcstack.push(val2/val1);
}

void PostfixCalculator::negate(){
    int negint = calcstack->top(); //int negint = calcstack.top();
    calcstack->pop(); //calcstack.pop();
    calcstack->push(negint*(-1)); //calcstack.push(negint*(-1));
}
