/*
Author: Evandro Policarpo
Creation: 20D/07M/2025Y 20:08 UTC-3
Description: Implementation of a Linked List Data Structure
Last Modify: 19D/08M/2025Y 17:00 UTC-3
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node *head;
} LinkedList;

// Funções da lista
void insertAtBeginning(LinkedList *ls, int value);
void insertAtEnd(LinkedList *ls, int value);
void insertAtIndex(LinkedList *ls,int value, int index);
void freeList(LinkedList *ls);
int  isEmpty(LinkedList *ls);
void printList(LinkedList *ls);
void removeAtIndex(LinkedList *ls, int index);
void removeFirst(LinkedList *ls);
void removeLast(LinkedList *ls);

// Insere no início da lista
void insertAtBeginning(LinkedList *ls, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return; // falha no malloc
    newNode->data = value;
    newNode->next = ls->head;
    ls->head = newNode;
}

// Insere no final da lista
void insertAtEnd(LinkedList *ls, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return; // falha no malloc
    newNode->data = value;
    newNode->next = NULL;

    if (ls->head == NULL) { // lista vazia
        ls->head = newNode;
        return;
    }

    Node *current = ls->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtIndex(LinkedList *ls, int value, int index){
	if(index < 0) return;

	Node *newNode = malloc(sizeof(Node));
	if(!newNode) return;
	newNode->data = value;

	if(index == 0){
		newNode->next = ls->head;
		ls->head = newNode;
		return;
	}

	Node *temp = ls->head;
	for(int i = 0 ; i < index - 1 && temp; i++){
		temp = temp->next;
	}

	if(!temp){					//índice fora da lista.
		free(newNode);
		return;
	}

	newNode->next = temp->next;
	temp->next = newNode;

}

// Libera todos os nós da lista
void freeList(LinkedList *ls) {
    Node *current = ls->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    ls->head = NULL;
}

// Retorna 1 se a lista estiver vazia, 0 caso contrário
int isEmpty(LinkedList *ls) {
    return ls->head == NULL;
}

// Imprime os elementos da lista
void printList(LinkedList *ls) {
    if (isEmpty(ls)) {
        printf("Empty List!\n");
        return;
    }

    Node *current = ls->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void removeAtIndex(LinkedList *ls, int index) {
    if (!ls || index < 0 || !ls->head) return;

    Node *temp = ls->head;

    if (index == 0) {
        ls->head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < index - 1 && temp; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) return;

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}


// Remove o primeiro elemento da lista
void removeFirst(LinkedList *ls) {
    if (isEmpty(ls)) return;
    Node *temp = ls->head;
    ls->head = ls->head->next;
    free(temp);
}

// Remove o último elemento da lista
void removeLast(LinkedList *ls) {
    if (isEmpty(ls)) return;
    Node *current = ls->head;

    if (current->next == NULL) { // só tem 1 nó
        free(current);
        ls->head = NULL;
        return;
    }

    while (current->next->next != NULL) { // vai até o penúltimo
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}