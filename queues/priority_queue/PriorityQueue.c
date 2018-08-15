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
/*
void check_heap(heap_type heap, int current_pos, int parrent_pos) {
	// Смотрим чтобы у всей кучи приоритеты были по убыванию
	while((parrent_pos =(current_pos - 1) >> 1) >= 0 && 
		heap->data[current_pos]->priority > 
		heap->data[parrent_pos]->priority)  {
		swap_heap(heap, parrent_pos, current_pos);
		current_pos = parrent_pos;
	}
}
*/

void print_heap(heap_type heap) {
  int i;
  for(i = 0; i < heap->size; i++) {
    printf("Task ID %d, priority %d \n", heap->data[i]->task_id, heap->data[i]->priority);
  }
}

void insert_in_heap(heap_type heap, task_type task) {
	int current_pos = heap->size;
	int parrent_pos;

	//if(empty_heap(heap))
		//return
	heap->data[heap->size] = task;
	heap->size++;
//	check_heap(heap, current_pos, parrent_pos);
}


int is_Empty(heap_type heap) {
	if (heap->size != 0) {
		return heap->size;
	} else {
		printf("Error! Queue is empty");
		return -1; 
	}
}

int full_heap(heap_type heap){
	return heap->size==heap->capacity;
}

int get_task_by_id(heap_type heap,int id){
	int pos=-1;
	for(int i=0;i<heap->size && pos==-1;i++)
		if(heap->data[i]->task_id==id)
			pos=i;
	return pos;
}

void swap_heap(heap_type heap, int parrent_pos,int current_pos) {
	//printf("Swap ID %d, %d \n", heap->data[parrent_pos]->task_id, heap->data[current_pos]->task_id);
  task_type tmp = heap->data[parrent_pos];
	heap->data[parrent_pos] = heap->data[current_pos];
	heap->data[current_pos] = tmp;
}
 

void increase_priority(heap_type heap, int task_id, int priority) {
	int where=get_task_by_id(heap,task_id);
	if(where==-1 || where>=heap->size || heap->data[where]->priority >= priority)
		return ;
	int current_pos=where,parent_pos;
  heap->data[where]->priority=priority;
 // check_heap(heap,current_pos, parent_pos);
 hold_heap(heap);
}

void decrease_priority(heap_type heap, int task_id, int priority) {
	int where = get_task_by_id(heap, task_id); //position

	if(where == -1 || where>=heap->size  || heap->data[where]->priority <= priority)
		return;
  
	heap->data[where]->priority = priority;
  hold_heap(heap);
}

void hold_heap(heap_type heap) {
  int i,j;
  for(i=0; i < heap->size; i++) {
    for(j=0; j<heap->size; j++) {
      if(heap->data[i]->priority > heap->data[j]->priority) {
        swap_heap(heap, j, i);
      }
    }
  }
}

struct Task *delete_min(heap_type heap){
	if(is_Empty(heap))
		return NULL;
	struct Task *top=heap->data[0];
	swap_heap(heap,0,heap->size-1);
	heap->size-=1;
	hold_heap(heap);
	return top;
}

void destroy_heap(heap_type heap){
	free(heap->data);
	free(heap);
}

