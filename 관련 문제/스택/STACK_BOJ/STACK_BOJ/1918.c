#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct {
	int size;
	element* data;
	int top;
}StackType;

void init(StackType* s) {
	s->size = 1;
	s->top = -1;
	s->data = (element*)malloc(sizeof(element) * s->size);
}

int is_full(StackType* s) {
	return (s->top == s->size - 1);
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, element* item) {
	if (is_full(s)) {
		s->size *= 2;
		s->data = (element*)realloc(s->data, sizeof(element) * s->size);
	}
	s->data[++(s->top)] = *item;
}

element pop(StackType* s) {
	if (s->top == -1) {
		return -1;
	}

	else{
		return s->data[(s->top)--];
	}
}

int priority(char* ch) {
	switch (*ch)
	{
	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;

	default:
		return -1;
	}
}

void calculate(StackType* s, char* infix) {	//infix : 입력값, postfix : 변환값
	char *c;

	for (int i = 0; i < strlen(infix); i++) {
		switch (infix[i]) {
		case '+': case '-': case '*': case '/':

			while (!is_empty(&(*s)) && priority(&infix[i]) <= priority(&(s->data[s->top]))) {
				printf("%c", pop(&(*s)));
			}
			push(&(*s), &infix[i]);
			break;

		case '(':
			push(&(*s), &infix[i]);
			break;

		case ')':	// #issue
			c = &(s->data[s->top]);
			while (*c != *"(") {
				printf("%c", pop(&(*s)));
				c = &(s->data[s->top]);
			}
			pop(&(*s));
			break;

		default:
			printf("%c", infix[i]);
			break;
		}
	}

	while (s->top != -1) {
		printf("%c", pop(&(*s)));
	}
}

int main(void) {
	StackType Stack;
	init(&Stack);
	char value[100] = { 0, };
	scanf("%s", value);
	int idx = 0;
	calculate(&Stack, value);
}