#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node* link;	//다음 요소를 가르킬 포인터
}Node;

Node* insert(Node* list, Node* pos, int item);
Node* insert_last(Node* list, int item);
Node* insert_first(Node* list, int head);
Node* delete(Node* list, int pos);
Node* get_entry(Node* list, int pos);
void print_list(Node* list);

int main(void) {
	Node* head = NULL;
	int input = 0;
	int option = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d %d",&option, &input);
		if (option == 1)
			head = insert_first(head, input);
		
		else {
			int idx = 0;
			scanf("%d", &idx);
			Node* search = head;
			head = insert(head,idx, input);
		}

		print_list(head);
	}
}


Node* insert(Node* list, Node* pos, int item) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = pos->link;
	pos->link = p;
	return list;
}

Node* insert_first(Node* head, int item) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
void print_list(Node* head) {
	while (head->link != NULL) {
		printf("%d ", head->data);
		head = head->link;
	}
	printf("\n************\n");
}