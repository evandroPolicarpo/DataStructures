/*
Author: Evandro Policarpo 
Creation: 07D/07M/2025Y 13:00 UTC-3
Description: Implementation of a List Data Structure
Last Modify: 20D/07M/2025Y 10:43 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>
#include <list.h>

typedef struct {
    int *elements;
    int capacity;
    int size;
} DynamicList;

// === Function Prototypes ===
int  destroyList(DynamicList *list);
int  getElement(DynamicList *list, int index, int *out);
int  getPosition(DynamicList *list, int value);
int  initializeList(DynamicList *list, int initialCapacity);
int  insertAt(DynamicList *list, int index, int value);
int  insertEnd(DynamicList *list, int value);
int  insertStart(DynamicList *list, int value);
int  isEmpty(DynamicList *list);
int  isFull(DynamicList *list);
int  listCapacity(DynamicList *list);
int  printList(DynamicList *list);
int  removeAt(DynamicList *list, int index);
int  removeEnd(DynamicList *list);
int  removeStart(DynamicList *list);
int  resizeList(DynamicList *list, int newCapacity);

// === Implementations ===

int initializeList(DynamicList *list, int initialCapacity) {
    if (initialCapacity <= 0) return 0;
    list->elements = malloc(initialCapacity * sizeof(int));
    if (!list->elements) return 0;
    list->capacity = initialCapacity;
    list->size = 0;
    return 1;
}

int destroyList(DynamicList *list) {
    if (!list || !list->elements) return 0;
    free(list->elements);
    list->elements = NULL;
    list->capacity = 0;
    list->size = 0;
    return 1;
}

int isEmpty(DynamicList *list) {
    return list && list->size == 0;
}

int isFull(DynamicList *list) {
    return list && list->size == list->capacity;
}

int listCapacity(DynamicList *list) {
    return list ? list->capacity : 0;
}

int resizeList(DynamicList *list, int newCapacity) {
    if (!list || newCapacity <= 0) return 0;
    int *newElements = realloc(list->elements, newCapacity * sizeof(int));
    if (!newElements) return 0;
    list->elements = newElements;
    list->capacity = newCapacity;
    if (list->size > newCapacity) list->size = newCapacity;
    return 1;
}

int insertEnd(DynamicList *list, int value) {
    if (!list) return 0;
    if (isFull(list)) {
        if (!resizeList(list, list->capacity * 2)) return 0;
    }
    list->elements[list->size++] = value;
    return 1;
}

int insertStart(DynamicList *list, int value) {
    if (!list) return 0;
    if (isFull(list)) {
        if (!resizeList(list, list->capacity * 2)) return 0;
    }
    for (int i = list->size; i > 0; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[0] = value;
    list->size++;
    return 1;
}

int insertAt(DynamicList *list, int index, int value) {
    if (!list || index < 0 || index > list->size) return 0;
    if (isFull(list)) {
        if (!resizeList(list, list->capacity * 2)) return 0;
    }
    for (int i = list->size; i > index; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = value;
    list->size++;
    return 1;
}

int removeEnd(DynamicList *list) {
    if (!list || isEmpty(list)) return 0;
    list->size--;
    return 1;
}

int removeStart(DynamicList *list) {
    if (!list || isEmpty(list)) return 0;
    for (int i = 0; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
    return 1;
}

int removeAt(DynamicList *list, int index) {
    if (!list || isEmpty(list) || index < 0 || index >= list->size) return 0;
    for (int i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
    return 1;
}

int getElement(DynamicList *list, int index, int *out) {
    if (!list || index < 0 || index >= list->size || out == NULL) return 0;
    *out = list->elements[index];
    return 1;
}

int getPosition(DynamicList *list, int value) {
    if (!list) return -1;
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i] == value) return i;
    }
    return -1;
}

int printList(DynamicList *list) {
    if (!list) return 0;
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return 1;
    }
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->elements[i]);
    }
    printf("\n");
    return 1;
}
