#include <stdio.h>
#include <stdlib.h>

int number_primo(int number){
    int primo = 0;
    for(int i = number; i > 1; i--){
        if(number % i){
            primo = 1;
        }
    }

    return primo;
}

int main()
{
    int primo;
    printf("Digite um numro: \n");
    scanf("%d", &primo);

    if(primo == 0){
        printf("Não e primo\n");
    }
    else{
        printf("E primo");
    }
    return 0;
}
