#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"
#include "sort.h"

#ifdef dynamic
#include <dlfcn.h>
typedef int (*ptr_dynamic)(double *, int);
int main() {
    double *data;
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        double *a = malloc(sizeof(double) * n);
        if (a == NULL) {
            printf("ERROR");
            return 0;
        }
        data = a;
        printf("LOAD DATA...\n");
        input(data, n);
        printf("RAW DATA:\n\t");
        output(data, n);
        void *library = dlopen("libdata_process.so", RTLD_LAZY);
        if (library != NULL) {
            ptr_dynamic normalization = (ptr_dynamic)dlsym(library, "normalization");
            if (normalization != NULL) {
                printf("\nNORMALIZED DATA:\n\t");
                normalization(data, n);
                output(data, n);
            } else {
                dlclose(library);
                printf("ERROR");
                return 1;
            }
            dlclose(library);
        } else {
            printf("ERROR");
            return 1;
        }

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        free(data);
        return 0;
    } else {
        printf("ERROR");
        return 0;
    }
}
#else
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"

int main() {
    double *data;
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        double *a = malloc(sizeof(double) * n);
        if (a == NULL) {
            printf("ERROR");
            return 0;
        }
        data = a;
        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        free(data);
        return 0;
    } else {
        printf("ERROR");
        return 0;
    }
}
#endif
