#ifndef LIST_H

#define LIST_H

struct List {
    int vertx;
    struct List *next;
};

typedef struct List *llink;

void display_list(llink );
void insert_element(llink* , int);
llink insert_element_recursive(llink, int); 
llink list_search(llink, int);
int list_length(llink);

#endif
