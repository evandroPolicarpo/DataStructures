#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <stdio.h>
#include <stdlib.h>

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
// Protótipos de função
// =======================

// Inicializa a lista circular
void initList(CircularList *list);

// Retorna 1 se a lista estiver vazia, 0 caso contrário
int isEmpty(CircularList *list);

// Insere um elemento no início da lista
void insertBeginning(CircularList *list, int value);

// Insere um elemento no final da lista
void insertAtEnd(CircularList *list, int value);

// Insere um elemento em um índice específico
void insertAtIndex(CircularList *list, int value, int index);

// Remove o primeiro elemento da lista
void removeAtBeginning(CircularList *list);

// Remove o último elemento da lista
void removeAtEnd(CircularList *list);

// Remove um elemento em um índice específico
void removeAtIndex(CircularList *list, int index);

// Libera todos os elementos da lista
void freeList(CircularList *list);

#endif // CIRCULAR_LIST_H
