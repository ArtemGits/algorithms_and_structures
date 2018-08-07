#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"


struct Task *create_task(int task_id, int priority) {
	struct Task *task = malloc(sizeof(struct Task));
	if(task) {
		task->task_id = task_id;
		task->priority = priority;
	}
	return task;
}

heap_type create_heap(int capacity) {
	heap_type heap = malloc(sizeof(struct Heap));
	if(!heap) {
		printf("When this calling?");
		return heap;
	}
	heap->size = 0;
	heap->capacity = capacity;
	heap->data = malloc(sizeof(struct Task *) * capacity);
	return heap;
}

void check_heap(heap_type heap) {
	// Смотрим чтобы у всей кучи приоритеты были по убыванию
	while( (parrent_pos = ((heap->size - 1) >> 1) >= 0 && 
		heap->data[current_pos]->priority > 
		heap->data[parrent_pos]->priority) ) {
		swap_heap(heap, current_pos, parrent_pos);
		current_pos = parrent_pos;
	}
}

void insert_in_heap(heap_type heap, task_type task) {
	int current_pos = heap->size;
	int parrent_pos;

	//if(empty_heap(heap))
		//return
	heap->data[heap->size] = task;
	heap->size++;
	check_heap(heap);
}

int is_Empty(heap_type heap) {
	if (heap->size != 0) {
		return heap->size;
	} else {
		printf("Error! Queue is empty");
		return NULL; 
	}

}

void swap_heap(heap_type heap,int current_pos, int parrent_pos) {
	task_type tmp = heap->data[current_pos];
	heap->data[current_pos] = heap->data[parrent_pos];
	heap->data[parrent_pos] = tmp;
}

void increase_priority(heap_type heap, int task_id, int priority) {
	where = get_task_by_id(heap, task_id); //position

	if(where == -1 || is_Empty() || heap->data[where]->priority >= priority)
		return;

	heap->data[where]->priority = priority;
	check_heap();
}

void decrease_priority(heap_type heap, int taskid, int priority) {
	where = get_task_by_id(heap, task_id); //position

	if(where == -1 || is_Empty() || heap->data[where]->priority <= priority)
		return;

	heap->data[where]->priority = priority;
	
}


