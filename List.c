/*
Author: Evandro Policarpo 
Creation: 07/07/2025
Description: Implementation of a Dynamic List Data Structure
Last Modify: 20/07/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// =======================
// Struct
// =======================
typedef struct {
    int *elements;
    int capacity;
    int size;
} DynamicList;

// =======================
// Function Prototypes
// =======================
int destroyList(DynamicList *list);
int getElement(DynamicList *list, int index, int *out);
int getPosition(DynamicList *list, int value);
int initializeList(DynamicList *list, int initialCapacity);
int insertAt(DynamicList *list, int index, int value);
int insertEnd(DynamicList *list, int value);
int insertStart(DynamicList *list, int value);
int isEmpty(DynamicList *list);
int isFull(DynamicList *list);
int listCapacity(DynamicList *list);
int printList(DynamicList *list);
int removeAt(DynamicList *list, int index);
int removeEnd(DynamicList *list);
int removeStart(DynamicList *list);
int resizeList(DynamicList *list, int newCapacity);

// =======================
// Function Implementations
// =======================

// Destroys the list and frees memory
int destroyList(DynamicList *list) {
    if (!list || !list->elements) return 0;
    free(list->elements);
    list->elements = NULL;
    list->capacity = 0;
    list->size = 0;
    return 1;
}

// Returns 1 if the list is empty, 0 otherwise
int isEmpty(DynamicList *list) {
    return list && list->size == 0;
}

// Returns 1 if the list is full, 0 otherwise
int isFull(DynamicList *list) {
    return list && list->size == list->capacity;
}

// Returns the capacity of the list
int listCapacity(DynamicList *list) {
    return list ? list->capacity : 0;
}

// Initializes a list with a given initial capacity
int initializeList(DynamicList *list, int initialCapacity) {
    if (initialCapacity <= 0) return 0;
    list->elements = malloc(initialCapacity * sizeof(int));
    if (!list->elements) return 0;
    list->capacity = initialCapacity;
    list->size = 0;
    return 1;
}

// Resizes the list to a new capacity
int resizeList(DynamicList *list, int newCapacity) {
    if (!list || newCapacity <= 0) return 0;
    int *newElements = realloc(list->elements, newCapacity * sizeof(int));
    if (!newElements) return 0;
    list->elements = newElements;
    list->capacity = newCapacity;
    if (list->size > newCapacity) list->size = newCapacity;
    return 1;
}

// Inserts an element at the start of the list
int insertStart(DynamicList *list, int value) {
    if (!list) return 0;
    if (isFull(list) && !resizeList(list, list->capacity * 2)) return 0;
    for (int i = list->size; i > 0; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[0] = value;
    list->size++;
    return 1;
}

// Inserts an element at the end of the list
int insertEnd(DynamicList *list, int value) {
    if (!list) return 0;
    if (isFull(list) && !resizeList(list, list->capacity * 2)) return 0;
    list->elements[list->size++] = value;
    return 1;
}

// Inserts an element at a specific index
int insertAt(DynamicList *list, int index, int value) {
    if (!list || index < 0 || index > list->size) return 0;
    if (isFull(list) && !resizeList(list, list->capacity * 2)) return 0;
    for (int i = list->size; i > index; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = value;
    list->size++;
    return 1;
}

// Removes the first element of the list
int removeStart(DynamicList *list) {
    if (!list || isEmpty(list)) return 0;
    for (int i = 0; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
    return 1;
}

// Removes the last element of the list
int removeEnd(DynamicList *list) {
    if (!list || isEmpty(list)) return 0;
    list->size--;
    return 1;
}

// Removes an element at a specific index
int removeAt(DynamicList *list, int index) {
    if (!list || isEmpty(list) || index < 0 || index >= list->size) return 0;
    for (int i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
    return 1;
}

// Retrieves an element at a specific index
int getElement(DynamicList *list, int index, int *out) {
    if (!list || index < 0 || index >= list->size || out == NULL) return 0;
    *out = list->elements[index];
    return 1;
}

// Finds the position of a value in the list, -1 if not found
int getPosition(DynamicList *list, int value) {
    if (!list) return -1;
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i] == value) return i;
    }
    return -1;
}

// Prints all elements in the list
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
