#ifndef LISTASEQUECIAL_H_INCLUDED
#define LISTASEQUECIAL_H_INCLUDED

#define MAX_ALUNO 50

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct lista{
    int quantidadeElemento;
    Aluno alunos[MAX_ALUNO];
}Lista;

Lista* cria_lista();
void libera_lista(Lista* lista);

int tamanho_lista(Lista* lista);
int lista_cheia(Lista* lista);
int lista_vazia(Lista* lista);
void imprime_lista(Lista* lista);

int insere_lista_final(Lista* lista, Aluno aluno);
int insere_lista_inicio(Lista* lista, Aluno aluno);
int insere_lista_ordenada(Lista* lista, Aluno aluno);
#endif // LISTASEQUECIAL_H_INCLUDED
