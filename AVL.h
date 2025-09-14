#ifndef H
#define H

#include <stdarg.h>

typedef struct Node {
    int data;
    struct Node* l;
    struct Node* r;
} Node;

int getBalance(Node* node);                 
int height(Node* node);
int max(int a, int b);
Node* createNode(int key);
Node* findMax(Node* node);
Node* findMin(Node* node);
void freeTree(Node* root);
Node* insert(Node* root, int key);          //
void inorder(Node* root);
void postorder(Node* root);
void preorder(Node* root);
Node* rebalance(Node* node);                
Node* remove(Node* root, int key);          //
Node* rotateL(Node* x);                     
Node* rotateLR(Node* node);                 
Node* rotateR(Node* y);                     
Node* rotateRL(Node* node);                 
Node* search(Node* root, int key);
//void updateHeight(Node* node);             

#endif
