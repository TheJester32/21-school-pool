#include <math.h>
#include <stdio.h>

int main() {
  double result = 0;
  int r;
  double P = 21500;
  char c;
  if (scanf("%d%c", &r, &c) != 1 && (c != '\n') && (c != EOF)) {
    printf("n/a");
  } else {
    double V = (4.0 / 3.0) * M_PI * pow(r, 3);
    double m = P * V;
    result = round(m);
    printf("%.0lf", result);
  }
  return 0;
}

// Написать программу, вычисляющую массу шара в килограммах, состоящего
// полностью из платины. Радиус шара (в метрах, вещественное число) задается на
// стандартном потоке ввода stdin, а плотность платины составляет 21500 кг/м^3.
// Результат вычисления округлить по целого числа и вывести на стандартный поток
// вывода stdout. Проверить на валидность введенные данные. В случае любой
// ошибки выводить "n/a". Примечание: формула объема шара: V = (4 / 3) * рі *
// R^3 Примечание: формула плотности: P = m / V Примечание: В этом задании важна
// точность, поэтому советуем использовать константу М_PI (содержащую число пи)
// и функцию double round (double x); из библиотеки <math.h>, а также double
// вместо float. Вывод должен выглядеть таким образом - printf("%.0lf", result);
