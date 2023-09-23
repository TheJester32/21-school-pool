#include <stdio.h>
#include <math.h>

int main (void){

    float x, a, b, c;
    double y;
    scanf("%f", &x);

     if ((x == (float)x) && (x != 0) )
     {
    a = pow(7*10,-3) * pow(x,4);
    b = (22.8 * pow(x, 1/3) - pow(1*10, 3) * x + 3) / (x * x / 2);
    c = pow((10 + x),(2/x));
    y = a + b - x * c - 1.01;
    printf("%.1lf\n", y);
     }

     else
     {
       printf("n/a\n");
       return 0;
     }
}