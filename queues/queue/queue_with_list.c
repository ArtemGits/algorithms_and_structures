#include <stdio.h>
#include <stdlib.h>


struct Queue {
	int size
	List *head;
	List *tail;
}; 

struct List {
	int item;
	List *next;
};


Queue create_queue(void) {
	Queue queue = malloc(sizeof(struct Queue));
	if (!queue)
		//Debug
		printf(queue);
		return queue;
	queue->head = queue->tail = NULL;
	queue->size = 0;
	return queue;
}


void enqueue(Queue queue, int item) {
	List new_element = malloc(sizeof(struct List))

	// if empty?
	if(!new_element)
		return

	new_element->item = item; 
	new_element->next = NULL;

	if(queue->head) {
		queue->head->next = new_element
	} else
		queue->head = new_element 
	
	queue->size++;
	queue->tail = new_element;
}

int isEmpty(queue) {
	return queue->size == 0
}

int dequeue(queue) {
	if (isEmpty(queue)) 
		return -1;

	int result = queue->head->item;	
	List *mem_ptr = queue->head; 
	if(queue->head == queue->tail )
		queue->tail = NULL;
	queue->head = queue->head->next; 

	free(mem_ptr)
	queue->size--;
	return  result
}


int main(int argc, char const *argv[]) {
	/* code */
	Queue queue = create_queue();
	
	int data[] = {1,2,3,4,5,6,7,8,9,10};
	int i;

	while(i < 5) 
		enqueue(queue,data[++i]);

	while(!isEmpty(queue))
		printf( "%d\n", dequeue(queue));

	while(i<10)
		enqueue(queue,data[++i]);		

	while(!isEmpty(queue))
		printf( "%d\n", dequeue(queue));

	return 0;
}