#include <stdio.h>

#define NMAX 10

int input(int *a);
void sortArray(int *a);
int output(int *a);

int main() {
    int array[NMAX];

    if (input(array) != -1) {
        sortArray(array);
        output(array);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int check;
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &a[i]) != 1) {
            check = -1;
        }
    }
    if (getchar() != '\n') {
        check = -1;
    }
    return check;
}

int output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (a[i] == a[0]) {
            printf("%d", a[i]);
        } else {
            printf(" %d", a[i]);
        }
    }
    return 0;
}

void sortArray(int *a) {
    for (int i = 0; i < NMAX - 1; i++) {
        for (int j = 0; j < NMAX - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
