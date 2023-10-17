CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: rebild

door_struct: dmanager_module.o 
	$(CC) $(CFLAGS) -DQuest_1 -c dmanager_module.c -o dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o ../build/Quest_1

dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) -c dmanager_module.c -o dmanager_module.o

list_test: list_test.o list.o
	$(CC) $(CFLAGS) list_test.o list.o -o ../build/Quest_2

list_test.o: list_test.c list.h
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -o list.o

stack.o: stack.c  stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) -c stack_test.c -o stack_test.o

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) stack_test.o stack.o -o ../build/Quest_3

clean:
	rm -rf ../build/Quest_* *.o 

rebild:
		make clean
		make door_struct
		make list_test
		make stack_test