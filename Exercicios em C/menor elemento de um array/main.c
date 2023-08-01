#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 5

int main()
{
    int array[SIZE_ARRAY];
    int smaller;

    for(int i = 0; i < SIZE_ARRAY; i++){
        printf("Digite um numero inteiro: \n");
        scanf("%d", &array[i]);

        if(i == 0){
            smaller = array[i];
        }
        else{
            if(smaller > array[i]){
                smaller = array[i];
            }
        }
    }

    printf("Menor: %d", smaller);

    return 0;
}
