#include "t10_parser.h"

#include <stdio.h>

int check_parenthesis(char *input_string) {
    int flag = 1;
    int balance = 0;
    while (*input_string != '\0') {
        if (*input_string == '(') {
            balance++;
        }
        if (*input_string == ')') {
            balance--;
        }
        if (balance < 0) {
            flag = 0;
            break;
        }
        input_string++;
    }
    if (balance != 0) {
        flag = 0;
    }

    return flag;
}

int is_digit(char ch) {
    int flag = 0;
    if (ch >= '0' && ch <= '9') {
        flag = 1;
    }
    return flag;
}

int get_operator_priority(int operator) {
    int priority = 0;
    switch (operator) {
        case ADD:
        case SUB:
            priority = 1;
            break;
        case MUL:
        case DIV:
            priority = 2;
            break;
        case COS:
        case SIN:
        case TAN:
        case CTG:
        case LN:
        case SQRT:
            priority = 3;
            break;
        default:
            priority = 0;
    }
    return priority;
}

t10_stack *parser(char *infix_string, int *flag) {
    int len = strlen(infix_string);
    t10_stack *temp_stack = t10_stack_new(len);
    t10_stack *output_stack = t10_stack_new(len);

    int last_token_type = -1;

    for (int i = 0; i < len; i++) {
        if (is_digit(infix_string[i]) ||
            (infix_string[i] == '-' &&
             (last_token_type == -1 || last_token_type == OPERATOR || last_token_type == BRAC_O))) {
            double d = strtod(&infix_string[i], NULL);
            t10_value value;
            value.number = d;
            t10_data data = {NUMBER, value};
            t10_stack_push(output_stack, data);

            while (i < len && (is_digit(infix_string[i]) || infix_string[i] == '.')) {
                i++;
            }
            i--;
            last_token_type = NUMBER;
        } else if (infix_string[i] == DEFAULT_X) {
            t10_value value;
            value.var = DEFAULT_X;
            t10_data data = {VAR, value};
            t10_stack_push(output_stack, data);
            last_token_type = VAR;
        } else if (infix_string[i] == '(') {
            t10_value value;
            value.operator= BRAC_O;
            t10_data data = {OPERATOR, value};
            t10_stack_push(temp_stack, data);
            last_token_type = OPERATOR;
        } else if (infix_string[i] == ')') {
            while (!t10_stack_is_empty(temp_stack) &&
                   temp_stack->data[temp_stack->top - 1].value.operator!= BRAC_O) {
                t10_data oper_data = t10_stack_pop(temp_stack, flag);
                t10_stack_push(output_stack, oper_data);
            }
            if (!t10_stack_is_empty(temp_stack) &&
                temp_stack->data[temp_stack->top - 1].value.operator== BRAC_O) {
                t10_stack_pop(temp_stack, flag);
            }
            last_token_type = OPERATOR;

        } else if (check_is_operator_or_start_func(infix_string[i])) {
            t10_value value;
            if (check_is_sin_func(infix_string, i, len)) {
                value.operator= SIN;
                i += 3;
            } else if (check_is_cos_func(infix_string, i, len)) {
                value.operator= COS;
                i += 3;
            } else if (check_is_tan_func(infix_string, i, len)) {
                value.operator= TAN;
                i += 3;
            } else if (check_is_ctg_func(infix_string, i, len)) {
                value.operator= CTG;
                i += 3;
            } else if (check_is_sqrt_func(infix_string, i, len)) {
                value.operator= SQRT;
                i += 4;
            } else if (check_is_ln_func(infix_string, i, len)) {
                value.operator= LN;
                i += 2;
            } else {
                value.operator= convert_simple_operator_from_ch_to_int(infix_string[i]);
            }
            t10_data data = {OPERATOR, value};
            while (!t10_stack_is_empty(temp_stack) &&
                   check_operator_is_higher(temp_stack->data[temp_stack->top - 1].value.operator,
                                            value.operator)) {
                t10_data oper_data = t10_stack_pop(temp_stack, flag);
                t10_stack_push(output_stack, oper_data);
            }
            t10_stack_push(temp_stack, data);
            last_token_type = OPERATOR;
        }
    }

    while (!t10_stack_is_empty(temp_stack)) {
        t10_data oper_data = t10_stack_pop(temp_stack, flag);
        t10_stack_push(output_stack, oper_data);
    }
    t10_stack_delete(temp_stack);
    return output_stack;
}

int check_is_operator_or_start_func(char ch) {
    int flag = 0;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == 's' || ch == 'c' ||
        ch == 't' || ch == 'l') {
        flag = 1;
    }
    return flag;
}

int check_is_sin_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 's' && (start_substr + 1 < len && str[start_substr + 1] == 'i') &&
        (start_substr + 2 < len && str[start_substr + 2] == 'n') &&
        (start_substr + 3 < len && str[start_substr + 3] == '(')) {
        flag = 1;
    }
    return flag;
}

int check_is_cos_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 'c' && (start_substr + 1 < len && str[start_substr + 1] == 'o') &&
        (start_substr + 2 < len && str[start_substr + 2] == 's') &&
        (start_substr + 3 < len && str[start_substr + 3] == '(')) {
        flag = 1;
    }
    return flag;
}

int check_is_tan_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 't' && (start_substr + 1 < len && str[start_substr + 1] == 'a') &&
        (start_substr + 2 < len && str[start_substr + 2] == 'n') &&
        (start_substr + 3 < len && str[start_substr + 3] == '(')) {
        flag = 1;
    }
    return flag;
}

int check_is_ctg_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 'c' && (start_substr + 1 < len && str[start_substr + 1] == 't') &&
        (start_substr + 2 < len && str[start_substr + 2] == 'g') &&
        (start_substr + 3 < len && str[start_substr + 3] == '(')) {
        flag = 1;
    }
    return flag;
}

int check_is_sqrt_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 's' && (start_substr + 1 < len && str[start_substr + 1] == 'q') &&
        (start_substr + 2 < len && str[start_substr + 2] == 'r') &&
        (start_substr + 3 < len && str[start_substr + 3] == 't') &&
        (start_substr + 4 < len && str[start_substr + 4] == '(')) {
        flag = 1;
    }
    return flag;
}

int check_is_ln_func(const char *str, int start_substr, int len) {
    int flag = 0;
    if (str[start_substr] == 'l' && (start_substr + 1 < len && str[start_substr + 1] == 'n') &&
        (start_substr + 2 < len && str[start_substr + 2] == '(')) {
        flag = 1;
    }
    return flag;
}

int convert_simple_operator_from_ch_to_int(char op) {
    int int_value;
    switch (op) {
        case '+':
            int_value = 1;
            break;
        case '-':
            int_value = 2;
            break;
        case '*':
            int_value = 3;
            break;
        case '/':
            int_value = 4;
            break;
        default:
            int_value = 0;
            break;
    }
    return int_value;
}

int check_operator_is_higher(int op_1, int op_2) {
    return get_operator_priority(op_1) >= get_operator_priority(op_2);
}
