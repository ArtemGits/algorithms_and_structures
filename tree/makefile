target=btree
$(target):main.o reverseisotree.o binarytree.o binarytree.h reverseisotree.h
	gcc -o btree reverseisotree.o binarytree.o main.o
reverseisotree.o:reverseisotree.c reverseisotree.h
	gcc -c reverseisotree.c
main.o:main.c
	gcc -c main.c
binarytree.o:binarytree.c binarytree.h
	gcc -c binarytree.c
.PHONY:clean run
clean:
	-rm main.o binarytree.o reverseisotree.o btree
run:
	./$(target)

