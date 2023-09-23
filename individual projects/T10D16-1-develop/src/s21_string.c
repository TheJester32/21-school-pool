#include "s21_string.h"

#include <stdio.h>

unsigned int s21_strlen(const char* str) {
    unsigned int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

unsigned int s21_strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (unsigned int)(*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (unsigned int)(*str1 - *str2);
}

void s21_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void s21_strcat(char* dest, const char* app) {
    char* temp = dest;
    while (*temp) {
        temp++;
    }
    while (*app) {
        *temp = *app;
        temp++;
        app++;
    }
    *temp = '\0';
}

char* s21_strchr(char* str, char ch) {
    while (*str != '\0') {
        if (*str == ch) {
            return str;
        }
        str++;
    }

    if (ch == '\0') {
        return str;
    }
    return (char*)str;
}

char* s21_strstr(const char* start, const char* needle) {
    if (*needle == '\0') {
        return (char*)start;
    }
    while (*start != '\0') {
        int i = 0;
        while (*(start + i) == *(needle + i)) {
            i++;
            if (*(needle + i) == '\0') {
                return (char*)start;
            }
        }
        start++;
    }

    return (char*)start;
}
