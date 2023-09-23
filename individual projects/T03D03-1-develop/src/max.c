#include <stdio.h>

int maxNumber(int a, int b){
    int res;
         if (a>b){
            res = a;
         }
         else{
            res =b;
         }
         return (res);

        }

int main (){

    float a, b, check;

    check=((scanf("%f %f", &a, &b)));

    if ((check == 2) && (a == (int)a && b == (int)b)){
        printf("%d\n", maxNumber(a, b));
    }


    else {
    printf("n/a\n");
    return 0;
    }
}
