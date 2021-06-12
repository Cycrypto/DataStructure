#ifndef __STACK__
#define __STACK__
#include "Tree.h"

#define TRUE	1
#define FALSE	0

typedef Tree* Data;

typedef struct _node{
	Data data;
	struct _node* next;
} Node;

typedef struct _Stack{
	Node* head;
} Stack;


void StackInit(Stack*);
int SIsEmpty(Stack*);

void SPush(Stack*, Data );
Data SPop(Stack*);
#endif