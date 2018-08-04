#include <stdio.h>
#include <stdlib.h>
//return stack - не понятно что будет в условии в функции createstack
//5. empty

typedef struct List {
  int item;
  struct List* next;
} List;

typedef struct Stack {
  int size;
  List* list;
} Stack;

Stack* create_stack() {
  Stack* stack = malloc(sizeof(Stack));
  //TODO add checker
  stack->size = 0;
  stack->list = NULL;
  return stack;
}

void push_back(Stack* stack, int item) {
  List* new = malloc(sizeof(List));
  //TODO add checker
  new->item = item;
  new->next = stack->list;
  stack->list = new;
  stack->size++;
}

int pop_back(Stack* stack) {
  List* ptr = stack->list; //head
  int retval  = stack->list->item;
  stack->list = ptr->next; //next to head
  ptr->next = NULL;
  free(ptr);
  stack->size--;
  return retval;
}

int is_empty(Stack* stack) {
  return stack->size == 0;
}

void print_stack(Stack* stack) {
  while(stack->list->next != NULL) {
    printf("%d, ",stack->list->item);
    stack->list = stack->list->next;
  }
  printf("\n");
}

int main() {
  Stack *stack = create_stack();
  int i = 0;
  while(i<2) {
    push_back(stack, i++);
  }
  while(is_empty(stack) != 1) {
    pop_back(stack);
  }
  while(i<10) {
    push_back(stack, i++);
  }
  print_stack(stack);
  printf("%d \nn",stack->list->item);
  return 0;
}


