#include <stdio.h>
#include <stdlib.h>

int main(){
    int* array = (int*)malloc((sizeof(int)/sizeof(int)) * sizeof(int));

    int input;
    int count = 0;
    
    while(input != -1) {
        if(scanf("%d", &input) == 1){
            if(input != -1){
            array[count] = input;
            count++;
            array = (int*)realloc(array, (count+1) * sizeof(int));
            }
    }
    else{
        printf("n/a");
        exit(1);
    }
    }
    
    int size = count;

    for(int i = size-1; i >= 0; i--){
        if(i == size -1){
        printf("%d", array[i]);
        }
        else{
            printf(" %d", array[i]);
        }
    }
    free(array);
    
    return 0;
}

// Написать программу, осуществляющую вывод на стандартный поток stdout через пробел в обратном порядке элементов последовательности, 
// состоящей из целых неотрицательных чисел. Последовательность задается на стандартный поток ввода stdin,
// элементы последовательности разделены между собой пробелами, концом 
// последовательности является число -1, которое обозначает конец последовательности и
// не является ее элементом. В конце ответа не должно быть переноса на новую строку.
// Проверить на валидность введенные данные. В случае любой ошибки выводить n/a.