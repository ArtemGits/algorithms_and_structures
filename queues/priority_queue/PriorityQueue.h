#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <stdlib.h>

struct Task {
	int task_id;
	int priority;
};

struct Heap {
	int capacity;
	int size;
	struct Task **data;
};

typedef struct Heap *heap_type;
typedef struct Task *task_type;

void swap_heap(heap_type heap,int pos1,int pos2);

heap_type create_heap(int capacity);
void insert_in_heap(heap_type heap,struct Task *newtask);

int empty_heap(heap_type heap);

int full_heap(heap_type heap);

void hold_heap(heap_type heap,int pos);
void decrease_priority(heap_type heap,int where,int priority);
void increase_priority(heap_type heap,int where,int priority);

#endif
