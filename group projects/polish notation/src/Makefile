
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXEC = ../build/graph
LIBS = ../libs/

all: graph

.PHONY: graph clean rebuild

graph: graph.c $(LIBS)*.c
	$(CC) $(CFLAGS) -c graph.c $(LIBS)*.c 
	$(CC) *.o -o $(EXEC)
	rm -rf *.o

format-check:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.c $(LIBS)*
	@rm .clang-format

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c $(LIBS)*
	@rm .clang-format

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h $(LIBS)*

clean:
	rm -rf *.o $(LIBS)*.o $(EXEC)

rebuild: clean all
