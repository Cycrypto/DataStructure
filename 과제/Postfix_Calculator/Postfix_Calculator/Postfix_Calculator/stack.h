#pragma once
#include "tree.h"

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}StackNode;

typedef struct _stack {
	StackNode* head;
}Stack;

int Stack_empty(Stack*);
void StackInit(Stack*);
void StackPush(Stack*, Data);
Data StackPop(Stack*);
Data peek(Stack*);