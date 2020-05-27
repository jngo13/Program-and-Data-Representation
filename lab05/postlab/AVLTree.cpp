// Justin Ngo
// jmn4fms
// 2/28/20
// AVLTree.cpp

#include "AVLTree.h"
#include <string>
#include "AVLNode.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    nodenum = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    if(find(x)!=true){
        insert(x, root);
        nodenum++;
    }
}

void AVLTree::insert(const string& x, AVLNode * & curNode){
        if (curNode==NULL) {
            curNode = new AVLNode();
            curNode -> value = x;
        } else if ( x < curNode->value ) {
            insert( x, curNode->left );
        } else if ( x > curNode->value) {
            insert( x, curNode->right );
        } else;
        balance(curNode);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    nodenum--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    if(find(x)==true){
        string str = "";
        return pathTo(x,root,str);
    }
    else return "";
}

string AVLTree::pathTo(const string& x, AVLNode *curNode, string str){
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
bool AVLTree::find(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    if(findNode(x,root)!=NULL) return true;
    return false;
}

AVLNode * AVLTree::findNode(string x, AVLNode *curNode) {
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
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE (X)
    return nodenum;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    //int balanceFactor = height(n->right) - height(n->left);
    if(balanceFactor(n) == 2){
        //first, see if we should also rotate right (i.e., do a double rotation)
        if(balanceFactor(n->right) < 0){
            rotateRight(n->right);
        }
        rotateLeft(n);
    }
    else if(balanceFactor(n) == -2){
        //first, see if we should also rotate left (i.e., double rotation)
        if(balanceFactor(n->left) > 0){
            rotateLeft(n->left);
        }
        rotateRight(n);
    }
}

int AVLTree::balanceFactor(AVLNode*& n){
    int bFactor = height(n->right) - height(n->left);
    return bFactor;
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    AVLNode *n2 = n->left;
    n->left = n2->right;
    n2->right = n;
    n->height = max(height(n->left), height(n->right)) + 1;
    n2->height = max(height(n2->left), n->height) + 1;
    n = n2;
    return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE (X)
    AVLNode * n2 = n->right;
    n2->right = n->left;
    n->left = n2;
    n2->height = max(height(n2->left), height(n2->right)) + 1;
    n->height = max(height(n->right), n2->height) + 1;
    n2 = n;
    return n;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
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
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        if (n->right == NULL) {
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        // two children -- tree may become unbalanced after deleting n
        string sr = min(n->right);
        n->value = sr;
        n->right = remove(n->right, sr);
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
    if (p == nullptr) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
