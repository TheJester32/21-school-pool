#ifndef S21_STRING_H
#define S21_STRING_H

unsigned int s21_strlen(const char *str);
unsigned int s21_strcmp(const char *str1, const char *str2);
void s21_strcpy(char *dest, const char *src);
void s21_strcat(char *dest, const char *app);
char *s21_strchr(char *str, char ch);
char *s21_strstr(const char *start, const char *needle);

#endif
