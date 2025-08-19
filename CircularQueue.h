#ifndef CIRCULAR_QUEUE_HQUEUE_H
#define CIRCULAR_QUEUE_HQUEUE_H

#include <stdlib.h>
#include <stdio.h>

// Estrutura da fila circular
typedef struct CircularQueueQueue {
    int front;      // índice do próximo elemento a ser removido
    int rear;       // índice da posição onde será inserido o próximo elemento
    int capacity;   // capacidade máxima da fila
    int *elements;  // array que armazena os elementos
} CircularQueue;

// Inicializa a fila com a capacidade especificada
void initQueue(CircularQueueQueue *queue, int capacity);

// Insere um elemento na fila
void enqueue(CircularQueueQueue *queue, int element);

// Remove e retorna o próximo elemento da fila (-1 se vazia)
int dequeue(CircularQueueQueue *queue);

// Verifica se a fila está cheia
int isFull(CircularQueueQueue *queue);

// Verifica se a fila está vazia
int isEmpty(CircularQueueQueue *queue);

// Imprime todos os elementos da fila
void printQueue(CircularQueueQueue *queue);

#endif // CIRCULAR_QUEUE_H
