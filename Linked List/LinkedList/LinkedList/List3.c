#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 	// ����Ʈ�� �ִ�ũ��

typedef int element;			// �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE];	  // �迭 ����
	int size;		  // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L)
{
	L->size = 0;
}
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType* L)
{
	return L->size == 0;
}
// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

// ����Ʈ ���
void display(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size - 1; i++)
		printf("%d->", L->array[i]);
	printf("%d", L->array[L->size - 1]);
	printf("\n");
}
void add(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;

	for (int i = 0; i < L->size; i++) {
		for (int j = 0; j < L->size - (i + 1); j++) {
			if (L->array[j] > L->array[j+1]) {
				element temp = L->array[j + 1];
				L->array[j + 1] = L->array[j];
				L->array[j] = temp;
			}
		}
	}
}

element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

element is_in_list(ArrayListType* L, element item) {

	for (int i = 0; i < L->size; i++) {
		if (L->array[i] == item)
			return 1;
	}

	return 0;
}
void clear(ArrayListType* L) {
	for (int i = 0; i < MAX_LIST_SIZE; i++) {
		L->array[i] = 0;
	}
	L->size = 0;
}

int get_length(ArrayListType* L) {
	return L->size;
}

int main(void)
{
	// ArrayListType�� �������� �����ϰ� ArrayListType�� 	
	// ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	ArrayListType list;

	init(&list);
	for (int i = 5; i > 0; i--) {
		element item = 0;
		scanf("%d", &item);
		add(&list, item);
		display(&list);
	}

	return 0;
}