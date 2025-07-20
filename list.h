#ifndef LIST_H
#define LIST_H

typedef struct {
    int *elements;
    int capacity;
    int size;
} DynamicList;

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

#endif // DYNAMIC_LIST_H
