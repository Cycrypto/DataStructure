#define _CRT_SECURE_NO_WARNINGS
#define PARENT(x) x/2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
}element;

typedef struct {
	element heap[MAXSIZE];
	int size;
}Heap;

Heap* create(void) {
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->size = 0;
}

void insert_up(Heap* h, element item) {
	int i = ++(h->size);
	while (i != 1 && item.data > h->heap[PARENT(i)].data) {
		h->heap[i] = h->heap[PARENT(i)];
		i = PARENT(i);
	}
	h->heap[i] = item;
}

element delete_heap(Heap* h) {
	int parent = 1, child = 2;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->size--];

	while (child <= h->size) {
		if ((child < h->heap[child + 1].data) && (h->heap[child].data < h->heap[child + 1].data))
			child++;

		if (temp.data >= h->heap[child].data)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void asc(element* h, int size) {
	Heap* space = create();
	init(space);
	for (int i = 0; i < size; i++) {
		insert_up(space, h[i]);
	}
	for (int i = 0; i < size; i++) {
		h[i] = delete_heap(space);
	}
}

int main(void) {
	element e[] = { 1,4,2,7,6,3,2,5 };
	int size = sizeof(e) / sizeof(element);
	asc(e, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", e[i].data);
	}
}