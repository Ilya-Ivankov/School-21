CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -shared

all: rebuild

build: main_executable_module.o ../data_libs/data_io.o ../data_module/data_process.o ../data_libs/data_stat.o ../yet_another_decision_module/decision.o
	$(CC) $(CFLAGS) main_executable_module.o ../data_libs/data_io.o ../data_module/data_process.o ../data_libs/data_stat.o ../yet_another_decision_module/decision.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_libs/data_stat.h ../data_module/data_process.h ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) -c main_executable_module.c -o main_executable_module.o
	
../yet_another_decision_module/decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o ../yet_another_decision_module/decision.o

../data_libs/data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o ../data_libs/data_io.o

../data_module/data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) $(CFLAGS) -c ../data_module/data_process.c -o ../data_module/data_process.o

../data_libs/data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o

data_stat.a: ../data_libs/data_stat.o
	ar rcs data_stat.a ../data_libs/data_stat.o

build_with_static: main_executable_module.o ../data_libs/data_io.o ../data_module/data_process.o ../yet_another_decision_module/decision.o data_stat.a
	$(CC) $(CFLAGS) main_executable_module.o ../data_libs/data_io.o ../data_module/data_process.o ../yet_another_decision_module/decision.o data_stat.a -o ../../build/Quest_5

data_process.so: ../data_module/data_process.o ../data_libs/data_stat.o
	$(CC) $(CFLAGS) $(LDFLAGS) ../data_module/data_process.o ../data_libs/data_stat.o -o ../data_module/data_process.so

build_with_dynamic: main_executable_module.o ../data_module/data_process.so ../yet_another_decision_module/decision.o ../data_libs/data_io.o
	$(CC) $(CFLAGS) -L. main_executable_module.o ../data_module/data_process.so ../yet_another_decision_module/decision.o ../data_libs/data_io.o -o ../../build/Quest_6

clean:
	rm -rf ../data_module/*.o ../data_libs/*.o  ../yet_another_decision_module/*.o  ../../build/Quest_* *.o *.a

rebuild: 
	make clean
	make build
	make data_stat.a
	make build_with_static
	make data_process.so
	make build_with_dynamic
	make build_with_macro

../data_libs/data_io_macro.o: ../data_libs/data_io_macro.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io_macro.h -o ../data_libs/data_io_macro.o

build_with_macro: main_executable_module.o ../data_module/data_process.o ../yet_another_decision_module/decision.o ../data_module/data_process.so ../data_libs/data_io.o ../data_libs/data_stat.o
	$(CC) $(CFLAGS) -DUSE_MACRO_IO main_executable_module.o ../data_libs/data_io_macro.h ../data_module/data_process.o ../data_module/data_process.so ../yet_another_decision_module/decision.o ../data_libs/data_io.o ../data_libs/data_stat.o -o ../../build/Quest_4
