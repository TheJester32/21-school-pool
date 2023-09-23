#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int output(int *a, int n, double mean_v, double variance_v);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) != -1) {
        output(data, n, mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int check;
    if ((scanf("%d", n) == 0 || *n <= 0)) {
        check = -1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            check = -1;
        }
    }
    if (getchar() != '\n') {
        check = -1;
    }
    return check;
}

double mean(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
}

double variance(int *a, int n) {
    double var = 0;
    double mean_ = mean(a, n);
    for (int i = 0; i < n; i++) {
        var += (a[i] - mean_) * (a[i] - mean_);
    }
    return var / n;
}

int output(int *a, int n, double mean_v, double variance_v) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= mean_v) && (a[i] <= mean_v + 3 * sqrt(variance_v)) && (a[i] != 0)) {
            res = a[i];
            break;
        }
    }
    printf("%d", res);
    return 0;
}
