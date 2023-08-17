#include <stdio.h>
#include <stdlib.h>

float biggest(float number[2]){
    if(number[0] >= number[1]){
        return number[0];
    }
    else{
        return number[1];
    }
}

int main()
{
    float number[2];
    printf("Digite um numero: \n");
    scanf("%f", &number[0]);

    printf("Digite um numero: \n");
    scanf("%f", &number[1]);

    float big = biggest(number);

    printf("O maior numero: %.2f\n", big);

    return 0;
}
