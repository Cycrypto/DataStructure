#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 999999999

#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct {
	long int data[MAX_SIZE];
	int front;
	int rear;
}QueueType;

void init(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

int empty(QueueType* q) {
	return (q->front ==	q->rear);
}

void push(QueueType* q, element item) {
	q->data[++(q->rear)] = item;
}

element pop(QueueType* q) {
	return q->data[++(q->front)];
}

int main(void) {
	QueueType q;
	init(&q);

	int iter, yos = 0;
	scanf("%d %d", &iter, &yos);
	for (int i = 1; i <= iter; i++) {
		push(&q, i);
	}	// yos(N,K)만큼을 큐에 저장 <1,2,3,4,5,6,7>
	printf("<");
	for (int j = 0; j < iter-1; j++) {
		/*for (int p = q.front; p < q.rear; p++) {
			printf("%d ", q.data[p]);
		}*/
		for (int i = 0; i < yos - 1; i++) {
			push(&q, pop(&q));
		}
		printf("%d, ", pop(&q));
	}
	printf("%d>", pop(&q));
	return 0;
}