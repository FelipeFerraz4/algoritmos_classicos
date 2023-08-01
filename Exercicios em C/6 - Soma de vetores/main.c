#include <stdio.h>

#define SIZE_ARRAY 5

int main() {
    float array1[SIZE_ARRAY], array2[SIZE_ARRAY], array3[SIZE_ARRAY];
    
    for(int i = 0; i < SIZE_ARRAY; i++){
        printf("Digite um numero do array 1: \n");
        scanf("%f", &array1[i]);
    }
    for(int i = 0; i < SIZE_ARRAY; i++){
        printf("Digite um numero do array 2: \n");
        scanf("%f", &array2[i]);
    }
    
    for(int i = 0; i < SIZE_ARRAY; i++){
        array3[i] = array1[i] + array2[i];
        printf("%.2f + %.2f = %.2f\n", array1[i], array2[i], array3[i]);
    }
    
    return 0;
}
