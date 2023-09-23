#include<stdio.h>

int main(void)
{
int check;
float num, num1;
int plus, minus, multiply;

check=scanf("%f %f", &num, &num1);

    if ((check == 2) && (num == (int)num && num1 == (int)num1)){

    plus = num + num1;
    minus = num - num1;
    multiply = num * num1;
    printf("%d %d %d ", plus, minus, multiply);
    num1 == 0? printf("n/a\n") : printf("%.0f\n", num/num1);
}
        else {
            
           printf("n/a\n");
           return 0;
           }

}


