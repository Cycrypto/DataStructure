#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
	char Name[20];
	int Age;
	int height;
	struct _node* next;
}Node;

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	head = tail;	//head와 tail을 연결

	for (int i = 0; i < 4; i++) {
		if (head == NULL) {
			char s[20] = { NULL, };
			head = tail = (Node*)malloc(sizeof(Node));
			i--;
		}

		else {
			char s[20] = { NULL, };
			tail->next = (Node*)malloc(sizeof(Node));
			printf("Name : ");
			scanf("%s", tail->Name);

			printf("Age : ");
			scanf("%d", &tail->Age);

			printf("Height : ");
			scanf("%d", &tail->height);

			tail = tail->next;
			tail->next = NULL;
		}
	}
	
	printf("\n---------------------------\n");

	while (head->next != NULL) {
		
		printf("이름 : %s\n", head->Name);
		printf("나이 : %d\n", head->Age);
		printf("키 : %d\n", head->height);
		printf("*************\n");
		head = head->next;
	}
}