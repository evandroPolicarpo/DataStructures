/*
Author: Evandro Policarpo 
Creation: 05D/08M/2025Y 22:00 UTC-3
Description: Implementation of a Stack Data Structure
Last Modify: 05D/08M/2025Y 22:10 UTC-3
*/

#include <stdio.h>
#include <stack.h>

typedef struct Node{
	int value;
	struct Node *next;
} Node;

typedef struct Stack{
	Node *top;
	int size;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
int getSize(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void clearStack(Stack* stack);
void printStack(Stack* stack);

void initStack(Stack *st){
	st->size = 0;
	st->top = NULL;
}

int isEmpty(Stack *st){
	//return st->top == NULL;
	return st->size == 0;
}

int getSize(Stack *st){
	return st->size;
}