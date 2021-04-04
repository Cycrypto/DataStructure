#include <stdio.h>
#include <stdlib.h>

// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 


int main(void)
{
	StackType Stack;
	init_stack(&Stack);
	for (int i = 0; i < 100; i++) {
		push(&Stack, i);
		printf("push [%d] -> %d\n", Stack.top, Stack.data[i]);
	}
	printf("=====================================\n");

	for (int i = 0; i < 100; i++) {
		printf("pop [%d] -> %d\n", Stack.top, pop(&Stack));
	}
	printf("free data [%d]", Stack.data[1]);
}
