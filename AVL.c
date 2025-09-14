/*
Author: Evandro Policarpo
Creation: 07D/09M/2025Y 11:00 UTC-3
Description: Implementation of a AVL Tree (Balanced Tree) Data Structure.
Last Modify: 12D/09M/2025Y 01:17 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>

int getBalance(Node *root){
    if(root == NULL) return 0;
    return height(root->l) - height(root->r);
}

int height(Node *root){
    if (root == NULL) return -1;

    int leftHeight = height(root->l);
    int rightHeight = height(root->r);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao criar nó");
        exit(1);
    }
    newNode->data = value;
    newNode->l = NULL;
    newNode->r = NULL;
    return newNode;
}

Node* findMax(Node *root){
    if(root == NULL) return NULL;
    Node *newNode = root;
    while(newNode->r != NULL){
        newNode = newNode->r;
    }
    return newNode;
}

Node* findMin(Node *root){
    if(root == NULL) return NULL;
    Node *newNode = root;

    while(newNode->l != NULL) newNode = newNode->l;

    return newNode;
}

void freeTree(Node *root){
    if(root != NULL){
        freeTree(root->l);
        freeTree(root->r);
        free(root);
    }
}

Node* insert(Node *root, int value){

}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
}

void postorder(Node *root){
    if(root != NULL){
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->data);
    }
}

void preorder(Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->l);
        preorder(root->r);
    }
}

//Balanceamento > 1 :
//  se subárvore direita com balanceamento < 0 = rotação dupla esquerda.
//  senão = rotação esquerda.
//Balanceamento < 1 :
// se subárvore esquerda com balanceamento > 0 = rotação dupla direita.
// senão = rotação direita
Node* rebalance(Node* node){
    if(node == NULL) return NULL;

    int balance = getBalance(node);
    int node_r = getBalance(node->r);
    int node_l = getBalance(node->l);

    if(balance > 1 && node_l >= 0) return rotateR(node);
    if(balance > 1 && node_l < 0){
        node->l = rotateL(node->l);
        return rotateR(node);
    }

    if(balance < -1 && node_r <= 0) return rotateL(node);
    if(balance < -1 && node_r > 0){
        node->r = rotateR(node->r);
        return rotateL(node);
    }

    return node;
}

Node* remove(Node* root, int key){

}

Node* rotateL(Node* x){
    Node *y = x->r;
    Node *subtree = y->l;

    y->l = x;
    x->r = subtree;

    return y;
}

Node* rotateLR(Node* node){
    node->l = rotateL(node->l);
    return rotateR(node);
}

Node* rotateR(Node* y){
    Node *x = y->l;
    Node *subtree = x->r;

    x->r = y;
    y->l = subtree;

    return x;
}

Node* rotateRL(Node* node){
    node->r = rotateR(node->r);
    return rotateL(node);
}

Node *search(Node *root, int value){
    if (root == NULL) return NULL;

    if (root->data == value) {
        return root;
    } else if (value < root->data) {
        return search(root->l, value);
    } else {
        return search(root->r, value);
    }
}

//void updateHeight(Node* node);