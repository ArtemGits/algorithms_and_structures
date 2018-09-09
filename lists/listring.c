#include <stdio.h>
#include "list.h"




llink find_item(llink list, int data) {
	while(list) {
		if(list->vertex == data) {
			return list;
		}
		list = list->next;
	}
	return NULL;
}


void make_ring(llink list, llink that) {
	// check without this move
	llink cur = list;
	if(!cur)
		return NULL;
	while(cur) {
		cur = list->next;
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
			break;
			retval = 1;
		}
			
	}
	return retval;

}


int main(int argc, char const *argv[]) {
	/* code */
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(data)/sizeof(int);
	llink* list = NULL;
	for(int i=0; i<size; i++) {
		insert_element(list, data[i]);
	}
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