#ifndef utility_h
#define utility_h
#include "AvlTree.h"
int height(Node *N);                                                       // A utility function to get the height of the tree
int max(int a, int b);  

//utility function to return the height
int height(Node* N)
{
    if (N == nullptr){
        return 0;
    }
    return N->height;
}

//utility function to return max of two numbers
int max(int a, int b){
    return (a > b)? a : b;
}



#endif /* utility_h */
