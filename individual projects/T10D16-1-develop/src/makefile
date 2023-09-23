CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXECUTABLE = ../build/Quest_1
EXECUTABLE1 = ../build/Quest_2
EXECUTABLE2 = ../build/Quest_3
EXECUTABLE3 = ../build/Quest_4
EXECUTABLE4 = ../build/Quest_5
EXECUTABLE5 = ../build/Quest_6
EXECUTABLE6 = ../build/Quest_7

strlen_tests: string_strlen_tests.o string_test_strlen_tests.o
	$(CC) $(CFLAGS) string_strlen_tests.o string_test_strlen_tests.o -o $(EXECUTABLE)

strcmp_tests: string_strcmp_tests.o string_test_strcmp_tests.o
	$(CC) $(CFLAGS) string_test_strcmp_tests.o string_strcmp_tests.o -o $(EXECUTABLE1)

strcpy_tests: string_strcpy_tests.o string_test_strcpy_tests.o
	$(CC) $(CFLAGS) string_test_strcpy_tests.o string_strcpy_tests.o -o $(EXECUTABLE2)

strcat_tests: string_strcat_tests.o string_test_strcat_tests.o
	$(CC) $(CFLAGS) string_test_strcat_tests.o string_strcat_tests.o -o $(EXECUTABLE3)

strchr_tests: string_strchr_tests.o string_test_strchr_tests.o
	$(CC) $(CFLAGS) string_test_strchr_tests.o string_strchr_tests.o -o $(EXECUTABLE4)

strstr_tests: string_strstr_tests.o string_test_strstr_tests.o
	$(CC) $(CFLAGS) string_test_strstr_tests.o string_strstr_tests.o -o $(EXECUTABLE5)

clean: 
	rm -rf *.o final $(EXECUTABLE) $(EXECUTABLE1) $(EXECUTABLE2) $(EXECUTABLE3) $(EXECUTABLE4) $(EXECUTABLE5)

string_test_strlen_tests.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -Dstrlen_tests s21_string_test.c -o string_test_strlen_tests.o

string_test_strcmp_tests.o: s21_string_test.c
	$(CC) $(CFLAGS) -c -Dstrcmp_tests s21_string_test.c -o string_test_strcmp_tests.o

string_strlen_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strlen_tests.o

string_strcmp_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strcmp_tests.o

string_test_strcpy_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c -Dstrcpy_tests s21_string_test.c -o string_test_strcpy_tests.o

string_strcpy_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strcpy_tests.o

string_test_strcat_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c -Dstrcat_tests s21_string_test.c -o string_test_strcat_tests.o

string_strcat_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strcat_tests.o

string_test_strchr_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c -Dstrchr_tests s21_string_test.c -o string_test_strchr_tests.o

string_strchr_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strchr_tests.o

string_test_strstr_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c -Dstrstr_tests s21_string_test.c -o string_test_strstr_tests.o

string_strstr_tests.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -o string_strstr_tests.o




	
