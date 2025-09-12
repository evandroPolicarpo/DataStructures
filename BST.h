#ifndef BST_H
#define BST_H

typedef struct Node {
    int data;
    struct Node *l;
    struct Node *r;
} Node;


int countNodes(const Node *root);                  
Node* createNode(int data);
Node* findMax(Node *root);
Node* findMin(Node *root);
void freeTree(Node *root);
int height(const Node *root);
void inorder(const Node *root);
Node* insert(Node *root, int data);
int isEmpty(const Node *root);
void postorder(const Node *root);
void preorder(const Node *root);
Node* removeNode(Node *root, int data);
Node* search(Node *root, int data);

#endif
