#include <stdio.h>

int factorial(int n);

int main() {
  int num;
  char c;
  if ((scanf("%d%c", &num, &c) != 1 && (c != '\n') && (c != EOF)) ||
      (num < 0)) {
    printf("n/a");
  } else {
    for (int k = 0; k <= num; k++) {
      int coef = factorial(num) / (factorial(k) * factorial(num - k));

      printf("%d", coef);
    }
  }
  return 0;
}

int factorial(int num) {
  int result = 1;
  for (int i = 1; i <= num; i++) {
    result *= i;
  }
  return result;
}

// Написать программу, осуществляющую вывод на стандартный поток stdout
// строки состоящей из биномиальных коэффициентов для k=0..n разделенных
// пробелами. ! - операция взятия факториала, факториал числа n вычисляется как
// n! = 1*2*3*...*n, параметр n задается в виде неотрицательного целого числа
// через стандартный поток ввода stdin. В конце ответа не должно быть переноса
// на новую строку.