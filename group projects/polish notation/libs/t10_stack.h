#ifndef T10_STACK_H
#define T10_STACK_H

#include <stdlib.h>

typedef union value {
    int operator;  // цифровое значение(приоритет) считанного оператора
    char var;       // символьная переменная
    double number;  // вещественное число
} t10_value;

typedef struct data {
    int type;  // тип значения, хранящийся в юнионе t10_value
    t10_value value;
} t10_data;

typedef struct stack {
    t10_data *data;  // указатель на массив структур t10_data
    int top;         // иднекс верхнего элемента стэка
    int size;        // текущий размер стека
} t10_stack;

t10_stack *t10_stack_new(int initial_size);
void t10_stack_delete(t10_stack *stack);
void t10_stack_push(t10_stack *stack, t10_data data);
t10_data t10_stack_pop(t10_stack *stack, int *flag);
int t10_stack_is_empty(t10_stack *stack);

#endif  // T10_STACK_H
