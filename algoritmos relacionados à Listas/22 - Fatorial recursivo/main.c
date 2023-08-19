#include <stdio.h>
#include <stdlib.h>

int fatorial(int number){
    if(number == 1 || number == 0){
        return 1;
    }
    return number * fatorial(number-1);
}

int main()
{
    int number, factorial;
    printf("Digite um numero: \n");
    scanf("%d", &number);

    factorial = fatorial(number);

    printf("O valor do fatorial de %d e %d", number, factorial);
    return 0;
}
