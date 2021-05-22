#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
typedef struct _node {
	char arr[MAX];
	int size;
}Node;

void init(Node* N) {   //Node initialize
	N->size = 0;
}

int is_full(Node* N) {
	return N->size == MAX;
}

int add(Node* L, int pos, char item)
{

	if (!is_full(L) && (pos >= 0)) {
		for (int i = (L->size); i >= pos; i--)
			L->arr[i + 1] = L->arr[i];
		L->arr[pos] = item;
		L->size++;
		return 1;
	}
	return 0;
}

int del(Node* N, int pos)
{
	char item;
	if (pos < 0 || pos >= N->size)
		return 1;

	item = N->arr[pos];
	for (int i = pos; i < (N->size); i++)
		N->arr[i] = N->arr[i + 1];
	N->size--;
	return 0;
}

int get(Node* L, char item) {
	for (int i = 1; i <= L->size + 1; i++) {
		//printf("%c\n%c\n\n",L->arr[i], item);
		if (L->arr[i] == item)
			return 1;
	}
	return -1;
}

int mod(Node* N, element pos, char item) {
	if (pos < 0 || pos >= N->size)
		return 1;

	N->arr[pos] = item;
	return 0;
}

void print(Node* N)
{
	int i;
	for (i = 1; i <= N->size; i++)
		printf("%c ", N->arr[i]);
	printf("\n");
}

int main(void) {
	Node N;
	init(&N);   // Node √ ±‚»≠

	int iter = 0;
	char opt = 0;
	char item = 0;
	int flag = 0, pos = 0;

	scanf("%d", &iter);
	getchar();
	for (int i = 0; i < iter; i++) {
		scanf("%c", &opt);
		getchar();
		switch (opt) {
		case 'A':
			scanf("%d %c",&pos, &item);
			getchar();
			flag = add(&N,pos, item);

			if (flag == 0) {
				printf("invalid\n");
				i--;
			}
			break;

		case 'D':
			scanf("%d", &pos);
			getchar();
			flag = del(&N, pos);

			if (flag == 1) {
				printf("invalid\n");
				i--;
			}
			break;

		case 'G':
			scanf("%c", &item);
			getchar();
			flag = get(&N, item);
			if (flag == -1) {
				printf("invalid\n");
				i--;
			}
			break;

		case 'M':
			scanf("%d %c", &pos, &item);
			getchar();
			flag = mod(&N, pos, item);
			break;

		case 'P':
			printf(">>");
			print(&N);
			break;
		default:
			printf("fuck\n");
			break;
		}
	}
}