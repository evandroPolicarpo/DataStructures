/*
Evandro Policarpo 07D/07M/2025Y 13:00 UTC-3
Implementation of a List Data Structure
Last Modify: 08D/07M/2025Y 10:01 UTC-3
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Lista de inteiros
typedef struct List{
	int currentPosition;						// Posição do último elemento
	int size;									// Tamanho da lista
	int nums[];									// Malloc/Realloc
} List;

List* start(int n){
	List *ls = malloc(sizeof(List) + n * sizeof(int));
	// if(!ls)
	ls->currentPosition = 0;
	ls->size = n;
	return ls;
}

void add(List *ls, int n){
	if(ls->currentPosition == ls->size) return;
	ls->nums[ls->currentPosition] = n;
	ls->currentPosition++;
}

int getSize(List ls){
	return ls.currentPosition;
}

int pop(List *ls){
	return ls->nums[ls->currentPosition - 1];
}

void destroy(List *ls){
	free(ls);
}