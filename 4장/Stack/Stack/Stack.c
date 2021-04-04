#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define ERROR_STACKFULL -1
#define ERROR_STACKEMPTY -2
/*
error 목록
return -1 : ERROR_STACKFULL
return -2 : ERROR_STACKEMPTY
*/

#include <stdio.h>

typedef int element;
element stack[MAX_STACK_SIZE];	// stack 생성
int idx = -1;
int item = 0;

int is_full() {
	if (idx + 1 == MAX_STACK_SIZE)
		return 1;
	else
		return 0;
}

int is_empty() {
	if (idx == -1)
		return 1;
	else
		return 0;
}

int push(element *s, int item) {
	if (is_full())
		return ERROR_STACKFULL;

	else {
		s[idx++] = item;
		return 1;
	}
}

int pop(element* s) {
	printf("%d\n", idx);
	if (is_empty())
		return ERROR_STACKEMPTY;

	else s[idx--];
}

int peek(element* s) {
	return s[idx];
}

int main(void) {
	push(stack, 1);
	push(stack, 2);
	printf("%d", pop(stack));
}