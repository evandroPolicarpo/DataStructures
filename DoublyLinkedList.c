/*
Author: Evandro Policarpo
Creation: 19D/08M/2025Y 18:30 UTC-3
Description: Implementation of a Doubly Linked List Data Structure.
Last Modify: 19D/08M/2025Y 19:30 UTC-3
*/

#include <stdio.h>
#include "DoublyLinkedList.h"

typedef struct Node{
	int data;
	struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList{
	Node *head;
    Node *tail;
} dls;

// Funções da lista
void initList(dls *ls);
void insertAtBeginning(dls *ls, int value);
void insertAtEnd(dls *ls, int value);
//void insertAtIndex(dls *ls,int value, int index);
void freeList(dls *ls);
int  isEmpty(dls *ls);
void printList(dls *ls);
//void removeAtIndex(dls *ls, int index);
void removeFirst(dls *ls);
void removeLast(dls *ls);

void initList(dls *ls){
    ls->head = NULL;
    ls->tail = NULL;
}

void insertAtBeginning(dls *ls, int value){
    if(ls == NULL) return;


    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = ls->head;
    newNode->prev = NULL;

    if(ls->head != NULL){
        ls->head->prev = newNode;
    } else{
        ls->tail = newNode;
    }

    ls->head = newNode;
}

void insertAtEnd(dls *ls, int value){
    if(ls == NULL) return;

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = ls->tail;

    if(ls->tail != NULL){
        ls->tail->next = newNode;
    } else{
        ls->head = newNode;
    }

    ls->tail = newNode;
}

/**void insertAtIndex(dls *ls,int value, int index){

}*/

/**void removeAtIndex(dls *ls, int index){

}*/

void removeFirst(dls *ls){
    if(ls == NULL) return;          //Lista não inicializada.
    if(ls->head == NULL) return;     //Lista vazia.

    Node *temp = ls->head;
    ls->head = ls->head->next;
    
    if(ls->head != NULL){
        ls->head->prev = NULL;
    } else{
        ls->tail = NULL;
    }

    free(temp);
}

void removeLast(dls *ls){
    if(ls == NULL) return;
    if(ls->tail == NULL) return;

    Node *temp = ls->tail;
    ls->tail = ls->tail->prev;

    if(ls->tail != NULL){
        ls->tail->next = NULL;
    } else{
        ls->head = NULL;
    }

    free(temp);

}

int isEmpty(dls *ls){
    return ls->head == NULL;
}

void freeList(dls *ls){
    if(ls == NULL) return;

    Node *aux = ls->head;
    Node *temp;
    while(aux != NULL){
        temp = aux;
        aux = aux->next;
        free(temp);
    }
    ls->head = NULL;
    ls->tail = NULL;
}

void printList(dls *ls){
    Node *aux = ls->head;
    while(aux != NULL){
        printf("%d <-> ",aux->data);
        aux = aux->next;
    }
}