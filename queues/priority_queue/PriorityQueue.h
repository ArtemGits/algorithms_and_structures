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
task_type create_task(int, int);
void insert_in_heap(heap_type heap,struct Task *newtask);
void print_heap(heap_type);
int is_Empty(heap_type heap);

int full_heap(heap_type heap);
void check_heap(heap_type, int, int);
void hold_heap(heap_type heap);

void decrease_priority(heap_type heap,int where,int priority);
void increase_priority(heap_type heap,int where,int priority);
task_type delete_min(heap_type heap);
void destroy_heap(heap_type heap);
#endif
