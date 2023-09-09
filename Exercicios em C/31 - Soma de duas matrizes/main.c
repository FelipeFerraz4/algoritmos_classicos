#include <stdio.h>
#include <stdlib.h>

void somaMatrizes3D(int dimension,
                    int matrizA[][dimension][dimension],
                    int matrizB[][dimension][dimension],
                    int matrizResultante[][dimension][dimension]){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            for(int k = 0; k < dimension; k++){
                matrizResultante[i][j][k] = matrizA[i][j][k] + matrizB[i][j][k];
            }
        }
    }
}

void adicionarElementoMatriz(int dimension,int matriz[dimension][dimension][dimension], int number){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            for(int k = 0; k < dimension; k++){
                matriz[i][j][k] = number;
            }
        }
    }
}

int main()
{
    int dimension = 3;
    int matrizResultado[dimension][dimension][dimension];
    int matrizA[dimension][dimension][dimension]; //= {{{2,2,2},{2,2,2},{2,2,2}}, {{2,2,2}, {2,2,2}, {2,2,2}}, {{2,2,2}, {2,2,2}, {2,2,2}}};
    int matrizB[dimension][dimension][dimension]; //= {{{1,1,1},{1,1,1},{1,1,1}}, {{1,1,1}, {1,1,1}, {1,1,1}}, {{1,1,1}, {1,1,1}, {1,1,1}}};

    adicionarElementoMatriz(dimension, matrizA, 1);
    adicionarElementoMatriz(dimension, matrizB, 2);

    somaMatrizes3D(dimension, matrizA, matrizB, matrizResultado);

    printf("%d\n", matrizA[0][0][0]);
    printf("%d\n", matrizB[0][0][0]);
    printf("%d\n", matrizResultado[0][0][0]);

    printf("Hello world!\n");
    return 0;
}
