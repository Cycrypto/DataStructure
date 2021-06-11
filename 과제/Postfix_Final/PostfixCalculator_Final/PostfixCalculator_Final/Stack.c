#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void SInit(Stack* s) {
	s->head = NULL;
}

void SPush(Stack* s, Data d) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = d;
	new_node->next = s->head;
	s->head = new_node;
}

Data SPop(Stack* s) {
	Data rdata;
	StackNode* rnode;

	rdata = s->head->data;
	rnode = s->head;

	s->head = s->head->next;
	free(rnode);
	return rdata;
}

int SIsEmpty(Stack* s) {
	return s->head == NULL;
}


Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}