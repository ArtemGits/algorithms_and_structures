#include <stdio.h>
#include <stdlib.h>
//return stack - не понятно что будет в условии в функции createstack


//WRONG BEHAVIOR
//typedef struct List {
//  int item;
//  struct List* next;
//} List;

//typedef struct Stack {
//  int size;
//  List* list;
//} Stack;

typedef struct Stack{
	int size;
	struct List{
		int item;
		struct List *next;
	} *head;
} Stack;



Stack* create_stack() {
  Stack* stack = malloc(sizeof(Stack));
  //TODO add checker
  stack->size = 0;
  stack->head = NULL;
  return stack;
}

void push_back(Stack* stack, int item) {
  struct List* new = malloc(sizeof(struct List));
  //TODO add checker
  new->item = item;
  new->next = stack->head;
  stack->head = new;
  stack->size++;
}

int pop_back(Stack* stack) {
  struct List* ptr = stack->head; //head
  int retval  = stack->head->item;
  stack->head = ptr->next; //next to head
  ptr->next = NULL;
  free(ptr);
  stack->size--;
  return retval;
}

int is_empty(Stack* stack) {
  return stack->size == 0;
}

void print_stack(Stack* stack) {
  struct List* iterator = stack->head;
  while(iterator != NULL) {
    printf("%d, ",iterator->item);
    iterator = iterator->next;
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
  while(is_empty(stack) != 1) {
    pop_back(stack);
  }
  print_stack(stack);
  push_back(stack, i++);
  printf("%d\n", stack->head->item);
  return 0;
}


