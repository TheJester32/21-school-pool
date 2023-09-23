#include <stdio.h>

int main() {
  int num;
  char c;
  if (scanf("%d%c", &num, &c) != 1 && (c != '\n') && (c != EOF)) {
    printf("n/a");
  } else {
    int last_digit = num % 10;
    int first_two_digits = num / 10;
    int first_digit = first_two_digits / 10;
    int second_digit = first_two_digits % 10;
    if ((second_digit < 0) || (first_digit < 0)) {
      second_digit *= -1;
      first_digit *= -1;
    }

    printf("%d", last_digit);
    printf("%d", second_digit);
    printf("%d", first_digit);
  }
  return 0;
}

// Написать программу, осуществляющую перестановку крайних цифр в целом
// трехзначном числе. Целое трехзначное число задается на стандартном потоке
// ввода stdin, результат перестановки выводится в виде трехзначного числа с
// учетом ведущих нулей на стандартный поток вывода stdout. В конце ответа не
// должно быть переноса на новую строку. Примечание: гарантируется, что на вход
// программе всегда подается целое трехзначное число.
