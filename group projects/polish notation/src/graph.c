#include <stdio.h>

#include "../libs/t10_calculator.h"
#include "../libs/t10_io.h"
#include "../libs/t10_parser.h"
#include "../libs/t10_stack.h"

int main() {
    int flag = 1;
    char *input_string = NULL;
    t10_stack *stack = NULL;
    double *result_array = NULL;

    print_welcome_message();
    input_string = read_string(&flag);
    if (flag) {
        flag = check_parenthesis(input_string);
    }

    if (flag) {
        stack = parser(input_string, &flag);
    }

    if (flag) {
        result_array = calculate(stack, &flag);
        output_graph(result_array);
    }

    free(result_array);
    free(input_string);
    t10_stack_delete(stack);

    return 0;
}