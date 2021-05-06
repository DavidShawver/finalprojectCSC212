


#ifndef NODE_
#define NODE_
#include <iostream>
#include "MMAFighters.h"
using namespace std;


//AVL Tree Node
class Node {
public:
    string key;            //holds key
    Node* left;         //points to left subtree
    Node* right;        //points to right subtree
    Node* parent;
    int height;       //points to parent in tree
    MMAFighters MMA;

    Node() { key=-1; left=nullptr; right=nullptr; parent = nullptr;};   //Constructor
    
    //mutator functions
    void setKey(string aKey) { key = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    void setParent(Node* aParent) { parent = aParent; };
    void setHeight(int height){this->height = height;};
    
    
    //set fighter object to _MMAFighter
    void setMMAFighter(MMAFighters _MMAFighter) {MMA = _MMAFighter;}
    
    //accessor functions
    string Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
    Node* Parent() { return parent; };
    Node* newNode(string key, MMAFighters MMA);

    //allows node object to act as Contacts class object by
    //allowing the node to use the mutator and accessor functions
    //of the Contacts class

    MMAFighters& getMMAFighter() {return MMA;}
    //returns MMAFighters object 
};



#endif
