#ifndef LIST_H
#define LIST_H

// Struct da lista
typedef struct List {
	int currentPosition;
	int size;
	int nums[];  // array de tamanho flexível
} List;

// "Construtor" da lista
List* start(int n);

// função add
void add(List *ls, int n);

// getSize
int getSize(List ls);

//pop
int pop(List *ls);

// (opcional) Destrutor
void destroy(List* ls);

#endif
