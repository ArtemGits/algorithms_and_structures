#ifndef MAP_H
#define MAP_H

struct Node {
  int vertex;
  struct Node* next;
};

struct Graph {
  int size;
  int sp;
  struct Node** nodes;
};

void read_map(char const *);
void display_map(struct Graph*);

#endif
