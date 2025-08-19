/*
Author: Evandro Policarpo
Creation: 05D/08M/2025Y 22:00 UTC-3
Description: Implementation of a Stack Data Structure
Last Modify: 18D/08M/2025Y 21:30 UTC-3
*/

#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

// Estrutura de um nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha
typedef struct Stack {
    Node* top;
} Stack;

// Protótipos das funções
void initStack(Stack* stack);
int isEmpty(Stack* stack);
int peek(Stack* stack);
int pop(Stack* stack);
void printNodes(Node *node);
void printStack(Stack* stack);
void push(Stack* stack, int value);

// Inicializa a pilha (topo = NULL)
void initStack(Stack *stack) {
    stack->top = NULL;
}

// Verifica se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Retorna o valor no topo da pilha (sem remover)
int peek(Stack *stack) {
    if (isEmpty(stack)) return INT_MIN; // retorna menor int se vazia
    return stack->top->data;
}

// Remove e retorna o valor do topo da pilha
int pop(Stack *stack) {
    if (isEmpty(stack)) return INT_MIN; // erro: pilha vazia
    Node *temp = stack->top;
    int topValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return topValue;
}

// Função auxiliar que percorre os nós da pilha.
void printNodes(Node *node){
	if(node == NULL) return;
	printNodes(node->next);
	printf("%d \n", node->data);
	// Só mostra os elementos depois de percorrer toda a pilha, ou seja: mostra do último(baixo) para cima.
}

// Mostra os elementos da pilha utilizando "printNodes" como auxiliar
void printStack(Stack *stack) {
	printNodes(stack->top);
}

// Insere um valor no topo da pilha
void push(Stack *stack, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return; // erro de alocação
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}
