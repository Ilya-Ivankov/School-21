CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: rebuild

graph: graph.o
	$(CC) $(CFLAGS) graph.o -o ../build/graph

graph.o: graph.c
	$(CC) $(CFLAGS) -c graph.c -o graph.o

clean:
	rm -rf ../build/graph *.o

rebuild:
	make clean
	make graph
