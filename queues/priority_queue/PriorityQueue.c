#include <stdlib.h>
#include "PriorityQueue.h"


struct Task *create_task(int taskid, int priority) {
	struct Task *task = malloc(siziof(struct Task));
	if(task) {
		task->taskid = taskid;
		task->priority = priority;
	}
	return task;
}

heaptype create_heap(int capacity) {
	heaptype heap = malloc(sizeof(struct Heap));
	if(!heap) {
		printf("When this calling?");
		return heap;
	}
	heap->size = 0;
	heap->capacity = capacity;
	heap->data = malloc(sizeof(struct Task *) * capacity)
	return heap;
}

void insert_in_heap(heaptype heap, tasktype task) {
	int current_pos = heap->size;
	int parrent_pos;

	if(is_Empty(heap))
		return
	heap->data[heap->size] = task;
	heap->size++;
	check_heap();
}

int is_Empty(heaptype heap) {
	if (heap->size != 0) {
		return heap->size;
	} else {
		printf("Error! Queue is empty");
		return NULL; 
	}

}

void swap_heap(heaptype heap, current_pos, parrent_pos) {
	tasktype tmp = heap->data[current_pos];
	heap->data[current_pos] = heap->data[parrent_pos];
	heap->data[parrent_pos] = tmp;
}

void increase_priority(heaptype heap, int task_id, int priority) {
	where = get_task_by_id(heap, task_id); //position

	if(where == -1 || is_Empty() || heap->data[where]->priority >= priority)
		return;

	heap->data[where]->priority = priority;
	check_heap();
}

void decrease_priority(heaptype heap, int taskid, int priority) {
	where = get_task_by_id(heap, task_id); //position

	if(where == -1 || is_Empty() || heap->data[where]->priority <= priority)
		return;

	heap->data[where]->priority = priority;
	
}

void check_heap(heaptype heap) {
	// Смотрим чтобы у всей кучи приоритеты были по убыванию
	while( (parrent_pos = ((heap->size - 1) >> 1) >= 0 && 
		heap->data[current_pos]->priority > 
		heap->data[parrent_pos]->priority) ) {
		swap_heap(heap, current_pos, parrent_pos);
		current_pos = parrent_pos;
	}
}
