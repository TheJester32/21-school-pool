#include "data_io.h"

#include <stdio.h>

double input(double *data, int n) {
    for (double *p = data; p - data < n; p++) {
        if (scanf("%lf", p) != 1) {
            return -1;
        }
    }
    return 0;
}

double output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%.2lf", data[i]);
        } else {
            printf(" %.2lf", data[i]);
        }
    }
    printf("\n");
    return 0;
}
