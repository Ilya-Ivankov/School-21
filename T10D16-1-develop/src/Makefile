CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: rebuild

strlen_tests: s21_string_test.o s21_string.o 
	$(CC) $(CFLAGS) -DQuest_1 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_1

s21_string_test.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

strcmp_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_2 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_2

strcpy_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_3 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_3

strcat_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_4 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_4

strchr_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_5 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_5

strstr_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_6 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_6

strtok_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -DQuest_7 -c s21_string_test.c -o s21_string_test.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_7

text_processor.o: text_processor.c s21_string.h
	$(CC) $(CFLAGS) -c text_processor.c -o text_processor.o

text_processor: text_processor.o s21_string.o
	$(CC) $(CFLAGS) text_processor.o s21_string.o -o ../build/Quest_8

clean:
	rm -rf ../build/Quest_* *.o 

rebuild: 
	make clean
	make strlen_tests
	make strcmp_tests
	make strcpy_tests
	make strcat_tests
	make strchr_tests
	make strstr_tests
	make strtok_tests
	make text_processor
