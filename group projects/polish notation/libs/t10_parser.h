#ifndef T10_PARSER_H
#define T10_PARSER_H

#include <stdlib.h>
#include <string.h>

#include "t10_stack.h"

#define DEFAULT_X 'x'
#define OPERATOR 0
#define VAR 1
#define NUMBER 2

#define VAL 0  // в стек занесено новое значение

#define ADD 1  // сложение
#define SUB 2  // вычитание

#define MUL 3  // умножение
#define DIV 4  // деление

#define COS 5    // косинус
#define SIN 6    // синус
#define TAN 7    // тангенс
#define CTG 8    // котангенс
#define LN 9     // натуральный логарифм
#define SQRT 10  // взятие квадратного корня

#define BRAC_O 11  // открывающая скобка

#define SOF -1  // переполнение стека
#define SUF -2  // в стеке недостаточно операндов
#define UNK -3  // неопознанное значение

int check_parenthesis(char *input_string);
int is_digit(char ch);
t10_stack *parser(char *infix_string, int *flag);
int check_is_operator_or_start_func(char ch);
int check_is_sin_func(const char *str, int start_substr, int len);
int check_is_cos_func(const char *str, int start_substr, int len);
int check_is_tan_func(const char *str, int start_substr, int len);
int check_is_ctg_func(const char *str, int start_substr, int len);
int check_is_sqrt_func(const char *str, int start_substr, int len);
int check_is_ln_func(const char *str, int start_substr, int len);
int convert_simple_operator_from_ch_to_int(char op);
int check_operator_is_higher(int op_1, int op_2);

#endif  // T10_PARSER_H