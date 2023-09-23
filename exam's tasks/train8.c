#include <stdio.h>

int main() {
  int num;
  char c;
  if ((scanf("%d%c", &num, &c) != 2) && (c != '\n') && (c != EOF)) {
    printf("n/a");
  } else {
    int total = 1;
    if (num < 0) {
      num = -num;
    }
    int counter = 0;
    while (num > 0) {
      int temp = num % 10;
      if (temp % 2 == 1) {
        total *= temp;
        counter++;
      }
      num = num / 10;
    }
    counter >= 1 ? printf("%d", total) : printf("%d", counter);
  }
  return 0;
}

// Написать программу, осуществляющую вывод на стандартный поток stdout
// произведение нечетных цифр целого числа, подаваемого через стандартный поток
// ввода stdin. Если нечетных цифр в числе нет, вывести в качестве результата 0.
// В конце ответа не должно быть переноса на новую строку.
// Проверить на валидность введенные данные. В случае любой ошибки выводить
// "n/a".
