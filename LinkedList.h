#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Estrutura de um nó
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Estrutura da lista
typedef struct {
    Node *head;
} LinkedList;

// Funções da lista
void insertAtBeginning(LinkedList *ls, int value);
void insertAtEnd(LinkedList *ls, int value);
void insertAtIndex(LinkedList *ls, int value, int index);
void freeList(LinkedList *ls);
int  isEmpty(LinkedList *ls);
void printList(LinkedList *ls);
void removeIndex(LinkedList *ls, int index);
void removeFirst(LinkedList *ls);
void removeLast(LinkedList *ls);


#endif
