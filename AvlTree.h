
#ifndef AVLTREE_
#define AVLTREE_
#include <iostream>
#include <algorithm>
using namespace std;
#include "Node.h"


// Binary Search Tree class
class AvlTree {
private:
    Node* root;                                 //Node root pointer
    bool treatAsInt;
    
    //add  object to addNode class
    //node may act as a object of  class
    //
    void insertNode(string key, Node* leaf, MMAFighters MMA);      //add a node
      //delete nodes
    void freeNode(Node* leaf);                  //freeNode
    bool isLessThanOtherKey(string key1, string key2);
    bool isEqualToOtherKey(string key1, string key2);
    bool shouldWeCompareAsInteger(string key1, string key2);

public:
    AvlTree();                                   //Default Contructor
    ~AvlTree();                                  //Destructor
    AvlTree(bool treatAsInt);                   //Constructor used in sort section for flagging whether to translate string to int
    Node* Root() { return root; }               //return root
    void setRoot(Node * _root) {root = _root;}  //assign root to _root
    
    //add  object to addNode class
    //node may act as a object of  class
    //
    void insertNode(string key, MMAFighters MMA);                      //add nodes
    Node* addNode(string key, MMAFighters MMA);
                                
    Node* findNode(string key, Node* parent);      //search for a node
    void printPreorder(Node* node);             //display nodes in preorder
    void printInorder(Node* node);              //display nodes inorder
    void printPostorder(Node* node);            //display nodes postorder
    int getBalance(Node *N);
    bool getTreatAsInt(){return this->treatAsInt;}
    void setTreatAsInt(bool treatAsInt){this->treatAsInt = treatAsInt;}
    
    Node* minKeyValueNode(Node* node);                      //locate min node
    Node* max_(Node* node);                      //locate max mode
    Node* successor(string key, Node* parent);     //locate successor
    Node* predecessor(string key, Node* parent);   //locate predecessor
    void preOrder(Node *root);
    Node* insert( string key, Node* node, MMAFighters& MMA);
    Node *leftRotate(Node *x);
    Node *rightRotate(Node *x);

    Node* deleteNode1(Node* root, string key);

    
};


#endif
