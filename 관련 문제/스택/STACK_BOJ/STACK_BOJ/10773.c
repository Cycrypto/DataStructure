#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 100000
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct {
	int data[MAXSIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

void push(StackType* s, element item) {
	if (s->top == MAXSIZE) {
		fprintf(stderr, "OVERFLOW\n");
		exit(-1);
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s){
	if (s->top == -1) {
		fprintf(stderr, "UNDERFLOW\n");
		exit(-1);
	}
	return s->data[(s->top)--];
}
int main(void) {
	int iter = 0;
	int sum = 0;
	StackType S;
	init(&S);

	scanf("%d", &iter);
	for (int i = 0; i < iter; i++) {
		int input = 0;
		scanf("%d", &input);
		if (input == 0) {
			pop(&S);
		}

		else {
			push(&S, input);
		}
	}
	while (S.top != -1) {
		sum += pop(&S);
	}
	printf("%d", sum);
}