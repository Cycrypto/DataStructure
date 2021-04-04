#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100

#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	/*for (int i = 0; i < MAX_STACK_SIZE; i++) {
		s->data[i] = NULL;
	}*/
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "STACK IS FULL!");
		exit(-1);
	}
	
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "STACK IS EMPTY!");
		exit(-1);
	}
	else {
		element re = s->data[s->top];
		s->data[s->top] = NULL;
		(s->top)--;
		return re;
	}
}

int main(void) {
	StackType Stack;
	init_stack(&Stack);
	for (int i = 0; i < 100; i++) {
		push(&Stack, i);
		printf("push [%d] -> %d\n", Stack.top, Stack.data[i]);
	}
	printf("=====================================\n");
	
	for (int i = 0; i < 100; i++) {
		printf("pop [%d] -> %d\n",Stack.top, pop(&Stack));
	}
}