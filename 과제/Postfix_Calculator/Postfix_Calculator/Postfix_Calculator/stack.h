#pragma once
#include "tree.h"

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}StackNode;

typedef struct _stack {
	StackNode* head;
}TreeStack;

int Stack_empty(TreeStack*);
void StackInit(TreeStack*);
void StackPush(TreeStack*, Data);
Data StackPop(TreeStack*);
Data peek(TreeStack*);