/*
 * =====================================================================================
 *
 *       Filename:  queue_with_array.c
 *
 *    Description: Queue with array
 *
 *        Version:  1.0
 *        Created:  05.08.2018 15:16:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Artem Salagaev, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
//Queue struct
//create queue
//full
//empty
//enqueue
//dequeue

typedef struct Queue {
  int* data;
  int capacity;
  int head;
  int rear;
}* Queue;

Queue create_queue(int capacity) {
  Queue queue = malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->data = malloc(sizeof(int) * queue->capacity);
  queue->head = queue->rear = 0;
}

void enque(Queue queue, int item) {
  queue->data[queue->rear] = item;
 // printf("%d ", queue->data[queue->rear]);
  queue->rear = (queue->rear + 1) % queue->capacity;
}

int deque(Queue queue) {
  int retval = queue->head;
  queue->head = (queue->head + 1) % queue->capacity;
}

void print_queue(Queue queue) {
  while(queue->rear != queue->head)
    printf("%d ", queue->data[--queue->rear]);
  printf("\n");
}

int is_empty(Queue queue) {
  return queue->rear == queue->head;
}

int is_full(Queue queue) {
  return queue->head == (queue->rear + 1) % queue->capacity;
}

int main() {
  Queue queue = create_queue(10);
  int i = 0;
  while(i<5) {
    enque(queue, i++);
  }
  print_queue(queue);
  while(!is_empty(queue))
    deque(queue);
  print_queue(queue);
  while(!is_full(queue))
    enque(queue, i++);
  print_queue(queue);
  return 0;
}
