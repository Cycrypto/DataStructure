#include <stdbool.h>
typedef struct _key {
	int key;
}Key;

typedef struct _heap {
	Key* heap;
	int heap_size;
}Heap;

Heap* create(void);
void init(Heap* h);
void up_heap(Heap* h, Key item);
void down_heap(Heap* h, Key item);
Key delete_heap(Heap* h, bool is_up);