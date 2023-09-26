#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define TAMANHO_DEFAULT 100

typedef struct aluno{
    int id;
    char nome[TAMANHO_DEFAULT];
    float notas[3];
}Aluno;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* lista);

int tamanho_lista(Lista* lista);
int lista_vazia(Lista* lista);
#endif // LISTA_H_INCLUDED
