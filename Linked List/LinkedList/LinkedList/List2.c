#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

Node* insert(Node* head, Node* tail, int item) {

	if (head == NULL) {
		printf("NULL\n");
		head = tail = (Node*)malloc(sizeof(Node));
	}
	else {
		tail = tail->next = (Node*)malloc(sizeof(Node));
		tail->data = item;
		tail->next = NULL;
	}
	return tail;
}



void display(Node* head) {
	Node* p = head->next;
	while (p->next != NULL) {
		printf("%d ->", p->data);
		p = p->next;

	}
	printf("%d", p->data);
	printf("\n");
}

Node* sort(Node* phead)
{
	Node* p, * temp;
	p = phead;

	while (p->next != NULL) {
		if (p->data > p->next->data)
		{
			temp = p->next;
			p->next = p->next->next;
			temp->next = phead;
			phead = p = temp;
			continue;
		}
		p = p->next;
	}
	return phead;
}

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	head = tail = (Node*)malloc(sizeof(Node));
	for (int i = 5; i > 0; i--) {
		int input = 0;
		scanf("%d", &input);
		tail = insert(head, tail, input);
	}
	sort(head);
	printf("MAX : %d, MIN : %d", tail->data, head->next->data);
}
