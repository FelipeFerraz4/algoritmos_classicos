#include <stdio.h>
#include <stdlib.h>
//Questão 1
void multiplicidade_numero() {
    //definindo variaveis
    int quantidade_numero, maior_numero;

    //pegando tamanho do vetor
    printf("Digite a quantidade de numero do vetor:\n");
    scanf("%d", &quantidade_numero);

    //criando o vetor
    int *vetor = (int*) malloc(sizeof(int) * quantidade_numero);

    if(vetor){

        //inserindo numeros no vetor
        for(int i = 0; i < quantidade_numero; i++){
            printf("Digite o numero %d do vetor: \n", i+1);
            scanf("%d", &vetor[i]);
        }

        //pegar o maior valor digitado
        for(int i = 0; i < quantidade_numero; i++){
            if(i == 0) {
                maior_numero = vetor[i];
            }
            if(vetor[i] > maior_numero){
                maior_numero = vetor[i];
            }
        }

        //criar o vetor com a multiplicidade dos numeros
        int *vetor2 = (int*) malloc(sizeof(int) * maior_numero);

        if(vetor2) {
            //colocar zero a multiplicidade nos index
            for(int i = 0; i < maior_numero; i++){
                vetor2[i] = 0;
            }

            //adicionar mais um a cada aparição no vetor do ususario
            for(int i = 0; i < quantidade_numero; i++){
                vetor2[vetor[i]-1] += 1;
            }

            //mostrando o numero e a multiplicidade
            for(int i = 0; i < maior_numero; i++){
                if (vetor2[i] > 0) {
                    printf("Numero %d, quantidade: %d\n", i+1, vetor2[i]);
                }
            }
        } else {
            printf("vetor2 nao alocado");
        }
        //liberar vetor2
        free(vetor2);
    } else {
        printf("vetor1 nao alocado\n");
    }
    //liberar vetor1
    free(vetor);
}

void maior_degrau(){
    //definindo variaveis
    int quantidade_numero, maior_diferenca;

    //pegando tamanho do vetor
    printf("Digite a quantidade de numero do vetor:\n");
    scanf("%d", &quantidade_numero);

    //criando o vetor
    int *vetor = (int*) malloc(sizeof(int) * quantidade_numero);

    if(vetor) {
        //inserindo numeros no vetor
        for(int i = 0; i < quantidade_numero; i++){
            printf("Digite o numero %d do vetor: \n", i+1);
            scanf("%d", &vetor[i]);
        }

        //pegar a maior diferenca
        for(int i = 0; i < quantidade_numero - 1; i++){
            if(i == 0) {
                maior_diferenca = abs(vetor[i+1] - vetor[i]);
            }
            if(abs(vetor[i+1] - vetor[i]) > maior_diferenca){
                maior_diferenca = abs(vetor[i+1] - vetor[i]);
            }

        }

        //imprimindo a maior diferença
        printf("a maior altura de um degrau na sequencia e %d", maior_diferenca);
    }

    //liiberando vetor
    free(vetor);
}

void media_linha_matriz() {
    //definindo variaveis
    int linhas;

    //pegando o tamanho da matriz
    printf("Digite a quantidade de linhas da matriz:\n");
    scanf("%d", &linhas);

    //criando a linha externa da matriz - linhas
    int **matriz = (int**) malloc(sizeof(int*) * linhas);

    //alocando as linhas interna da matriz - colunas
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int*) malloc(sizeof(int) * linhas);
    }

    //pegando valor da matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < linhas; j++){
            printf("Digite o numero da matriz[%d][%d]: \n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    //criando o vetor
    float *vetor = (float*) malloc(sizeof(float) * linhas);

    //pegando as medias das linhas
    for(int i = 0; i < linhas; i++){
        float media = 0;
        for(int j = 0; j < linhas; j++){
            media += matriz[i][j];
        }
        media /= linhas;
        vetor[i] = media;
    }

    //imprimindo a media
    for(int i = 0; i < linhas; i++){
        printf("Media da linha %d: %.2f\n", i, vetor[i]);
    }

    //imprimir matriz por elemento
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < linhas; j++){
            printf("Digite o numero da matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }
    /*
    //imprimir matriz em formato de matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < linhas; j++){
            printf("%d ", i, j, matriz[i][j]);
        }
        printf("\n");
    }
    */

    //liberando as linhas internas da matriz - colunas
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    //liberando a linha externa da matriz - linhas
    free(matriz);
    //liberar vetor
    free(vetor);
}
int main()
{
    //questão 1
        //multiplicidade_numero();

    //questão 2
        //maior_degrau();

    //questao 3
        media_linha_matriz();
    return 0;
}
