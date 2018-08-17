#include <stdio.h>
#include "map.h"



 int main(int argc, char const *argv[]) {

   if(argc == 1) {
     printf("argv NULL \n");
     return (1);
   }

   struct Graph* map = read_map(argv[1]);
   display_map(map);

  return 0;
}
