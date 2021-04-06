#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct {
	element* data;
	int size;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->size = 1;	//스택의 메모리 사이즈 / 실제 들어있는 값과는 차이가 있음
	s->data = (element)malloc(s->size * sizeof(element));
	s->top = -1;
}

void stack_push(StackType* s, element item) {
	if (s->size - 1 == s->top) {
		s->size *= 2;
		s->data = (element)realloc(s->data, s->size * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element stack_pop(StackType* s) {
	if (stack_empty(s)) {
		return -1;
	}

	else {
		return s->data[(s->top)--];
	}
}

element stack_size(StackType* s) {
	return s->top + 1;
}

int stack_empty(StackType* s) {
	return (s->top == -1);
}

int stack_top(StackType* s) {
	if (stack_empty(s))
		return -1;
	else
		return (s->data[s->top]);
}

int main(void) {
	StackType STACK;
	init_stack(&STACK);
	
	int iter = 0;
	scanf("%d", &iter);
	for (int i = 0; i < iter; i++) {
		char* func = malloc(sizeof(char) * 10);
		int param = 0;
		scanf("%s", func);
		if (!strcmp(func, "push")) {
			scanf("%d", &param);
			stack_push(&STACK, param);
		}

		else if (!strcmp(func, "pop")) {
			printf("%d\n", stack_pop(&STACK));
		}

		else if (!strcmp(func, "size")) {
			printf("%d\n", stack_size(&STACK));
		}

		else if (!strcmp(func, "empty")) {
			printf("%d\n", stack_empty(&STACK));
		}

		else {
			printf("%d\n", stack_top(&STACK));
		}
	}
}