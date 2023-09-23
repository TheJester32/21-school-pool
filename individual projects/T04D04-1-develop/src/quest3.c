#include <stdio.h>

int fib(int n) {
  if (n <= 1) {
    return n;
  }

  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  char c = '\n';

  if ((scanf("%d%c", &n, &c) == 2) && (n > 1) && (c == '\n')) {
    printf("%d", fib(n));
  } else {
    printf("n/a");
  }
  return 0;
}
