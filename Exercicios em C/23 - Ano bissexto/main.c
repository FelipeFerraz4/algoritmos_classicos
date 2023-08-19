#include <stdio.h>
#include <stdlib.h>

int ano_bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        return 1;
    }
    return 0;
}

int main()
{
    int year;
    printf("Digite o ano: \n");
    scanf("%d", &year);

    if(ano_bissexto(year)){
        printf("%d e ano bissexto\n", year);
    }
    else{
        printf("%d nao e ano bissexto\n", year);
    }
    return 0;
}
