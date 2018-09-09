#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void insert_element(llink* head , int element) {
    llink new = malloc(sizeof(struct List));
    if(!new) // if fail while memory allocation
        return;
   
    new->vertx = element;
    new->next = NULL;
    if(!*head) {
        *head = new;
        return;
    }
    
    llink cur = *head;

    while(cur->next)
        cur = cur->next;
    
    cur->next = new;
}

void display_list(llink list) {
  if(!list) {
    printf("List is empty\n");
    return;
  } else {
      while(list) {
        printf("List element is: %d \n", list->vertx);
        list = list->next;
    }
    printf("\n");

  }
}

int list_lenght(llink head) {
    int count = 0;
    while(head->next) {
        count++;
        head = head->next;
    }
    return count;
}

llink insert_element_recursive(llink link, int element) {
    
    if(!link) {
        llink new = malloc(sizeof(struct List));
        if(!new) // if fail while memory allocation
            return new;
       
        new->vertx = element;
        new->next = NULL; 
        return new;   
    } else {
        link->next = insert_element_recursive(link->next, element);
        return link;
    }
    
}

llink list_search(llink head, int element) {
    while(head->next) {
        if(head->vertx == element)
            return head;
    head = head->next;
    }
}





