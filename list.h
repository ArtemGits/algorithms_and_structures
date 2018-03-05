#ifndef LIST_H

#define LIST_H

struct List {
    int vertx;
    struct List *next;
}

typedef List *list;

void display_list(List *);
void insert_element(list *, int);

#endif
