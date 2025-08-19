/*
Author: Evandro Policarpo
Creation: 18D/08M/2025Y 23:00 UTC-3
Description: Implementation of a Queue Data Structure with Array.
Last Modify: 18D/08M/2025Y 23:50 UTC-3
*/

#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// Estrutura da fila
typedef struct {
    int rear;       // Índice do último elemento
    int size;       // Capacidade máxima
    int *elements;  // Array de elementos
} Queue;

// Inicializa a fila com capacidade n
void initQueue(Queue *queue, int capacity) {
    queue->rear = -1;
    queue->size = capacity;
    queue->elements = malloc(capacity * sizeof(int));
}

// Verifica se a fila está vazia
int emptyQueue(Queue *queue) {
    return queue->rear == -1;
}

// Libera a Fila
void freeQueue(Queue *q){
    free(q->elements);
    free(q);
}

// Insere um elemento no final da fila
void insertQueue(Queue *queue, int value) {
    if (queue->rear == queue->size - 1) return; // fila cheia
    queue->rear++;
    queue->elements[queue->rear] = value;
}

// Remove e retorna o elemento do início da fila
int removeQueue(Queue *queue) {
    if (emptyQueue(queue)) return -1; // fila vazia
    
    int value = queue->elements[0];
    
    // Desloca todos os elementos para frente
    for (int i = 1; i <= queue->rear; i++) {
        queue->elements[i - 1] = queue->elements[i];
    }
    
    queue->rear--;
    return value;
}

// Imprime todos os elementos da fila
void printQueue(Queue *queue) {
    for (int i = 0; i <= queue->rear; i++) {
        printf("%d\n", queue->elements[i]);
    }
}
