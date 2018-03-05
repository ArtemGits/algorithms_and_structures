#include <stdio.h>
#include "list.h"

void insert_element(List* head , int element) {
    List new = malloc(sizeof(struct List));
    if(!new) // if fail while memory allocation
        return;
   
    new->vertx = element;
    new->next = NULL;
    if(!*head) {
        *head = new;
        return;
    }
    
    List cur = *head;

    while(cur->next)
        cur = cur->next;
    
    cur->next = new;

}

void display_list(List list) {
    while(list) {
        printf("List element is: %d", list->vertx);
        list = list->next;
    }

    printf("\n");

}



