#include <stdio.h>

#define NMAX 10

int input(int *a);
int output(int *a);
void quick_sort(int *a, int first, int last);
void swap(int *a, int *b);
void mergesort(int *a, int *b);
int output1(int *a);

int main() {
    int array[NMAX];
    int first = 0;
    int last = NMAX - 1;
    int array1[NMAX];

    if (input(array) != -1) {
        quick_sort(array, first, last);
        output(array);
        mergesort(array, array1);
        output1(array1);
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

int output1(int *b) {
    for (int i = 0; i < NMAX; i++) {
        if (b[i] == b[0]) {
            printf("\n%d", b[i]);
        } else {
            printf(" %d", b[i]);
        }
    }
    return 0;
}

void mergesort(int *a, int *b) {
    int rght, rend;
    int i, j, m;

    for (int k = 1; k < NMAX; k *= 2) {
        for (int left = 0; left + k < NMAX; left += k * 2) {
            rght = left + k;
            rend = rght + k;
            if (rend > NMAX) rend = NMAX;
            m = left;
            i = left;
            j = rght;
            while (i < rght && j < rend) {
                if (a[i] <= a[j]) {
                    b[m] = a[i];
                    i++;
                } else {
                    b[m] = a[j];
                    j++;
                }
                m++;
            }
            while (i < rght) {
                b[m] = a[i];
                i++;
                m++;
            }
            while (j < rend) {
                b[m] = a[j];
                j++;
                m++;
            }
            for (m = left; m < rend; m++) {
                a[m] = b[m];
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}