#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("ERROR");
        return 0;
    }

    data = malloc(n * sizeof(double));
    if (data == NULL) {
        printf("ERROR");
        free(data);
        return -1;
    }
    if (input(data, n) == 0) {
        if ((make_decision(data, n))) {
            printf("YES");
            free(data);
        }
    } else {
        printf("NO");
        free(data);
    }
    return 0;
}
