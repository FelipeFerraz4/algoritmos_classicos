#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define MAX_NOME 50

typedef struct aluno{
    int matricula;
    char nome[MAX_NOME];
    float n1,n2,n3;
}Aluno;

typedef struct hash_alunos{
    int quantidade, table_size;
    Aluno **itens;
} Hash;

Hash* create_hash(int table_size);
void free_hash(Hash* hash_alunos);

int function_hash(int key, int table_size);
int function_hash2(int key, int table_size);
int function_hash3(int key, int table_size);
int function_hash4(char *palavra);
int function_hash_universal(int a, int b,int p, int key, int table_size);

int insert_hash_sem_colisao(Hash* hash_alunos, Aluno aluno);
int search_hash_sem_colisao(Hash* hash_alunos, int matricula, Aluno* aluno);

int sondagemLinear(int position, int i, int table_size);
int sondagemQuadratica(int position, int i, int table_size);
int function_dubloHash(int H1, int key, int i, int table_size);

int insert_hash_enderAberto(Hash* hash_alunos, Aluno aluno);
int search_hash_enderAberto(Hash* hash_alunos, int matricula, Aluno* aluno);
#endif // HASH_H_INCLUDED
