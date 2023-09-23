#include "s21_string.h"

#include <stdio.h>
#ifdef strlen_tests

unsigned int s21_strlen_test(const char* str);

int main() {
    s21_strlen_test("Hello");
    s21_strlen_test("");
    s21_strlen_test("$$$!!!Hello World!!!$$$");

    return 0;
}

unsigned int s21_strlen_test(const char* str) {
    unsigned int expected_len = 0;
    const char* ptr = str;
    while (*ptr != '\0') {
        expected_len++;
        ptr++;
    }

    unsigned int result_len = s21_strlen(str);

    printf("Input: %s\n", str);
    printf("Output: %u\n", expected_len);
    if (expected_len == result_len) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return 0;
}

#endif

#ifdef strcmp_tests

unsigned int s21_strcmp_test(const char* str1, const char* str2);

int main() {
    s21_strcmp_test("String", "String");
    s21_strcmp_test(" ", "");
    s21_strcmp_test("Second Test String123##$$^^&&", "Second Test String123##$$^^&&");

    return 0;
}

unsigned int s21_strcmp_test(const char* str1, const char* str2) {
    unsigned int result_compare = s21_strcmp(str1, str2);

    printf("Input: %s %s\n", str1, str2);
    printf("Output: %u\n", result_compare);
    if (result_compare == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return 0;
}

#endif

#ifdef strcpy_tests

void s21_strcpy_test(const char* src);

int main() {
    s21_strcpy_test("String");
    s21_strcpy_test("");
    s21_strcpy_test("xdxd12312412r1 cqf1 2faf@!@!@!$$^^");
    s21_strcpy_test("I want to copy this string so much");

    return 0;
}

void s21_strcpy_test(const char* src) {
    char dest[10000];
    s21_strcpy(dest, src);

    printf("Input: %s\n", src);
    printf("Output: %s\n", dest);
    if ((s21_strlen(dest)) == (s21_strlen(src))) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

#endif

#ifdef strcat_tests

void s21_strcat_test(char* dest, const char* app);

int main() {
    s21_strcat_test("String", "String2");
    s21_strcat_test("", "123!@@#$@$");
    s21_strcat_test("sadsaddd", "happyhahppyhappy");
    s21_strcat_test("How is Verter doing?", "He is fine!");

    return 0;
}

void s21_strcat_test(char* dest, const char* app) {
    char res[10000];
    s21_strcat(res, app);
    s21_strcat(res, dest);

    printf("Input: %s %s\n", app, dest);
    printf("Output: %s\n", res);
    if ((s21_strlen(res)) - (s21_strlen(dest) + (s21_strlen(app))) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    for (int i = 0; i < 10000; i++) {
        res[i] = 0;
    }
}

#endif

#ifdef strchr_tests

char* s21_strchr_test(char* str, char ch);

int main() {
    s21_strchr_test("String", 'g');
    s21_strchr_test("a", 'b');
    s21_strchr_test("i am so tired", 'e');
    s21_strchr_test("12312ad", '2');

    return 0;
}

char* s21_strchr_test(char* str, char ch) {
    char* res = s21_strchr(str, ch);
    unsigned int dif = s21_strlen(str) - s21_strlen(res);

    printf("Input: %s %c\n", str, ch);
    printf("Output: %d\n", dif);
    if (s21_strlen(str) > dif) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return 0;
}

#endif

#ifdef strstr_tests

char* s21_strstr_test(const char* start, const char* needle);

int main() {
    s21_strstr_test("Check string", "string");
    s21_strstr_test("a", "");
    s21_strstr_test("relax, take it easy", "easy");
    s21_strstr_test("12312ad", "666");

    return 0;
}

char* s21_strstr_test(const char* start, const char* needle) {
    char* res = s21_strstr(start, needle);
    unsigned int dif = s21_strlen(start) - s21_strlen(res) + 1;

    printf("Input: %s %s\n", start, needle);
    printf("Output: %d\n", dif);
    if (s21_strlen(start) > dif) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return 0;
}

#endif