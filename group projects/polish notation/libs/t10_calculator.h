#ifndef T10_CALCULATOR_H
#define T10_CALCULATOR_H

#include <math.h>
#include <stdlib.h>

#include "t10_parser.h"
#include "t10_stack.h"
#define WIDTH 80

double *calculate(t10_stack *stack, int *flag);
double calculate_x_by_index(int index);

void processing_with_binary_func(t10_stack *stack, int index, int *flag,
                                 double (*func)(double d_1, double d_2));
double func_add(double d_1, double d_2);
double func_sub(double d_1, double d_2);
double func_mul(double d_1, double d_2);
double func_div(double d_1, double d_2);

void processing_with_unary_func(t10_stack *stack, int index, int *flag, double (*func)(double d));
double func_sin(double d);
double func_cos(double d);
double func_tan(double d);
double func_ctg(double d);
double func_sqrt(double d);
double func_ln(double d);

#endif  // T10_CALCULATOR_H