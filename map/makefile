target=map
$(target):allpath.o map.o map.h
	gcc -o map allpath.o map.o
main.o:allpath.c map.h
	gcc -c allpath.c
PriorityQueue.o:PriorityQueue.c PriorityQueue.h
	gcc -c map.c
.PHONY:clean run
clean:
	-rm allpath.o map.o map
run:
	./$(target)
