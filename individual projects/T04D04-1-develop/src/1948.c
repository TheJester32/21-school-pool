#include <stdio.h>

int divide(int p, int q) {
  int res = 0;

  while (p > 0) {
    p = p - q;
    res++;
  }
  if (p == 0) {
    return res;
  } else {
    return -1;
  }
}

int find_max_prime_div(int p) {
  if (p < 0) {
    p *= -1;
  }

  int cur_q = 2, max_q = -1;
  while (cur_q <= p) {
    int r = divide(p, cur_q);
    if (r >= 0) {
      max_q = cur_q;
      p = r;
    } else {
      cur_q++;
    }
  }
  return max_q;
}

int main(void) {
  int p;
  int check = (scanf("%d", &p));
  if (check < 1) {
    printf("n/a");
    return 1;
  }

  int max_q = find_max_prime_div(p);
  if (max_q > 1) {
    printf("%d", max_q);
  } else {
    printf("n/a");
    return -1;
  }

  return 0;
}
