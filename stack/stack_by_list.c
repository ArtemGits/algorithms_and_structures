#include <stdio.h>
#include <stdlib.h>
//return stack - не понятно что будет в условии в функции createstack
//1. Struct Stack and List
//2. create stack
//3. push
//4. pop
//5. empty

typedef struct {
  int item;
  struct List* next;
} *List;

typedef struct {
  int size;
  List* list;
} Stack;

void create_stack(Stack* stack) {
  stack = malloc(sizeof(Stack));
  stack->size = 0;
  stack->list = NULL;
}


int main() {
  Stack *stack;
  create_stack(stack);
  printf("%d", stack->size);
  return 0;
}


