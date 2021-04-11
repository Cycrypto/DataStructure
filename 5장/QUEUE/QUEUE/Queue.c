#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_SIZE];
}Queue;

void init(Queue* q) {
	q->rear = -1;
	q->front = -1;
}

int is_full(Queue* q) {
	return (q->rear == MAX_SIZE - 1);
}

int is_empty(Queue* q) {
	return (q->rear == q->front);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "OVERFLOW!\n");
		exit(-1);
	}
	else {
		return q->data[++(q->rear)] = item;
	}
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "UNDERFLOW\n");
		exit(-1);
	}
	else {
		return q->data[++(q->front)];
	}
}
element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "UNDERFLOW\n");
		exit(-1);
	}
	else {
		return q->data[q->front + 1];
	}
}
void queue_print(Queue* q) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf("  |");
		}
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n\n");
}

int main(void) {
	int item = 0;
	Queue Q;
	init(&Q);

	enqueue(&Q, 10); queue_print(&Q);
	enqueue(&Q, 20); queue_print(&Q);
	enqueue(&Q, 30); queue_print(&Q);

	item = dequeue(&Q); queue_print(&Q);
	item = dequeue(&Q); queue_print(&Q);
	item = dequeue(&Q); queue_print(&Q);
}