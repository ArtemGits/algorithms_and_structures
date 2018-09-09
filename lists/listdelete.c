#include <stdio.h>
#include <stdlib.h>
#include "list.h"


llink find_item(llink list, int data) {
	while(list) {
		if(list->vertx == data) {
			return list;
		}
		list = list->next;
	}
	return NULL;
}

void delete_item_advanced(llink node) {
	llink next = node->next;
	if(next) {
		node->next = next->next;
		node->vertx = next->vertx;
		free(next);
	} else
		printf("Can't delete item %d for its the last item\n", node->vertx);
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
	int del_data[] = {4,5,6,7,9,10};
	llink node ;
	for(int i = 0; i<6; i++) {
		node = find_item(list, del_data[i]);
		delete_item_advanced(node);
	}
  if(list)
    display_list(list);			
	return 0;
}
