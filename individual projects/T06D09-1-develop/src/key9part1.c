#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *n);
int sum_numbers(int *buffer);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int n, buffer[NMAX];
    int length = sizeof(buffer) / sizeof(buffer[0]);
    int numbers[length];

    if (input(buffer, &n) == 0) {
        printf("%d\n", sum_numbers(buffer));
        int count = find_numbers(buffer, length, sum_numbers(buffer), numbers);
        for (int i = 0; i < count; i++) {
            if (numbers[i] == numbers[0]) {
                printf("%d", numbers[i]);
            } else {
                printf(" %d", numbers[i]);
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) != 2 || *n <= 0 || *n > NMAX || c != '\n') {
        return -1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return -1;
        }
    }
    return 0;
}

int sum_numbers(int *buffer) {
    int sum = 0;
    for (int i = 0; i < NMAX; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[count] = buffer[i];
                count++;
            }
        }
    }
    return count;
}
