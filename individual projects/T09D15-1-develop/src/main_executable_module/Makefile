CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ../data_libs/*.c main_executable_module.c ../data_module/data_module_entry.c ../data_module/data_process.c
OBJECTS = main_executable_module.o data_module_entry.o data_io.o data_stat.o data_process.o
EXECUTABLE = ../../build/Quest_3
EXECUTABLE1 = ../../build/Quest_5
EXECUTABLE2 = ../../build/Quest_6

all: final

final: main_executable_module.o sort.o data_io.o data_stat.o decision.o  data_process.o
	$(CC) $(CFLAGS) main_executable_module.o sort.o data_io.o data_stat.o decision.o data_process.o -o $(EXECUTABLE)

clean: 
	rm -rf *.o *.a *.so final $(EXECUTABLE) $(EXECUTABLE1) $(EXECUTABLE2)

rebuild: clean all

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c

main_executable_module_dynamic.o: main_executable_module.c
	$(CC) $(CFLAGS) -c -Ddynamic main_executable_module.c -o main_executable_module_dynamic.o

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

data_stat.a: data_stat.o
	ar rcs data_stat.a data_stat.o

libdata_process.so: ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -fPIC -c ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -shared -o libdata_process.so data_process.o data_stat.o

build_with_static: main_executable_module.o sort.o data_io.o decision.o data_process.o data_stat.a
	$(CC) $(CFLAGS) main_executable_module.o sort.o data_io.o decision.o data_process.o data_stat.a -o $(EXECUTABLE1)

build_with_dynamic: main_executable_module_dynamic.o sort.o data_io.o decision.o libdata_process.so
	$(CC) $(CFLAGS) main_executable_module_dynamic.o sort.o data_io.o decision.o -L. -ldata_process -o $(EXECUTABLE2)
	install_name_tool -change libdata_process.so @executable_path/../src/main_executable_module/libdata_process.so ../../build/Quest_6


	