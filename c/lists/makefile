target=mergelist
$(target):mergelist.o list.o list.h
	gcc -o mergelist mergelist.o list.o
mergelist.o:mergelist.c list.h
	gcc -c mergelist.c
list.o:list.c list.h
	gcc -c list.c
.PHONY:clean run
clean:
	-rm mergelist.o list.o mergelist
run:
	./$(target)


