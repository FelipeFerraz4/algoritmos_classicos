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
    char nome[DEFAULT_MAX];
    int quantidade;
}Recurso;

typedef struct nave_espacial{
    int prioridade;
    int tipo_nave;
    int quantidade_pessoas;
    int quantidade_recursos;
}Nave;

typedef struct heap{
    int quantidade_nave;
    Nave naves[DEFAULT_MAX];
}Heap;

Heap* criar_heap();
void libera_heap(Heap* fila_de_naves);

int tamanho_heap(Heap* fila_de_naves);
int heap_cheio(Heap* fila_de_naves);
int heap_vazio(Heap* fila_de_naves);

#endif // HEAP_H_INCLUDED
