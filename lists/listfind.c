#include <stdio.h>
#include "list.h"


llink find_middle_of_the_list(llink list) {
	llink list_one = list;
	llink list_two = list;

	while(list_one) {
			list_one = list_one->next;
		if(list_one)
			list_one = list_one->next;
		if(list_one)
			list_two = list_two->next;
	}
	return list_two;
}


llink get_klast_item(llink list, int k) {
	llink cur=list, curk=list;
	int i =0;
	while(i++<=k && cur)
		curk = curk->next;
	if(i>k && !curk)
		return cur;
	if(!curk)
		return NULL;
	while(curk) {
		cur = cur->next;
		curk = curk->next;
	}
	return cur;
}



int main(int argc, char const *argv[]) {
	/* code */
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(data)/sizeof(int);
	llink list = NULL;
	for(int i=0; i<size; i++) {
		insert_element(&list, data[i]);
	}
	llink mid = find_middle_of_the_list(list);
	printf("Middle element %d\n", mid->vertx );
	llink k = NULL;
	for(int i=0; i<size; i++) {
		k = get_klast_item(list, i);
		if(k)
			printf("%d last=%d\n", i, k->vertx);
	}
	return 0;
}
