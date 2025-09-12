/*
Author: Evandro Policarpo
Creation: 07D/09M/2025Y 11:00 UTC-3
Description: Implementation of a Binary Search Tree Data Structure.
Last Modify: 11D/09M/2025Y 22:17 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

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

int countNodes(Node *n) {
    if (n == NULL) return 0;
    return countNodes(n->l) + countNodes(n->r) + 1;
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

int height(Node *root){
    if (root == NULL) return -1;

    int leftHeight = height(root->l);
    int rightHeight = height(root->r);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->data);
        inorder(root->r);
    }
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->l = insert(root->l, value);
    } else if (value > root->data) {
        root->r = insert(root->r, value);
    }
    return root;
}

int isEmpty(Node *root){
    return root == NULL;
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

Node* removeNode(Node *root, int value){
    if(root == NULL) return NULL;

    if(value < root->data){
        root->l = removeNode(root->l, value);
    } else if (value > root->data){
        root->r = removeNode(root->r, value);
    } else{
        if(root->l == NULL && root->r == NULL){
            free(root);
            return NULL;
        } else if (root->l == NULL){
            Node *temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL){
            Node *temp = root->l;
            free(root);
            return temp;
        } else{
            Node *temp = findMin(root->r);
            root->data = temp->data;
            root->r = removeNode(root->r, temp->data);
        }
    }
    return root;
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
