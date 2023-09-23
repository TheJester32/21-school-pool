#include "t10_io.h"

void print_welcome_message() { printf("%s", "Enter the formula:\n"); }

char *read_string(int *flag) {
    char *string = NULL;
    char *temp = NULL;
    int ch;
    int capacity = 0;
    int length = 0;

    while (((ch = getchar()) != '\n') && (ch != EOF) && *flag) {
        if ((length + 1) >= capacity) {
            if (capacity == 0) {
                capacity = 2;
            } else {
                capacity *= 2;
            }
            if ((temp = realloc(string, capacity * sizeof(char))) == NULL) {
                *flag = 0;
            }
            string = temp;
        }
        if (*flag) {
            string[length] = (char)ch;
        }
        length++;
    }
    if (*flag) {
        string[length] = '\0';
    }
    if ((temp = realloc(string, (length + 1) * sizeof(char))) == NULL) {
        *flag = 0;
    }

    string = temp;
    return string;
}

void zero_graph(char **graph) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = '.';
        }
    }
}

void output_graph(double *results) {
    char **graph = (char **)malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        graph[i] = (char *)malloc(WIDTH * sizeof(char));
    }
    zero_graph(graph);
    set_points_on_graph(graph, results);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", graph[i][j]);
            if (j == WIDTH - 1) {
                printf("\n");
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        free(graph[i]);
    }
    free(graph);
}

int check_point(double result) {
    int index = -1;
    for (int i = 0; i < HEIGHT; i++) {
        if (-1 + STEP * i - EPS < result && -1 + STEP * i + EPS > result) {
            index = i;
        } else if (result == 0) {
            index = 13;
        } else if (result == -1.0) {
            index = 0;
        } else if (result == 1.0) {
            index = 24;
        }
    }
    return index;
}

void set_points_on_graph(char **graph, double *results) {
    for (int i = 0; i < WIDTH; i++) {
        int index = check_point(results[i]);
        if (index != -1) {
            graph[index][i] = '*';
        }
    }
}