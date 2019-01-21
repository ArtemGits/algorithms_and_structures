#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


void display_map(struct Graph* map) {
  int i;
  struct Node* cur;
  for(i=0; i<map->size; i++) {
    cur = map->nodes[i];
    printf(" %d:", cur->vertex);
    cur = cur->next;

    while(cur) {
      printf(" %d", cur->vertex);
      cur = cur->next;
    }
    printf("\n");
  }
}

struct Graph* graph_init(int nodesize) {
  struct Graph* map = malloc(sizeof(struct Graph));
  if(!map) {
    printf("Something goes wrong!\n");
    return map;
  }
  map->sp = 0;
  map->size = nodesize;
  map->nodes = malloc(sizeof(struct Node*) * nodesize);
  return map;
}

void graph_insert_node(struct Graph* map, int nodename) {
  struct Node* newnode = malloc(sizeof(struct Node));
  newnode->next = NULL;
  newnode->vertex = nodename;
  map->nodes[map->sp++] = newnode;
}

void graph_insert_edge(struct Graph* map, int nodename1, int nodename2) {
  struct Node* node = map->nodes[nodename1];
  struct Node* new = malloc(sizeof(struct Node));
  new->vertex = nodename2;
  new->next = node->next;
  node->next = new;
}

struct Graph* read_map(const char* filename) {
    FILE *map_file=fopen(filename,"r");
  	int directed,nodesize;
  	fscanf(map_file,"%d %d\n",&directed,&nodesize);
  	struct Graph *map=graph_init(nodesize);
  	char buff[1024];
  	char *node_line=fgets(buff,sizeof(buff),map_file);
  	char *node=strtok(node_line," \n");
    //printf("%s\n", node_line);
    //printf("%s\n", node);
    //insert nodes
  	while(node){
  		graph_insert_node(map,atoi(node));
      // printf("%s\n", node);
  		node=strtok(NULL," \n");
      // printf("after: %s\n", node);
  }
  //insert edges
  char* edge_line;
  int node1, node2;
  while( edge_line = fgets(buff, sizeof(buff), map_file)) {
    node = strtok(edge_line, "\t\n");
    node1 = atoi(node);
    node = strtok(NULL, "\t\n");
    node2 = atoi(node);
    graph_insert_edge(map, node1, node2);
    if(!directed) {
      graph_insert_edge(map, node2, node1);
    }
  }

  fflush(map_file);
  fclose(map_file);
  return map;


}
