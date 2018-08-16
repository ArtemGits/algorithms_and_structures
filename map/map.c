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

void read_map(const char* filename) {
    FILE *map_file=fopen(filename,"r");
  	int directed,nodesize;
  	fscanf(map_file,"%d %d\n",&directed,&nodesize);
  	//struct Graph *map=graph_init(nodesize);
  	char buff[1024];
  	char *node_line=fgets(buff,sizeof(buff),map_file);
  	char *node=strtok(node_line," \n");
    //printf("%s\n", node_line);
    //printf("%s\n", node);
  	while(node){
  		//graph_insertnode(map,atoi(node));
      printf("%s\n", node);
  		node=strtok(NULL," \n");
      printf("after: %s\n", node);

  }
}
