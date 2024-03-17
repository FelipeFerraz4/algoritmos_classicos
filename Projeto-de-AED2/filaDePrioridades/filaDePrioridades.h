#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#define DEFAULT_MAX 100
#define TAMANHO_HASH 23

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

// Definição de estrutura de nó para a lista encadeada
typedef struct elemento {
    int id_1, id_2, id_3;
    struct elemento* proximo;
}Elemento;

typedef struct lista {
    int tamanho_lista;
    Elemento* elemento;
} Lista;

typedef struct tableHash {
    Lista lista_elementos[TAMANHO_HASH];
} TableHash;

Heap* criar_heap();
void libera_heap(Heap* fila_de_naves);

int tamanho_heap(Heap* fila_de_naves);
int heap_cheio(Heap* fila_de_naves);
int heap_vazio(Heap* fila_de_naves);

void subir_heap(Heap* fila_de_naves, int filho);
void descer_heap(Heap* fila_de_naves, int pai);

int inserir_heap(Heap* fila_de_naves, Nave nave, int prioridade);
int remove_heap(Heap* fila_de_naves);
int remove_heap_ids(Heap* fila_de_naves, int ids_recursos[]);

int verifica_prioridade(int prioridade);
void teste_heap(Heap* fila_de_naves);

int option_list();
int option_programa(Heap* fila_de_naves, TableHash* hash_nave);
int get_nave_file(Heap* fila_de_naves);


Elemento* cria_elemento(int id1, int id2, int id3);
//void criarHashTable();
int insereHash(TableHash* hash_nave, int id1, int id2, int id3);
int buscaHash(TableHash* hash_nave, int id1, int id2, int id3);
void print_hash(TableHash* hash_nave);
void remove_lista_Hash(TableHash* hash_nave, int id1, int id2, int id3);
int verificaLista(TableHash* hash_nave, int id1, int id2, int id3);

int teste_hash();
TableHash* cria_hash();
void libera_hash(TableHash* hash_nave);


#endif // HEAP_H_INCLUDED
