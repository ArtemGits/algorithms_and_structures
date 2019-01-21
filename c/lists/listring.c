#include <stdio.h>
#include <stdlib.h>
#include "list.h"




llink find_item(llink list, int data) {
	llink cur = list;
  //printf("%d \n", cur->vertx);
  while(cur) {
		if(cur->vertx == data) {
     // printf("Return from find_item\n");
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void make_ring(llink list, llink that) {
	// check without this move
	llink cur = list;
  printf("Make ring: %d \n", that->vertx);
	if(!cur)
		return;
	while(cur->next) {
		cur = cur->next;
	}
	cur->next = that;
}

int is_ring_list(llink list) {
	llink turtle = list, rabit=list;
	int retval = 0;
	while(rabit) {
		turtle=turtle->next;
		rabit=rabit->next;
		if(rabit)
			rabit=rabit->next;
		if(rabit==turtle) {
			retval = 1;
      break;
		}
	}
	return retval;
}

llink create_list() {
  llink list = malloc(sizeof(struct List));
  //TODO add checker
  list->vertx = 0;
  list->next = NULL;
  return list;
}

int main(int argc, char const *argv[]) {
	/* code */
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(data)/sizeof(int);
	llink list = NULL;
	for(int i=0; i<size; i++) {
		insert_element(&list, data[i]);
	}

  display_list(list);
   
	if(is_ring_list(list))
		printf("Has ring list.\n");
	else
		printf("No ring.\n");

	make_ring(list, find_item(list, data[0]));
	if(is_ring_list(list))
		printf("Has ring list.\n");
	else
		printf("No ring.\n");
	
	return 0;
  
}
