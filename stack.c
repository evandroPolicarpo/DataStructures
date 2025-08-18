/*
Author: Evandro Policarpo
Creation: 05D/08M/2025Y 22:00 UTC-3
Description: Implementation of a Stack Data Structure
Last Modify: 17D/08M/2025Y 20:46 UTC-3
*/

#include <stdlib.h>
#include <limits.h>
#include "stack.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;


void initStack(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
//void clearStack(Stack* stack);
//void printStack(Stack* stack);

void initStack(Stack *st){
	st->top = NULL;
}

int isEmpty(Stack *st){
	return st->top == NULL;
}

void push(Stack *st, int n){
	Node *new = malloc(sizeof(Node));
	if(new == NULL) return;
	new->data = n;
	new->next = st->top;
	st->top = new;
}

int pop(Stack *st){
	if(isEmpty(st)) return 0; //!!
	Node *temp = st->top;
	int m = temp->data;
	st->top = temp->next;
	free(temp);
	return m;
}

int peek(Stack *st){
    if(isEmpty(st)) return INT_MIN;
    return st->top->data;
}
