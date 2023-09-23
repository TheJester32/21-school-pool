#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void sortArray(int *a, int n);
int output(int *a, int n);

int main() {
  int n;
  scanf("%d", &n);
  int *array = (int *)malloc(n * sizeof(int));

  if (input(array, n) != -1) {
    sortArray(array, n);
    output(array, n);
  } else {
    printf("n/a");
  }

  free(array);
  return 0;
}

int input(int *a, int n) {
  int check;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) != 1) {
      check = -1;
    }
  }
  return check;
}

int output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      printf("%d", a[i]);
    } else {
      printf(" %d", a[i]);
    }
  }
  return 0;
}

void sortArray(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}