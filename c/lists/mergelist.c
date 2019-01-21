#include <stdio.h>
#include "list.h"




llink merge_list_recursive(llink list1,llink list2){
	if(list1 && list2){
		if(list1->vertx < list2->vertx){
			list1->next=merge_list_recursive(list1->next,list2);
			return list1;	
		}else{
			list2->next=merge_list_recursive(list1,list2->next);
			return list2;
		}
	}
	else if(list1)
		return list1;
	else
		return list2;
}

llink merge_list_nonrecursive(llink list1, llink list2) {
  llink newlist = NULL, newlist_cur = NULL, selected;
  while(list1 && list2) {
    if(list1->vertx < list2->vertx) {
      selected = list1;
      list1 = list1->next;
    } else {
      selected = list2;
      list2 = list2->next;
    }
    if(!newlist) {
      newlist = selected;
      newlist_cur = newlist;
    } else {
      newlist_cur->next = selected;
      newlist_cur = newlist_cur->next;
    }
  }
  if(list1) {
    if(!newlist_cur) {
      newlist = list1;
    } else {
      printf("list1 \n");
      newlist_cur->next = list1;
    }
  }
  if(list2) {
    if(list2) {
      if(!newlist) {
        newlist = list2; 
      } else {
        printf("list2 \n");
        //newlist = list1; empty
        newlist_cur->next = list2;
      }
    }
  }
  return newlist;
}

int main() {
  int data1[]={2,8,4};
	int size1=sizeof(data1)/sizeof(int);
	int data2[]={5,9,3};
	int size2=sizeof(data2)/sizeof(int);

	llink list1=NULL,list2=NULL;
	int i;
	for(i=0;i<size1;i++)
		insert_element(&list1,data1[i]);
	display_list(list1);
	for(i=0;i<size2;i++)
		insert_element(&list2,data2[i]);
	display_list(list2);
//	llink list3 = merge_list_recursive(list1,list2);
  llink list3 = merge_list_nonrecursive(list1, list2);
  display_list(list3);
  return 0;
}
