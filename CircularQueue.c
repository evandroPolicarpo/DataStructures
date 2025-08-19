/*
Author: Evandro Policarpo
Creation: 18D/08M/2025Y 23:00 UTC-3
Description: Implementation of a CircularQueue Data Structure with Array.
Last Modify: 19D/08M/2025Y 50:00 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

typedef struct CircularQueue {
    int front;    // índice do próximo elemento a ser removido
    int rear;     // índice da posição onde será inserido o próximo elemento
    int capacity; // capacidade máxima da fila
    int *elements;// array que armazena os elementos
} CircularQueue;

// Inicializa a fila com a capacidade especificada
void initQueue(CircularQueue *queue, int capacity) {
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    queue->elements = malloc(capacity * sizeof(int));
}

// Insere um elemento na fila
void enqueue(CircularQueue *queue, int element) {
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        printf("Fila cheia! Não é possível inserir %d\n", element);
        return;
    }
    queue->elements[queue->rear] = element;
    queue->rear = (queue->rear + 1) % queue->capacity;
}

// Remove e retorna o próximo elemento da fila
// Retorna -1 se a fila estiver vazia
int dequeue(CircularQueue *queue) {
    if (queue->front == queue->rear) {
        printf("Fila vazia! Não é possível remover.\n");
        return -1;
    }
    int element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return element;
}

// Verifica se a fila está cheia
int isFull(CircularQueue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Verifica se a fila está vazia
int isEmpty(CircularQueue *queue) {
    return queue->front == queue->rear;
}

// Imprime todos os elementos da fila
void printQueue(CircularQueue *queue) {
    int i = queue->front;
    printf("Fila: ");
    while (i != queue->rear) {
        printf("%d ", queue->elements[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}