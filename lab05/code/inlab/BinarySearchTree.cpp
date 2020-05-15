// Justin Ngo
// jmn4fms
// 2/25/20
// BinarySearchTree.cpp

#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include "BinaryNode.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    nodenum = 0;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE(X)
    if(find(x)!=true){
        insert(x,root);
        nodenum++;
    }
}

void BinarySearchTree::insert(const string& x, BinaryNode * & curNode){
        if (curNode==NULL) {
            curNode = new BinaryNode();
            curNode -> value = x;
        } else if ( x < curNode->value ) {
            insert( x, curNode->left );
        } else if ( x > curNode->value) {
            insert( x, curNode->right );
        } else;
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
    nodenum--;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }
    // first look for x
    if (x == n->value) {
        // found
        // no children
        if (n->left == NULL && n->right == NULL) {
            delete n;
            n = NULL;
            return NULL;
        }
        // single child
        if (n->left == NULL) {
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        if (n->right == NULL) {
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        // two children
        string sr = min(n->right);
        n->value = sr;
        n->right = remove(n->right, sr);
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE(X)
    if(find(x)==true){
        string str = "";
        return pathTo(x,root,str);
    }
    else return "";
}

string BinarySearchTree::pathTo(const string& x, BinaryNode *curNode, string str){
    // handle case where a NULL pointer could be passed
    // curNode->right or curNode->left might be NULL
    
    str += curNode->value + " ";
    
    if (curNode == NULL){  // we've "run" off the bottom
        return NULL;
    }
    
    else if (x < curNode->value){
        return pathTo(x, curNode->left, str); // search left
    }
    else if (x > curNode->value){
        return pathTo(x, curNode->right, str); //search right
    }
    else{
        return str; // matched
    }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x){
    // YOUR IMPLEMENTATION GOES HERE (X)
    //return getElement(find(x,root));
    if(findNode(x,root)!=NULL) return true;
    return false;
}

/*const string& BinarySearchTree::getElement(BinaryNode *t) const {
    return t == NULL ? ITEM_NOT_FOUND : t->value;
}*/

BinaryNode * BinarySearchTree::findNode(string x, BinaryNode *curNode) {
    // handle case where a NULL pointer could be passed
    // curNode->right or curNode->left might be NULL
    if (curNode == NULL)  // we've "run" off the bottom
        return NULL;
    else if (x < curNode->value){
        return findNode(x, curNode->left); // search left
    }
    else if (x > curNode->value){
        return findNode(x, curNode->right); //search right
    }
    else{
        return curNode; // matched
    }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE (X)
    return nodenum;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
    if (p == nullptr) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}
