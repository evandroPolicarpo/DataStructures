/*
Author: Evandro Policarpo 
Creation: 20D/07M/2025Y 20:08 UTC-3
Description: Implementation of a Linked List Data Structure
Last Modify: 05D/08M/2025Y 23:50 UTC-3
*/

#include <stdio.h>
#include <stdarg.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node *head;
} LinkedList;

void initList(LinkedList* list);									//Feito
void freeList(LinkedList* list);
void insertAtBeginning(LinkedList* list, int value);				//Feito
void insertAtEnd(LinkedList* list, int value);						//Feito
void insertAtIndex(LinkedList* list, int index, int value);
void removeFirst(LinkedList* list);									//Feito
void removeLast(LinkedList* list);									//Feito
void removeValue(LinkedList* list, int value);
void removeAtIndex(LinkedList* list, int index);
Node* search(LinkedList* list, int value);							//Feito
int contains(LinkedList* list, int value);							//Feito
int getAtIndex(LinkedList* list, int index);						//Feito
int isEmpty(const LinkedList* list);								//Feito
int size(const LinkedList* list);									//Feito
void printList(const LinkedList* list);								//Feito
void reverse(LinkedList* list);
void clear(LinkedList* list);

int main(int argc, char const *argv[]){

	return 0;
}

void initList(LinkedList *ls){
	ls->head = NULL;
}

void insertEnd(LinkedList *ls, int value){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	if(ls->next == NULL){
		ls->head = newNode;
		return;
	}

	Node *current = ls->head;
	while(current->next != NULL){
		current = current->next;
	}

	current->next = newNode;

}

int isEmpty(LinkedList *ls){
	return ls->head == NULL;
}

int size(LinkedList *ls){
	if(ls == NULL) return 0;

	Node *current = ls->head;
	int i = 0;

	while(current != NULL){
		i++;
		current = current->next;
	}

	return i;
}

void removeLast(LinkedList *ls){
	if(isEmpty(ls)) return;
	Node *current = ls->head;

	if(current->next == NULL){
		free(current);
		ls->head = NULL;
		return;
	}

	while(current->next->next != NULL){
		current = current->next;
	}

	free(current->next);
	current->next = NULL;
}

void insertAtBeginning(LinkedList *ls, int n){
	Node *new = (Node *)malloc(sizeof(Node));
	if(new == NULL) return;
	new->data = n;
	new->next = ls->head;
	ls->head = new;
}

int contains(LinkedList *ls, int n){
	Node *current = ls->head;

	while(current != NULL){
		if(current->data == n) return 1;
		current = current->next;
	}

	return 0;
}

int getAtIndex(LinkedList *ls, int index){
	int i = 0;
	Node *current = ls->head;

    while (current != NULL) {
        if (i == index) return current->data;
        current = current->next;
        i++;
    }

	return -1;
}

void printList(LinkedList *ls){
	if(isEmpty(ls)){
		printf("Empty List!\n");
		return;
	}
	Node *current = ls->head;
	while(current != NULL){
		printf("%d\n",current->data);
		current = current->next;
	}
}

Node* search(LinkedList *ls, int n){
	if(ls == NULL || isEmpty(ls)) return NULL;
	Node *current = ls->head;

	while(current != NULL){
		if(current->data == n) return current;
		current = current->next;
	}

	return NULL;
}

void removeFirst(LinkedList *ls){
	if(isEmpty(ls)) return;
	Node *temp = ls->head;
	ls->head = ls->head->next;
	free(temp);
}
