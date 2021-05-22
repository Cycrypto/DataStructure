#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct _node {
	int data;
	struct _node* next;
}Node;

bool is_empty(Node* n) {
	return (n == NULL);
}

int is_size(Node* n, Node* tail) {
	Node* temp = n;
	int size = 0;
	while (temp != tail) {
		temp = temp->next;
		size++;
	}
	printf("size : %d\n", size += 1);
	return size;
}

Node* add(Node* head, Node* tail, int cur, int item) {
	Node* temp = head;
	if (cur >= 0 && cur < is_size(head, tail)) {
		for (int i = 0; i < cur - 1; i++) {
			temp = head->next;
		}
		//printf("[*]%d\n", temp->data);
		Node* p = (Node*)malloc(sizeof(Node));
		p->next = temp->next;
		temp->next = p;
		p->data = item;

	}

	else {	// 맨 뒤에 추가 (append)
		Node* p = (Node*)malloc(sizeof(Node));
		tail = tail->next = p;
		p->next = head->next;	//head의 첫번째 요소를 가르킴
		p->data = item;

	}
	return tail;
}

void print(Node* n) {
	Node* temp = n->next;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	free(temp);
}
int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	head = tail = (Node*)malloc(sizeof(Node));

	while (1) {
		int item = 0, pos = 0;
		scanf("%d %d", &item, &pos);
		if (item < 0)
			break;

		else
			tail = add(head, tail, pos, item);
	}
	print(head);

}