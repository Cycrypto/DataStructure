#define _CRT_SECURE_NO_WARININGS
#define MAX_ELEMENT 200
#define PARENT(x)	x/2

#include <stdio.h>
#include <stdlib.h>
typedef struct _key {
	int key;
}element;

typedef struct _heap {
	element heap[MAX_ELEMENT];
	int heap_size;
}Heap;

Heap* create(void) {
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->heap_size = 0;
}

void up_heap(Heap* h, element item) {
	int i = ++(h->heap_size);
	while (i != 1 && item.key > h->heap[PARENT(i)].key) {
		h->heap[i] = h->heap[PARENT(i)];
		i = PARENT(i);
	}
	h->heap[i] = item;
}

void down_heap(Heap* h, element item) {
	int i = ++(h->heap_size);
	while (i != 1 && item.key < h->heap[PARENT(i)].key) {
		h->heap[i] = h->heap[PARENT(i)];
		i = PARENT(i);
	}
	h->heap[i] = item;
}

element delete_heap(Heap* h, int is_up) {
	int parent = 1, child = 2;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	if (is_up) {
		while (child <= h->heap_size) {
			if ((child < h->heap[child + 1].key) && (h->heap[child].key < h->heap[child + 1].key))
				child++;

			if (temp.key >= h->heap[child].key)
				break;

			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	else {
		while (child <= h->heap_size) {
			if ((child < h->heap[child + 1].key) && (h->heap[child].key > h->heap[child + 1].key))
				child++;

			if (temp.key <= h->heap[child].key)
				break;

			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	Heap* heap;

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

				// 삽입
	down_heap(heap, e1);
	down_heap(heap, e2);
	down_heap(heap, e3);

	// 삭제
	e4 = delete_heap(heap, 0);
	printf("< %d > ", e4.key);
	e5 = delete_heap(heap, 0);
	printf("< %d > ", e5.key);
	e6 = delete_heap(heap, 0);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}