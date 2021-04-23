#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 5
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Queue{
	int rear;
	int front;
	element data[MAX_SIZE];
}Queue;

void init(Queue* q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(Queue* q) {
	return ((q->rear + 1) % MAX_SIZE) == q->front;
}

int is_empty(Queue* q) {
	return (q->rear == q->front);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		q->rear = 1;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}


element dequeue(Queue* q) {
	if (is_empty(q)) {
		exit(0);
	}
	return q->data[q->front = (q->front + 1) % MAX_SIZE];
}

element peek(Queue* q) {
	return q->rear;
}

void queue_print(Queue* q)
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (q->front < MAX_SIZE && q->rear < MAX_SIZE) {
			printf("!");
			if (i <= q->front || i > q->rear)
				printf("   | ");
			else
				printf("%d | ", q->data[i]);
		}

		else {
			if (i <= (q->front + 1) % MAX_SIZE || i > (q->rear + 1) % MAX_SIZE)
				printf("   | ");
			else
				printf("%d | ", q->data[i]);
		}
	}
	printf("\n");
}

int main(void) {
	Queue q;
	init(&q);
	int item = 0;

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	printf("\n$$ Secondary Enqueue\n");
	enqueue(&q, 1); queue_print(&q);
	enqueue(&q, 2); queue_print(&q);
	enqueue(&q, 3); queue_print(&q);
	enqueue(&q, 4); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);

}