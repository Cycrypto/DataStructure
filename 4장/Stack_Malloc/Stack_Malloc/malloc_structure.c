#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100

#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct {
	element *data;
	int capacity;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;	//2배로 늘리는게 부하 관련해서 훨씬 경제적임
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Error - STACK IS EMPTY!");
		exit(-1);
	}
	return s->data[(s->top)--];
}

int main(void) {
	StackType* Stack;
	init_stack(&Stack);

	push(&Stack, 1);
	push(&Stack, 2);
	push(&Stack, 3);

	printf("%d \n", pop(&Stack));
	printf("%d \n", pop(&Stack));
	printf("%d \n", pop(&Stack));
	free(Stack->data);
	
	return 0;
}