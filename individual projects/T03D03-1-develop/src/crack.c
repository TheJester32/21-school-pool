#include <stdio.h>

int main (void){

float x, y;
int check;

check=(scanf("%f %f", &x, &y));

if((x*x + y*y <= 25) && (check==2)){

 printf("GOTCHA\n");
}

else if((x*x + y*y > 25) && (x == (float)x) && (y == (float)y)){
 printf("MISS\n");
}

else{
    printf("n/a\n");
}
}
