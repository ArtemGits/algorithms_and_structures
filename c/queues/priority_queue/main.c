#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PriorityQueue.h"
#define HEAPSIZE 100

/* 
 * 1. Create heap.
 * 2. Create task.
 * 3. Insert heap.
 * 4. Increase priority.
 * 5. Delete task from heap.
 * 6. Decrease priority.
 * 7. Destroy heap.
 * */

int main(){
    struct Task *task;
    int priority; 
    srand(time(NULL));
    heap_type heap = create_heap(HEAPSIZE);
    for(int i=0; i<10; i++) {
	    priority = rand() % 100;
	    task = create_task(i,priority);
	    insert_in_heap(heap, task);
    }
    hold_heap(heap);
    //print_heap(heap);

    increase_priority(heap, 3, 1000);
 
    if( (task = delete_min(heap)) ) {
    	printf("Task ID = %d, task priority = %d\n", task->task_id, task->priority);
    	decrease_priority(heap,4,3); // 4 = task_id
    	increase_priority(heap,0,999); 
    }

    increase_priority(heap, 0, 999);
    while( (task=delete_min(heap) ))
    	printf("Task ID = %d, task priority = %d\n", task->task_id, task->priority);
    printf("-------\n");
    print_heap(heap);
    destroy_heap(heap);

}

