#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct {
	element data[10000];
	int start;
	int rear;
}QueueType;

void init(QueueType* q) {
	q->start = -1;
	q->rear = -1;
}

int size(QueueType* q) {
	return (q->rear - q->start);
}

int empty(QueueType* q) {
	return q->start == q->rear;
}


void push(QueueType* q, element item) {
	q->data[++(q->rear)] = item;
}

element pop(QueueType* q) {
	if (empty(q)) {
		return -1;
	}

	else
		return q->data[++(q->start)];
}


element front(QueueType* q) {
	if (empty(q))
		return -1;

	else
		return q->data[q->start + 1];
}

element back(QueueType* q) {
	if (empty(q))
		return -1;
	else
		return q->data[q->rear];
}


int main(void) {
	int N = 0;
	char* cmd = malloc(sizeof(char) * 10);
	QueueType Queue;
	init(&Queue);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int value = 0;
		scanf("%s", cmd);

		if (!strcmp(cmd, "push")) {
			scanf("%d", &value);
			push(&Queue, value);
		}
		else if (!strcmp(cmd, "pop")) {
			printf("%d\n", pop(&Queue));
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", size(&Queue));
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", empty(&Queue));
		}
		else if (!strcmp(cmd, "front")) {
			printf("%d\n", front(&Queue));
		}
		else if (!strcmp(cmd, "back")) {
			printf("%d\n", back(&Queue));
		}
		else {
			printf("error\n");
		}
	}
	free(cmd);
}