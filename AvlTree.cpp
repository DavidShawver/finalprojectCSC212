
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
    treatAsInt = true;
}

 AvlTree::AvlTree(bool treatAsInt){
     root = nullptr;
     this->treatAsInt = treatAsInt;
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
Node* AvlTree::minKeyValueNode(Node* node)
{
    Node* current = node;
   
    while( current->Left() != nullptr){
        current = current->Left();
    }
    
    return current;
}


// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
Node* AvlTree::deleteNode1(Node* root, string key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == nullptr) 
        return root; 
  
    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( isLessThanOtherKey(key, root->Key())) 
        root->setLeft(deleteNode1(root->left, key)); 
  
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if(isLessThanOtherKey(root->Key(), key)) 
        root->setRight(deleteNode1(root->right, key)); 
  
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( root->Left() == nullptr || root->Right() == nullptr)
        { 
            Node *temp = (root->Left()) ? root->Left() : root->Right(); 
  
            // No child case 
            if (temp == nullptr) 
            { 
                temp = root; 
                root = nullptr; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Node* temp = minKeyValueNode(root->Right()); 
  
            // Copy the inorder successor's 
            // data to this node 
            root->Key() = temp->Key(); 
  
            // Delete the inorder successor 
            root->setRight(deleteNode1(root->Right(), temp->Key()));
        } 
    } 
  
    // If the tree had only one node
    // then return 
    if (root == nullptr) 
    return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->setHeight(1 + max(height(root->left), 
                           height(root->right))); 
  
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root); 
  
    // If this node becomes unbalanced, 
    // then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && 
        getBalance(root->Left()) >= 0) 
        return rightRotate(root); 
  
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->Left()) < 0) 
    { 
        root->setLeft(leftRotate(root->Left())); 
        return rightRotate(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->Right()) <= 0) 
        return leftRotate(root); 
  
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->Right()) > 0) 
    { 
        root->setRight(rightRotate(root->Right())); 
        return leftRotate(root); 
    } 
  
    return root; 
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

/* Helper function that allocates a new node
   with the given key and MMA object and
   NULL left and right pointers. */
Node* AvlTree::addNode(string key, MMAFighters MMA)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
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
    Node *x = y->Left();
    Node *T2 = x->Right();
 
    // Perform rotation
    x->setRight(y);
    y->setLeft(T2);
 
    // Update heights
    y->setHeight(max(height(y->left),
                    height(y->right)) + 1);
    x->setHeight(max(height(x->left),
                    height(x->right)) + 1);
 
    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *AvlTree::leftRotate(Node *x)
{
    Node *y = x->Right();
    Node *T2 = y->Left();
 
    // Perform rotation
    y->setLeft(x);
    x->setRight(T2);
 
    // Update heights
    x->setHeight(max(height(x->left),   
                    height(x->right)) + 1);
    y->setHeight(max(height(y->left),
                    height(y->right)) + 1);
 
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


Node* AvlTree::insert(string key, Node* node, MMAFighters& MMA)
{
    /* 1. Perform the normal BST insertion */
    if (this->Root() == nullptr){
        setRoot(addNode(key, MMA));
        return root;
    }

    if (node == nullptr)
        { return addNode(key, MMA);}
 
    if (isLessThanOtherKey(key, node->key))
        {node->setLeft(insert(key, node->left, MMA));
         node->left->setParent(node);}
    else if (isLessThanOtherKey(node->key, key))
        {node->setRight(insert(key, node->right, MMA));
         node->right->setParent(node);}
    else {return node;} // Equal keys are not allowed in BST
 
    /* 2. Update height of this ancestor node */
    node->setHeight(1 + max(height(node->left),
                        height(node->right)));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && isLessThanOtherKey(key, node->left->key))
    {
        return rightRotate(node);
    }
 
    // Right Right Case
    if (balance < -1 && isLessThanOtherKey(node->right->key, key))
    {
        return leftRotate(node);
    }
 
    // Left Right Case
    if (balance > 1 && isLessThanOtherKey(node->left->key, key))
    {
        node->setLeft(leftRotate(node->left));
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && isLessThanOtherKey(key, node->right->key))
    {
        node->setRight(rightRotate(node->right));
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