/*
 * =====================================================================================
 *
 *       Filename:  stack_by_array.c
 *
 *    Description:  Stack by using array
 *
 *        Version:  1.0
 *        Created:  05.08.2018 09:20:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Artem Salagaev, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int* data;
  int sp;
  int capacity;
} *Stack;

Stack create_stack(int capacity) {
  Stack stack = malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->data = malloc(sizeof(int)*capacity);
  stack->sp = -1;
}

void push_back(Stack stack, int item) {
  stack->data[++stack->sp] = item;
  //printf("Pointer: %d ", stack->sp);
}

int pop_back(Stack stack) {
  int retval = stack->data[stack->sp];
  stack->data[stack->sp] = -1;
  stack->sp--;
  return retval;
}

int is_empty(Stack stack) {
  return stack->sp == -1;
}

int is_full(Stack stack) {
  return stack->sp == stack->capacity - 1; //sp start from -1
}

void print_stack(Stack head, int position) {
  int iterator = position;
  while(iterator != head->capacity) {
    printf("%d ", head->data[iterator++]);
  }
  printf("\n");
}

int main() {
  Stack stack = create_stack(10);
  int i = 0;
  while(i<5)
    push_back(stack, i++);
 // printf("%d\n", stack->data[0]);
 // printf("%d\n", stack->data[1]);
 // printf("%d\n", stack->data[2]);
 // printf("%d\n", stack->data[3]);
  while(!is_empty(stack))
    pop_back(stack);
  print_stack(stack, 0);
  while(!is_full(stack))
    push_back(stack,i++);
  print_stack(stack, 0);
  return 0;
}

