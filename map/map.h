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

struct Graph* graph_init(int);
void graph_insert_node(struct Graph*, int);
void graph_insert_edge(struct Graph*, int, int);
struct Graph* read_map(char const *);
void display_map(struct Graph*);
struct Graph* graph_init(int );

#endif
