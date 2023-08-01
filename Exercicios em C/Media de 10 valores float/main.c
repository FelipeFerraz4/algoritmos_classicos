#include <stdio.h>

#define SIZE_ARRAY 10

int main() {
    float array[SIZE_ARRAY];
    float mean;
    
    for(int i = 0; i < SIZE_ARRAY; i++){
        printf("Digite um número real: \n");
        scanf("%f", &array[i]);
        mean = mean + array[i];
    }
    mean = mean / SIZE_ARRAY;

    printf("Media dos valores: %.3f\n", mean);

    return 0;
}
