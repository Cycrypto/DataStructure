#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void StackInit(Stack* s)
{
	s->head = NULL;
}

int SIsEmpty(Stack* s)
{
	if (s->head == NULL)
		return TRUE;

	else
		return FALSE;
}

void SPush(Stack* s, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = s->head;

	s->head = newNode;
}

Data SPop(Stack* s)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(s)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = s->head->data;
	rnode = s->head;

	s->head = s->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* s)
{
	if (SIsEmpty(s)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return s->head->data;
}