#ifndef QUEUE_H
#define QUEUE_H

// Estrutura da fila
typedef struct {
    int rear;       // Índice do último elemento
    int size;       // Capacidade máxima
    int *elements;  // Array de elementos
} Queue;

// Inicializa a fila com capacidade n
void initQueue(Queue *queue, int capacity);

// Verifica se a fila está vazia
int emptyQueue(Queue *queue);

// Insere um elemento no final da fila
void insertQueue(Queue *queue, int value);

// Remove e retorna o elemento do início da fila
int removeQueue(Queue *queue);

// Imprime todos os elementos da fila
void printQueue(Queue *queue);

// (Opcional) Retorna o tamanho da fila
// int getQueueSize(Queue *queue);

// (Opcional) Libera a memória alocada para a fila
// void clearQueue(Queue *queue);

#endif // QUEUE_H
