#include "t10_stack.h"

#define DEFAULT_STACK_SIZE 50

t10_stack *t10_stack_new(int initial_size) {
    t10_stack *stack = (t10_stack *)malloc(sizeof(t10_stack));
    stack->size = initial_size;
    if (stack->size <= 0) {
        stack->size = DEFAULT_STACK_SIZE;
    }
    stack->top = 0;
    stack->data = (t10_data *)malloc(sizeof(t10_data) * stack->size);
    return stack;
}

void t10_stack_delete(t10_stack *stack) {
    free(stack->data);
    free(stack);
}

void t10_stack_push(t10_stack *stack, t10_data data) {
    if (stack->top == stack->size) {
        stack->size = (stack->size * 3 + 1) / 2;  // увеличение стека на 50%
        stack->data = (t10_data *)realloc(stack->data, stack->size * sizeof(t10_data));
    }
    stack->data[stack->top++] = data;
}

t10_data t10_stack_pop(t10_stack *stack, int *flag) {
    t10_data data;
    if (stack->top > 0) {
        data = stack->data[--stack->top];
        *flag = 1;
    } else {
        t10_value value;
        value.number = 0.0;
        data.value = value;
        *flag = 0;
    }
    return data;
}

int t10_stack_is_empty(t10_stack *stack) {
    int flag = 0;
    if (stack == NULL || stack->top == 0) {
        flag = 1;
    }
    return flag;
}