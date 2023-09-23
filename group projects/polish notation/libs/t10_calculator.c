#include "t10_calculator.h"

double *calculate(t10_stack *stack, int *flag) {
    double *result = (double *)malloc(WIDTH * sizeof(double));
    t10_stack *temp_stack = t10_stack_new(stack->size);

    for (int j = 0; j < WIDTH; j++) {
        for (int i = 0; i < stack->top; i++) {
            if (stack->data[i].type == OPERATOR) {
                switch (stack->data[i].value.operator) {
                    case ADD: {
                        processing_with_binary_func(temp_stack, j, flag, func_add);
                    }; break;
                    case SUB: {
                        processing_with_binary_func(temp_stack, j, flag, func_sub);
                    }; break;
                    case MUL: {
                        processing_with_binary_func(temp_stack, j, flag, func_mul);
                    }; break;
                    case DIV: {
                        processing_with_binary_func(temp_stack, j, flag, func_div);
                    }; break;
                    case SIN: {
                        processing_with_unary_func(temp_stack, j, flag, func_sin);
                    }; break;
                    case COS: {
                        processing_with_unary_func(temp_stack, j, flag, func_cos);
                    }; break;
                    case TAN: {
                        processing_with_unary_func(temp_stack, j, flag, func_tan);
                    }; break;
                    case CTG: {
                        processing_with_unary_func(temp_stack, j, flag, func_ctg);
                    }; break;
                    case SQRT: {
                        processing_with_unary_func(temp_stack, j, flag, func_sqrt);
                    }; break;
                    case LN: {
                        processing_with_unary_func(temp_stack, j, flag, func_ln);
                    }; break;
                    default:
                        break;
                }
            } else {
                t10_stack_push(temp_stack, stack->data[i]);
            }
            result[j] = t10_stack_pop(temp_stack, flag).value.number;
        }
    }

    t10_stack_delete(temp_stack);
    return result;
}

double calculate_x_by_index(int index) { return (M_PI * 4 + 1) / 79 * index; }

double func_add(double d_1, double d_2) { return d_1 + d_2; }
double func_sub(double d_1, double d_2) { return d_1 - d_2; }
double func_mul(double d_1, double d_2) { return d_1 * d_2; }
double func_div(double d_1, double d_2) { return d_1 / d_2; }
double func_sin(double d) { return sin(d); }
double func_cos(double d) { return cos(d); }
double func_tan(double d) { return tan(d); }
double func_ctg(double d) { return 1 / tan(d); }
double func_sqrt(double d) { return sqrt(d); }
double func_ln(double d) { return log(d); }

void processing_with_binary_func(t10_stack *stack, int index, int *flag,
                                 double (*func)(double d_1, double d_2)) {
    double d_1, d_2;
    t10_value value;
    t10_data data = t10_stack_pop(stack, flag);
    if (data.type == NUMBER) {
        d_1 = data.value.number;
    } else {
        d_1 = calculate_x_by_index(index);
    }

    data = t10_stack_pop(stack, flag);
    if (data.type == NUMBER) {
        d_2 = data.value.number;
    } else {
        d_2 = calculate_x_by_index(index);
    }

    value.number = func(d_1, d_2);
    t10_data push_data = {NUMBER, value};
    t10_stack_push(stack, push_data);
}

void processing_with_unary_func(t10_stack *stack, int index, int *flag, double (*func)(double d)) {
    double d;
    t10_value value;
    t10_data data = t10_stack_pop(stack, flag);
    if (data.type == NUMBER) {
        d = data.value.number;
    } else {
        d = calculate_x_by_index(index);
    }

    value.number = func(d);
    t10_data push_data = {NUMBER, value};
    t10_stack_push(stack, push_data);
}