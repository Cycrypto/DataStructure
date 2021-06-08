#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define PARENT(x) x/2

Heap* create(void) {
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->heap_size = 0;
}

void up_heap(Heap* h, Key item) {
	int i = ++(h->heap_size);
	while (i != 1 && item.key > h->heap[PARENT(i)].key) {
		h->heap[i] = h->heap[PARENT(i)];
		i = PARENT(i);
	}
	h->heap[i] = item;
}

void down_heap(Heap* h, Key item) {
	int i = ++(h->heap_size);
	while (i != 1 && item.key < h->heap[PARENT(i)].key) {
		h->heap[i] = h->heap[PARENT(i)];
		i = PARENT(i);
	}
	h->heap[i] = item;
}

Key delete_heap(Heap* h, bool is_up) {
	int parent = 1, child = 2;
	Key item, temp;
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
