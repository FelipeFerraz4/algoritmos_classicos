#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10

//MELHORIAS colocar niveis de dificuldade

int main()
{
    char new_game = 'n';
    do{
        int user_number;

        srand((unsigned)time(NULL));
        int random_number = rand() % (MAX_NUMBER+1);

        printf("---------------------------------------------------------\n");
        printf("\t\tJogo de Advinhar Numero\n");
        printf("---------------------------------------------------------\n");

        printf("Digite o numero entre 0 a %d: \n", MAX_NUMBER);
        scanf("%d", &user_number);

        printf("\nNumero sortiado: %d ", random_number);
        if(user_number == random_number){
            printf("Meus parabens, voce acertou!\n");
        }
        else{
            printf("Que pena, nao foi dessa vez\n");
        }

        printf("\nGostaria de continuar jogando, N/S: \n");
        scanf("%s", &new_game);

    }while(new_game == 's' || new_game == 'S');
    return 0;
}
