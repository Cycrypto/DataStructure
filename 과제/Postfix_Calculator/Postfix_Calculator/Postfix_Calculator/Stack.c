#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(Stack* s) {
	s->head = NULL;
}

void StackPush(Stack* s, Data d) {
	StackNode* new_node = (StackNode*)malloc(sizeof(Node));
	new_node->data = d;
	new_node->next = s->head;
	s->head = new_node;
}

Data StackPop(Stack* s) {
	Data rdata;
	Node* rnode;

	rdata = s->head->data;
	rnode = s->head;

	s->head = s->head->next;
	free(rnode);
	return rdata;
}

int Stack_empty(Stack* s) {
	return s->head == NULL;
}

Data peek(Stack* s) {
	if (Stack_empty(s)) {
		fprintf(stderr, "stack is empty");
	}

	else {
		return s->head->data;
	}
}