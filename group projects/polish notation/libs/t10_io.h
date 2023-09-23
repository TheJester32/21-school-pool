#ifndef T10_IO_H
#define T10_IO_H

#define WIDTH 80
#define HEIGHT 25
#define STEP 2.0 / 24.0
#define EPS 2.0 / 24.0 / 2.0
#define BUFFERSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "t10_parser.h"
#include "t10_stack.h"

void print_welcome_message();
char *read_string(int *flag);
void zero_graph(char **graph);
void output_graph(double *results);
int check_point(double result);
void set_points_on_graph(char **graph, double *results);

#endif  // T10_IO_H