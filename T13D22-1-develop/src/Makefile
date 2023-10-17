all: cipher 

FLAGS = -Wall -Wextra -Werror



cipher: cipher.c file_io.c encode.c logger.c
	gcc -c cipher.c file_io.c encode.c logger.c
	gcc cipher.o file_io.o encode.o logger.o -o ../build/cipher


clean:
	rm *.o
	rm ../build/*