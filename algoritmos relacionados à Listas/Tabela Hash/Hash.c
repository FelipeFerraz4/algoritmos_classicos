#include <stdlib.h>
#include <string.h>
#include "Hash.h"

Hash* create_hash(int table_size){
    Hash* hash_alunos = (Hash*) malloc(sizeof(Hash));
    if (hash_alunos != NULL){
        hash_alunos->table_size = table_size;
        hash_alunos->itens =
            (Aluno**) malloc(table_size * sizeof(Aluno*));
        if(hash_alunos->itens == NULL){
            free(hash_alunos);
            return NULL;
        }
        hash_alunos->quantidade = 0;
        for(int i = 0; i < hash_alunos->table_size; i++){
            hash_alunos->itens[i] = NULL;
        }
    }
    return hash_alunos;
}

void free_hash(Hash* hash_alunos){
    if(hash_alunos != NULL){
        for(int i = 0; i < hash_alunos->table_size; i++){
            if(hash_alunos->itens[i] != NULL){
                free(hash_alunos->itens[i]);
            }
        }
        free(hash_alunos->itens);
        free(hash_alunos);
    }
}

int function_hash(int key, int table_size){
    return (key & 0x7FFFFFFF) % table_size;
    //o uso do 0x7FFFFFFF evita ter overflow e números negativos
}

int function_hash2(int key, int table_size){
    float A = 0.6180339887; // contante com 0 < A < 1

    float value = key * A;
    value -= (int) value;

    return (int) (table_size * value);
}

int function_hash3(int key, int table_size){
    int number_bits = 10;
    int parte1 = key >> number_bits;
    int parte2 = key & (table_size-1);
    return (parte1 ^ parte2);
}

int function_hash4(char *palavra){
    int number = 7;
    int tamanho_palavra = strlen(palavra);
    for(int i = 0; i < tamanho_palavra; i++){
        number = 31 * number + (int) palavra[i];
    }
    return number;

}

int function_hash_universal(int a, int b,int p, int key, int table_size){
    return ((a*key + b) % p) % table_size;
    // a e b são aleatorios definidos no inicio do programa
    // 0 < a <= p
    // 0 <= b <= p
    // 0 <= key < p para todo key
    // p deve ser primo e maior que table_size
}

int insert_hash_sem_colisao(Hash* hash_alunos, Aluno aluno){
    if(hash_alunos == NULL){
        return 0;
    }

    if(hash_alunos->quantidade == hash_alunos->table_size){
        return 0;
    }

    int key = aluno.matricula;
    int position = function_hash(key, hash_alunos->table_size);
    Aluno* newAluno;

    newAluno = (Aluno*) malloc(sizeof(Aluno));

    if(newAluno == NULL){
        return 0;
    }

    *newAluno = aluno;
    hash_alunos->itens[position] = newAluno;
    hash_alunos->quantidade++;
    return 1;
}

int search_hash_sem_colisao(Hash* hash_alunos, int matricula, Aluno* aluno){
    if (hash_alunos == NULL){
        return 0;
    }

    int position = function_hash(matricula, hash_alunos->table_size);
    if(hash_alunos->itens[position] == NULL){
        return 0;
    }
    *aluno = *(hash_alunos->itens[position]);
    return 1;
}

int sondagemLinear(int position, int i, int table_size){
    return ((position + i) & 0x7FFFFFFF) % table_size;
}
int sondagemQuadratica(int position, int i, int table_size){
    position = position + 2*i + 5*i*i;
    return (position & 0x7FFFFFFF) % table_size;
}
int function_dubloHash(int H1, int key, int i, int table_size){
    int H2 = function_hash(key, table_size) + 1;
    return ((H1 + i*H2) & 0x7FFFFFFF) % table_size;
}

int insert_hash_enderAberto(Hash* hash_alunos, Aluno aluno){
    if(hash_alunos == NULL){
        return 0;
    }

    if(hash_alunos->quantidade == hash_alunos->table_size){
        return 0;
    }

    int key = aluno.matricula;
    int position, newPosition;

    position = function_hash(key, hash_alunos->table_size);

    for(int i = 0; i < hash_alunos->table_size; i++){
        newPosition = sondagemLinear(position, i, hash_alunos->table_size);
        if(hash_alunos->itens[newPosition] == NULL){
            Aluno* newAluno;
            newAluno = (Aluno*) malloc(sizeof(Aluno));
            if(newAluno == NULL){
                return 0;
            }
            *newAluno = aluno;
            hash_alunos->itens[newPosition] = newAluno;
            hash_alunos->quantidade++;
            return 1;
        }
    }
    return 0;
}

int search_hash_enderAberto(Hash* hash_alunos, int matricula, Aluno* aluno){
    if(hash_alunos == NULL){
        return 0;
    }

    int position, newPosition;

    position = function_hash(matricula, hash_alunos->table_size);

    for(int i = 0; i < hash_alunos->table_size; i++){
        newPosition = sondagemLinear(position, i, hash_alunos->table_size);

        if(hash_alunos->itens[newPosition] == NULL){
            return 0;
        }

        if(hash_alunos->itens[newPosition]->matricula == matricula){
            *aluno = *(hash_alunos->itens[newPosition]);
            return 1;
        }
    }
    return 0;
}
