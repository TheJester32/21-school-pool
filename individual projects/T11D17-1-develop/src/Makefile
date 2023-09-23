CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXECUTABLE = ../build/Quest_1


door_struct: dmanager_module.o door_struct.o
	$(CC) $(CFLAGS) dmanager_module.o door_struct.o -o $(EXECUTABLE)

clean: 
	rm -rf *.o final $(EXECUTABLE)

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c -Ddoor_struct dmanager_module.c -o dmanager_module.o

door_struct.o: door_struct.c
	$(CC) $(CFLAGS) -c -Ddoor_struct door_struct.c -o door_struct.o
