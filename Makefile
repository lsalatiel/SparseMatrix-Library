all:
	gcc -Wall -g -o main main.c src/Node.c src/SparseMatrix.c
clean:
	rm -rf main
