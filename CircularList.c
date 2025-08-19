/*
Author: Evandro Policarpo
Creation: 19D/08M/2025Y 11:00 UTC-3
Description: Implementation of a CircularList Data Structure.
Last Modify: 19D/08M/2025Y 15:40 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

// =======================
// Cabeçalhos de função
// =======================
void freeList(CircularList *list);
int isEmpty(CircularList *list);
void initList(CircularList *list);
void insertAtEnd(CircularList *list, int value);
void insertAtIndex(CircularList *list, int value, int index);
void insertBeginning(CircularList *list, int value);
void removeAtBeginning(CircularList *list);
void removeAtEnd(CircularList *list);
void removeAtIndex(CircularList *list, int index);

// =======================
// Estruturas
// =======================
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircularList {
    Node *head;
    Node *tail;
} CircularList;

// =======================
// Funções
// =======================

// Inicializa a lista circular
void initList(CircularList *list){
    list->head = NULL;
    list->tail = NULL;
}

// Retorna 1 se a lista estiver vazia, 0 caso contrário
int isEmpty(CircularList *list){
    return list->head == NULL;
}

// Insere um elemento no início da lista
void insertBeginning(CircularList *list, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;

    if (isEmpty(list)) {
        // primeiro nó
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = list->head;
        list->tail->next = newNode; 
        list->head = newNode;       
    }
}

// Insere um elemento no final da lista
void insertAtEnd(CircularList *list, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Insere um elemento em um índice específico
void insertAtIndex(CircularList *list, int value, int index) {
    if (index < 0) return;

    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;

    // lista vazia: só insere se índice == 0
    if (isEmpty(list)) {
        if (index == 0) {
            list->head = newNode;
            list->tail = newNode;
            newNode->next = newNode;
        } else {
            free(newNode); // índice inválido
        }
        return;
    }

    // inserção no início
    if (index == 0) {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->head = newNode;
        return;
    }

    // inserção no meio ou final
    Node *current = list->head;
    int i = 0;
    while (i < index - 1 && current->next != list->head) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    current->next = newNode;

    // atualiza tail se inseriu no final
    if (current == list->tail) {
        list->tail = newNode;
    }
}

// Remove o primeiro elemento da lista
void removeAtBeginning(CircularList *list){
    if (isEmpty(list)) return;

    Node *toRemove = list->head;

    // caso lista com apenas um nó
    if (list->head == list->tail) {
        free(toRemove);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    list->head = list->head->next;
    list->tail->next = list->head;
    free(toRemove);
}

// Remove o último elemento da lista
void removeAtEnd(CircularList *list){
    if (isEmpty(list)) return;

    // caso lista com apenas um nó
    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    // encontra penúltimo nó
    Node *current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }

    current->next = list->head;
    free(list->tail);
    list->tail = current;
}

// Remove um elemento em um índice específico
void removeAtIndex(CircularList *list, int index) {
    if (isEmpty(list) || index < 0) return;

    // remover início
    if (index == 0) {
        removeAtBeginning(list);
        return;
    }

    Node *prev = list->head;
    int i = 0;

    // percorre até o nó anterior ao índice
    while (i < index - 1 && prev->next != list->head) {
        prev = prev->next;
        i++;
    }

    // índice maior que tamanho → nada a remover
    if (prev->next == list->head) return;

    Node *toRemove = prev->next;
    prev->next = toRemove->next;

    // atualiza tail se necessário
    if (toRemove == list->tail) {
        list->tail = prev;
    }

    free(toRemove);
}

// Libera todos os elementos da lista
void freeList(CircularList *list){
    if (isEmpty(list)) return;

    Node *current = list->head;
    Node *next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);

    list->head = NULL;
    list->tail = NULL;
}
