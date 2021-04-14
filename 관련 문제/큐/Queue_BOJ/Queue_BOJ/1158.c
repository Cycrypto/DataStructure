#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5000

#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct {
	int data[MAX_SIZE];
	int front;
	int rear;
}QueueType;

void init(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

int empty(QueueType* q) {
	return q->front ==	q->rear;
}

void push(QueueType* q, element item) {
	q->data[(q->rear)++] = item;
}

element pop(QueueType* q, element* dec) {
	return q->data[(q->front)++];
}

int main(void) {
	QueueType q;
	int iter, yos = 0;
	scanf("%d", &iter);
	for (int i = 0; i < iter; i++) {
		push(&q, i);
	}	// yos(N,K)만큼을 큐에 저장 <1,2,3,4,5,6,7>
	
	while (empty(&q)) {

	}
}