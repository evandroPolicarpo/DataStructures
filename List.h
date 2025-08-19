#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// =======================
// Struct
// =======================
typedef struct {
    int *elements;   // ponteiro para os elementos da lista
    int capacity;    // capacidade máxima da lista
    int size;        // quantidade atual de elementos
} DynamicList;

// =======================
// Function Prototypes
// =======================

// Inicializa a lista com capacidade inicial
int initializeList(DynamicList *list, int initialCapacity);

// Destroi a lista e libera memória
int destroyList(DynamicList *list);

// Retorna 1 se a lista estiver vazia, 0 caso contrário
int isEmpty(DynamicList *list);

// Retorna 1 se a lista estiver cheia, 0 caso contrário
int isFull(DynamicList *list);

// Retorna a capacidade da lista
int listCapacity(DynamicList *list);

// Redimensiona a lista para uma nova capacidade
int resizeList(DynamicList *list, int newCapacity);

// Insere um elemento no início da lista
int insertStart(DynamicList *list, int value);

// Insere um elemento no final da lista
int insertEnd(DynamicList *list, int value);

// Insere um elemento em um índice específico
int insertAt(DynamicList *list, int index, int value);

// Remove o primeiro elemento da lista
int removeStart(DynamicList *list);

// Remove o último elemento da lista
int removeEnd(DynamicList *list);

// Remove um elemento em um índice específico
int removeAt(DynamicList *list, int index);

// Retorna o elemento de um índice específico
int getElement(DynamicList *list, int index, int *out);

// Retorna a posição de um valor na lista, ou -1 se não encontrado
int getPosition(DynamicList *list, int value);

// Imprime todos os elementos da lista
int printList(DynamicList *list);

#endif // LIST_H
