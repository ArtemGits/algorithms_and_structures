#include <stdio.h>
#include "list.h"


void reverse_list_nonrecursive(llink* list) {
  llink cur = *list;
  llink next = NULL;
  llink prev = NULL;
  while(cur) {
    next = cur->next; // store next value of origin list
    cur->next = prev; //  1. cur->next = null 2. cur->next = 1 . 3 = 2
    prev = cur; // 1. prev = 1 2. prev = 2. 3.
    cur = next; // next
  }

  *list = prev;
}


llink reverse_list_recursive(llink* list, llink cur) {
  if(!cur)
	  	return NULL;
	  llink prev=reverse_list_recursive(list,cur->next);
	  cur->next=NULL;
	  if(!prev) {
      prev = cur;
		  *list=prev;
    }
      else {
      prev->next=cur;
		  
    }
  return cur;
}


int main() {
  int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(data)/sizeof(int);
	llink list = NULL;
	for(int i=0; i<size; i++) {
		insert_element(&list, data[i]);
	}
  display_list(list);
  //reverse_list_nonrecursive(&list);
  reverse_list_recursive(&list, list);
  display_list(list);
  return 0;
}
