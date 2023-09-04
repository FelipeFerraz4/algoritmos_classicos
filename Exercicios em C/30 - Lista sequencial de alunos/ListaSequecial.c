#include <stdio.h>
#include <stdlib.h>
#include "ListaSequecial.h"

Lista* cria_lista(){
    Lista* lista;
    lista = (Lista*) malloc(sizeof(Lista));

    if (lista != NULL){
        lista->quantidadeElemento = 0;
    }

    return lista;
}

void libera_lista(Lista* lista){
    free(lista);
}

int tamanho_lista(Lista* lista){
    if(lista == NULL){
        return 0;
    }

    return lista->quantidadeElemento;
}

int lista_cheia(Lista* lista){
    if(lista == NULL){
        return 0;
    }

    if(lista->quantidadeElemento == MAX_ALUNO){
        return 1;
    }

    return 0;
}

int lista_vazia(Lista* lista){
    if (lista == NULL){
        return 0;
    }

    if (lista->quantidadeElemento == 0){
        return 1;
    }

    return 0;
}
void imprime_lista(Lista* lista){
    if (lista == NULL){
        return;
    }

    printf("\nLista: \n");
    for(int i = 0; i < lista->quantidadeElemento; i++){
        printf("Matricula: %d\n", lista->alunos[i].matricula);
        printf("Nome: %s\n", lista->alunos[i].nome);
        printf("Nota1: %.1f\n", lista->alunos[i].n1);
        printf("Nota2: %.1f\n", lista->alunos[i].n2);
        printf("Nota3: %.1f\n\n", lista->alunos[i].n3);
    }
}

int insere_lista_final(Lista* lista, Aluno aluno){
    if (lista == NULL){
        return 0;
    }
    if (lista_cheia(lista)){
        return 0;
    }
    lista->alunos[lista->quantidadeElemento] = aluno;
    lista->quantidadeElemento++;
    return 1;
}
int insere_lista_inicio(Lista* lista, Aluno aluno){
    if (lista == NULL){
        return 0;
    }

    if (lista_cheia(lista)){
        return 0;
    }

    for(int i = lista->quantidadeElemento; i > 0; i--){
        lista->alunos[i] = lista->alunos[i-1];
    }

    lista->alunos[0] = aluno;
    lista->quantidadeElemento++;
    return 1;
}
int insere_lista_ordenada(Lista* lista, Aluno aluno){
    if (lista == NULL){
        return 0;
    }

    if (lista_cheia(lista)){
        return 0;
    }
    int i = 0;
    while(i < lista->quantidadeElemento && lista->alunos[i].matricula < aluno.matricula){
        i++;
    }

    if(i == lista->quantidadeElemento){
        lista->alunos[lista->quantidadeElemento] = aluno;
    }
    else{
        for(int j = lista->quantidadeElemento; j > i; i--){
            lista->alunos[i] = lista->alunos[i-1];
        }
        lista->alunos[i] = aluno;
    }
    lista->quantidadeElemento++;
    return 1;
}

int remove_lista(Lista* lista, int matricula){
    if(lista == NULL){
        return 0;
    }
    if(lista->quantidadeElemento == 0){
        return 0;
    }
    int i = 0;
    while(i < lista->quantidadeElemento &&
          lista->alunos[i].matricula != matricula){
        i++;
    }

    if(i == lista->quantidadeElemento){
        return 0;
    }
    else{
        for(int j = i; j < lista->quantidadeElemento-1;j++){
            lista->alunos[j] = lista->alunos[j+1];
        }
        lista->quantidadeElemento--;
        return 1;
    }
}

int remove_lista_inicio(Lista* lista){
    if(lista == NULL){
        return 0;
    }
    if(lista->quantidadeElemento == 0){
        return 0;
    }
    for(int i = 0; i < lista->quantidadeElemento-1;i++){
        lista->alunos[i] = lista->alunos[i+1];
    }
    lista->quantidadeElemento--;
    return 1;
}

int remove_lista_final(Lista* lista){
    if(lista == NULL){
        return 0;
    }
    if(lista->quantidadeElemento == 0){
        return 0;
    }
    lista->quantidadeElemento--;
    return 1;
}

int consulta_lista_posicao(Lista* lista, int posicao,
                           Aluno* aluno){
    if(lista == NULL){
        return 0;
    }
    if(lista->quantidadeElemento == 0){
        return 0;
    }
    if(posicao < 0 || posicao > lista->quantidadeElemento){
        return 0;
    }
    *aluno = lista->alunos[posicao-1];
    return 1;

}
int consulta_lista_matricula(Lista* lista, int matricula,
                             Aluno* aluno){
    if(lista == NULL){
        return 0;
    }
    if(lista->quantidadeElemento == 0){
        return 0;
    }
    int i = 0;
    while(i < lista->quantidadeElemento && lista->alunos[i].matricula != matricula){
        i++;
    }
    if(i == lista->quantidadeElemento){
        return 0;
    }

    *aluno = lista->alunos[i];
    return 1;
}

