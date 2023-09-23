CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXECUTABLE = ../build/cipher

all: cipher

cipher: cipher.o
	$(CC) $(CFLAGS) cipher.o -o $(EXECUTABLE)

clean: 
	rm -rf *.o $(EXECUTABLE)

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c -Dcipher cipher.c -o cipher.o



