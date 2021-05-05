
#ifndef BSTREE_
#define BSTREE_
#include <iostream>
#include <algorithm>
using namespace std;
#include "Node.h"

// Binary Search Tree class
class BSTree {
private:
    Node* root;                                 //Node root pointer
    bool treatAsInt;
    
    //add  object to addNode class
    //node may act as a object of  class
    //
    void addNode(string key, Node* leaf, MMAFighters MMA);      //add a node
    
    Node* deleteNode(Node* node, string key);      //delete nodes
    void freeNode(Node* leaf);                  //freeNode
    bool isLessThanOtherKey(string key1, string key2);
    bool isEqualToOtherKey(string key1, string key2);
    bool shouldWeCompareAsInteger(string key1, string key2);

public:
    BSTree();                                   //Default Contructor
    BSTree(bool treatAsInt);                                   //Sort By Int Contructor
    ~BSTree();                                  //Destructor
    Node* Root() { return root; }               //return root
    void setRoot(Node * _root) {root = _root;}  //assign root to _root
    
    //add  object to addNode class
    //node may act as a object of  class
    //
    void addNode(string key, MMAFighters MMA);                      //add nodes
                                                                
    Node* findNode(string key, Node* parent);      //search for a node
    void printPreorder(Node* node);             //display nodes in preorder
    void printInorder(Node* node);              //display nodes inorder
    void printPostorder(Node* node);            //display nodes postorder
    
    
    void deleteNode(string key);                   //delete a node
    
    Node* min(Node* node);                      //locate min node
    Node* max(Node* node);                      //locate max mode
    Node* successor(string key, Node* parent);     //locate successor
    Node* predecessor(string key, Node* parent);   //locate predecessor
    
};


#endif
