#ifndef STACK_H
#define STACK_H

// Estrutura de um nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha
typedef struct Stack{
    Node* top;
} Stack;

// Inicializa uma pilha vazia
void initStack(Stack* stack);

// Verifica se a pilha está vazia
int isEmpty(Stack* stack);

// Retorna o tamanho da pilha
//int getSize(Stack* stack);

// Empilha um elemento
void push(Stack* stack, int value);

// Desempilha um elemento e o retorna
int pop(Stack* stack);

// Retorna o elemento do topo sem remover
int peek(Stack* stack);

// Libera todos os nós da pilha
//void clearStack(Stack* stack);

// Imprime a pilha do topo até a base
//void printStack(Stack* stack);

#endif // STACK_H
