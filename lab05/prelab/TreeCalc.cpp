// Justin Ngo
// jmn4fms
// 2/15/20
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

stack<int> calcstack;
TreeNode *delitr;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    cleanTree(delitr);
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr->left){
        cleanTree(ptr->left);
    }
    if(ptr->right){
        cleanTree(ptr->right);
    }
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *node = new TreeNode(val);
    if(val == "+" || val == "-" || val == "*" || val == "/"){
        TreeNode *right = mystack.top();
        mystack.pop();
        TreeNode *left = mystack.top();
        mystack.pop();
        node->right = right;
        node->left =left;
    }
    mystack.push(node);
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    if(ptr == NULL){
        //break
    }
    else{
        cout << ptr->value + " ";
        if(ptr->left !=NULL){
            printPrefix(ptr->left);
        }
        if(ptr->right != NULL){
            printPrefix(ptr->right);
        }
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    if(ptr->left != NULL){
        cout << "( ";
        printInfix(ptr->left);
    }
    cout << ptr->value + " ";
    if(ptr->right != NULL){
        printInfix(ptr->right);
        cout << ") ";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    string str = "";
    if(ptr->left != NULL){
        printPostfix(ptr->left);
    }
    if(ptr->right != NULL){
        printPostfix(ptr->right);
    }
    str += ptr->value + " ";
    cout << str;
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    if(ptr->left != NULL){
        calculate(ptr->left);
    }
    if(ptr->right != NULL){
        calculate(ptr->right);
    }
    
    if(ptr->value == "+"){
        int top = calcstack.top();
        calcstack.pop();
        int bottom = calcstack.top();
        calcstack.pop();
        calcstack.push(top+bottom);
    }
    else if(ptr->value == "-"){
        int top = calcstack.top();
        calcstack.pop();
        int bottom = calcstack.top();
        calcstack.pop();
        calcstack.push(bottom-top);
    }
    else if(ptr->value== "*"){
        int top = calcstack.top();
        calcstack.pop();
        int bottom = calcstack.top();
        calcstack.pop();
        calcstack.push(top*bottom);
    }
    else if(ptr->value == "/"){
        int top = calcstack.top();
        calcstack.pop();
        int bottom = calcstack.top();
        calcstack.pop();
        calcstack.push(bottom/top);
    }
    
    /*else{
        int n;
        if(atoi(ptr->value) >> n){
            calcstack.push(n);
        }
    }*/
    //Could not get atoi to work at TA OH so switched to sstream
    else{
        int n;
        if((stringstream(ptr->value)>>n)){
            calcstack.push(n);
        }
    }
    return calcstack.top();
}

// Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());
    delitr = mystack.top();
    mystack.pop();
    return i;
}
