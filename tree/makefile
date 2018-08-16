target=btree
$(target):main.o binarytree.o binarytree.h
	gcc -o btree main.o binarytree.o
listring.o:main.c binarytree.h
	gcc -c main.c
list.o:binarytree.c binarytree.h
	gcc -c binarytree.c
.PHONY:clean run
clean:
	-rm main.o binarytree.o btree
run:
	./$(target)

