/*
 * =====================================================================================
 *
 *       Filename:  queue_with_two_stack_by_array.c
 *
 *    Description:  Queue with two stack by array
 *
 *        Version:  1.0
 *        Created:  05.08.2018 17:25:10
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
//push_
//pop_
//empty_
//full_;
//enqueu
//deque
//empty queue
//full queue
#define STACK_SIZE 100
int stack_one[STACK_SIZE];
int sp_one = -1;

void push_one(int item) {
  stack_one[++sp_one] = item;
}

int pop_one() {
  int retval = stack_one[sp_one];
  stack_one[sp_one] = -1;
  sp_one--;
  return retval;
}

int is_empty_one() {
  return sp_one == -1; 
}

int is_full_one() {
  return sp_one == STACK_SIZE -1;
}

int stack_two[STACK_SIZE];
int sp_two = -1;

void push_two(int item) {
  stack_two[++sp_two] = item;
}

int pop_two() {
  int retval = stack_two[sp_two];
  stack_two[sp_two] = -1;
  sp_two--;
  return retval;
}

int is_empty_two() {
  return sp_two == -1; 
}

int is_full_two() {
  return sp_two  == STACK_SIZE -1;
}

void enqueue_queue(int item) {
  if(!is_full_one()) {
    push_one(item);
  } else {
      while(!is_full_two() && !is_empty_one()) {
        push_two(pop_one());
      }
    push_one(item);  
  }
  
}

int dequeue_queue() {
  int retval;
  if(is_empty_two()) {
    while(!is_empty_one()) {
      retval = pop_one();
      push_two(retval);
    }
  } 
 //TODO rework this section
 if(is_empty_two()) {
   printf("Queue is empty.\n");
   return -1;
 } else {
   retval = pop_two();
 }
 return retval;
}

int empty_queue() {
  return is_empty_one() && is_empty_two();
}

int full_queue() {
  return is_full_one() && is_full_two();
}



int main() {
  int data[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(data)/sizeof(int);
  int i = 0;
  while(i<5)
    enqueue_queue(data[i++]);
  while(!empty_queue()) {
   printf("%d\n", dequeue_queue());
  }
  while(i<size)
		enqueue_queue(data[i++]);
	while(!empty_queue())
    printf("%d\n",dequeue_queue());
  return 0;
}

