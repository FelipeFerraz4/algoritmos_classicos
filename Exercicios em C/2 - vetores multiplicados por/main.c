#include <stdio.h>
#include <stdlib.h>

#define SIZE_USER 10

int main()
{
    int array1[SIZE_USER], array2[SIZE_USER];

    for(int i = 0; i < SIZE_USER; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &array1[i]);
        array2[i] = array1[i] * 10;
    }

    for(int i = 0; i < SIZE_USER; i++){
        printf("%d ", array2[i]);

        if(i == SIZE_USER-1){
            printf("\n");
        }
    }

    return 0;
}
