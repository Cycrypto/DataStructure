#include <stdio.h>
#include <stdlib.h>
#include "Stack2.h"

void StackInit2(Stack2* s) {
	s->head = NULL;
}

void StackPush2(Stack2* s, Data* d) {
	StackNode2* new_node = (StackNode2*)malloc(sizeof(Node));
	new_node->data = d;
	new_node->next = s->head;
	s->head = new_node;
}

Data* StackPop2(Stack2* s) {
	Data* rdata;
	Node* rnode;

	rdata = s->head->data;
	rnode = s->head;

	s->head = s->head->next;
	free(rnode);
	return &rdata;
}

int Stack_empty2(Stack2* s) {
	return s->head == NULL;
}
