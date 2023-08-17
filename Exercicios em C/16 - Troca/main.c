#include <stdio.h>
#include <stdlib.h>

void swap(int* number1, int* number2){
    int aux;
    aux = *number1;
    *number1 = *number2;
    *number2 = aux;
}

int main()
{
    int number[2];
    printf("Digite um numero: \n");
    scanf("%d", &number[0]);

    printf("Digite um numero: \n");
    scanf("%d", &number[1]);

    printf("Numero: %d e %d\n", number[0], number[1]);

    swap(&number[0], &number[1]);

    printf("Numero: %d e %d\n", number[0], number[1]);

    return 0;
}
