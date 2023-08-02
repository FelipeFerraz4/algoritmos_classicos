#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10

int main()
{
    int user_number;

    srand((unsigned)time(NULL));
    int random_number = rand() % (MAX_NUMBER+1);

    printf("---------------------------------------------------------\n");
    printf("\t\tJogo de Advinhar Numero\n");
    printf("---------------------------------------------------------\n");

    printf("Digite o numero entre 0 a %d: \n", MAX_NUMBER);
    scanf("%d", &user_number);

    printf("Numero sortiado: %d\n", random_number);
    if(user_number == random_number){
        printf("Meus parabens, voce acertou!\n");
    }
    else{
        printf("\nQue pena, nao foi dessa vez\n");
        printf("Voce consegue na proxima\n");
    }
    return 0;
}
