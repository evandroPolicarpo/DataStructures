#ifndef STACK_H
#define STACK_H

// Estrutura de um nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha
typedef struct Stack {
    Node* top;
} Stack;

// Inicializa uma pilha vazia
void initStack(Stack* stack);

// Verifica se a pilha está vazia
int isEmpty(Stack* stack);

// Retorna o elemento do topo sem remover
int peek(Stack* stack);

// Remove e retorna o elemento do topo
int pop(Stack* stack);

// Imprime os nós da pilha.
void printNodes(Node *node);

// Imprime a pilha (do base para o topo)
void printStack(Stack* stack);

// Empilha um elemento no topo
void push(Stack* stack, int value);


#endif // STACK_H
