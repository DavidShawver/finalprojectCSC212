
#include "util.h"
#include "AvlTree.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Constructor
AvlTree::AvlTree() {
    root = nullptr;
}

AvlTree::AvlTree(bool treatAsInt) {
    root = nullptr;
    this->treatAsInt=treatAsInt;
}

// Destructor
AvlTree::~AvlTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
void AvlTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {
        
    }
    else if ( leaf != nullptr )
        
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
    }
    
}


// Add a node
/*
void AvlTree::insertNode(string key, MMAFighters newMMAFighter)
{
    // No elements. Add the root
    if ( root == nullptr )
    {
        Node* n = new Node();
        n->setKey(key);
        root = n;
        n->setMMAFighter(newMMAFighter);    
    }
    else
    {
        insertNode(key, root, newMMAFighter);
    }
}

// Add a node (private)
void AvlTree::insertNode(string key, Node* leaf, MMAFighters newMMAFighter)   
{
    if ( isLessThanOtherKey(key, leaf->Key()) || isEqualToOtherKey(key, leaf->Key()) )
    {
        if ( leaf->Left() != nullptr )
            insertNode(key, leaf->Left(), newMMAFighter);
        else
        {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
            n->setMMAFighter(newMMAFighter); //added 4/11/17
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            insertNode(key, leaf->Right(), newMMAFighter);
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
            n->setMMAFighter(newMMAFighter); //added 4/10/17
        }
    }
}
*/

// Find a node
Node* AvlTree::findNode(string key, Node* root)
{

    //check if node is equal to nullptr
    if (root != nullptr)
    {
        //if node is equal to key, then return the node
        if ( isEqualToOtherKey(key, root->Key()) )
            return root;
        
        //if key is less than node, then traverse left side of BSTree
        else if ( isLessThanOtherKey(key, root->Key()) )
            return findNode(key, root->Left());
        
        //if key is greater than or equal to node, then traverse
        //right side of BSTree
        else
            return findNode(key, root->Right());
    }
    //if node is equal to nullptr, return nullptr
    else
        return root;
    
}


// Print the BSTree
void AvlTree::printPreorder(Node* root)
{
    //check if node points to nullptr
    if (root != nullptr)
    {
        cout << root->Key() << " ";     //visit and display nodes
        printPreorder(root->Left());    //traverse left subtree of root
        printPreorder(root->Right());   //traverse right subtree of root
    }
}

void AvlTree::printInorder(Node* root)
{
    //check if node points to nullptr
    if (root != nullptr)
    {
        //as long as node doesn't point to nullptr
        printInorder(root->Left());     //traverse left subtree of node's root
        
        //Print MMAFighter object to display the records
        cout << root->getMMAFighter();     //visit and display nodes
                                        //added getMMAFighters() 4/10/17
        printInorder(root->Right());    //traverse right subtree of node's root
    }
    
}

void AvlTree::printPostorder(Node* root)
{
    //check if node points to nullptr
    if (root != nullptr)
    {
        printPostorder(root->Left());   //traverse left subtree
        printPostorder(root->Right());  //traverse right subtree
        cout << root->Key() << " ";     //visit and display nodes
    }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* AvlTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* AvlTree::max_(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max_(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

string removeSpaces(string input)
{
  input.erase(remove(input.begin(),input.end(),' '),input.end());
  return input;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

bool AvlTree::shouldWeCompareAsInteger(string key1, string key2){
    if(treatAsInt == true && !key1.empty() && !key2.empty() && isNumber(removeSpaces(key1)) && isNumber(removeSpaces(key2))){
        return true;
    } else {
        return false;
    }
}

bool AvlTree::isLessThanOtherKey(string key1, string key2){

    bool result;

    if( shouldWeCompareAsInteger(key1, key2) ){
        result = ( stoi( key1 ) < stoi( key2 ) ) ? true : false;
    } else {
        result = ( key1 < key2 ) ? true : false;
    }

    return result;
}

bool AvlTree::isEqualToOtherKey(string key1, string key2){

    bool result;

    if( shouldWeCompareAsInteger(key1, key2) ){
        result = ( stoi( key1 ) == stoi( key2 ) ) ? true : false;
    } else {
        result = ( key1 == key2 ) ? true : false;
    }

    return result;
}

void AvlTree::deleteNode(string key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* AvlTree::deleteNode(Node* root, string key)
{
    
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */
    
    if(root == nullptr) return root;
    else if( isLessThanOtherKey(key, root->Key()) )
        root->setLeft( deleteNode(root->Left(),key));
    else if( isLessThanOtherKey(root->Key(), key) )
        root->setRight( deleteNode(root->Right(), key) );
    else {
        // Case 1: No Child
        if(root->Left() == nullptr && root->Right() == nullptr){
            delete root;
            root = nullptr;
            // Case 2: one child
        } else if(root->Left() == nullptr){
            Node *temp = root;
            root = root->Right();
            delete temp;
        } else if(root->Right() == nullptr){
            Node *temp = root;
            root = root->Left();
            delete temp;
        } else{
            Node *temp = min(root->Right());
            root->setKey(temp->Key());
            root->setMMAFighter(temp->getMMAFighter());
            root->setRight(deleteNode(root->Right(), temp->Key()));
        }
    }
    return root;
    
}



/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
Node* AvlTree::addNode(string key, MMAFighters MMA)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->MMA = MMA;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *AvlTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *AvlTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}

// Get Balance factor of node N
int AvlTree::getBalance(Node *N)
{
    if (N == nullptr)
        {return 0;}
    return (height(N->left) - height(N->right));
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.


Node* AvlTree::insert(string key, Node* node, MMAFighters MMA)
{
    /* 1. Perform the normal BST insertion */
    if (node == nullptr)
        {return(addNode(key, MMA));}
 
    if (isLessThanOtherKey(key, node->key)|| isEqualToOtherKey(key, node->key)){
        node->left = insert(key, node->left, MMA);}
    else if (key > node->key)
        node->right = insert(key, node->right, MMA);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void AvlTree::preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}