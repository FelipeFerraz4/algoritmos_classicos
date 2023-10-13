#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#define DEFAULT_MAX 100

typedef struct pessoa{
    int id;
    char nome[DEFAULT_MAX];
    int idade;
    char planeta[DEFAULT_MAX];
}Pessoa;

typedef struct recurso{
    int id;
    char nome[DEFAULT_MAX];
    int quantidade;
}Recurso;

typedef struct nave{
    char nome[DEFAULT_MAX];
    int quantidade_pessoas;
    Pessoa pessoa[DEFAULT_MAX];
    int quantidade_recursos;
    Recurso recurso[DEFAULT_MAX];
} Nave;

typedef struct dados{
    int prioridade;
    Nave nave;
} Dados;

typedef struct heap{
    int quantidade_nave;
    Dados dados[DEFAULT_MAX];
}Heap;

Heap* criar_heap();
void libera_heap(Heap* fila_de_naves);

int tamanho_heap(Heap* fila_de_naves);
int heap_cheio(Heap* fila_de_naves);
int heap_vazio(Heap* fila_de_naves);

void subir_heap(Heap* fila_de_naves, int filho);
void descer_heap(Heap* fila_de_naves, int pai);

int inserir_heap(Heap* fila_de_naves, Nave nave, int prioridade);
int remove_heap(Heap* fila_de_naves);

int verifica_prioridade(int prioridade);
void teste_heap(Heap* fila_de_naves);

int option_list();
int option_programa(Heap* fila_de_naves);
int get_nave_file(Heap* fila_de_naves);

#endif // HEAP_H_INCLUDED
