#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

typedef struct no* ArvAVL;
typedef struct no No;

ArvAVL* create_arvoreAVL();
void free_no(No* no);
void free_arvoreAVL(ArvAVL* root);

int empty_arvoreAVL(ArvAVL* root);
int height_no_arvoreAVL(No* no);
int fatorBalanceamento_No(No* no);
int biggest(int number1, int number2);
int total_no_arvoreAVL(ArvAVL* root);

void rotationLL(ArvAVL* root);
void rotationRR(ArvAVL* root);
void rotationLR(ArvAVL* root);
void rotationRL(ArvAVL* root);

int insert_arvoreAVL(ArvAVL* root, int value);
No* procuraMenor(No* atual);
int remove_arvoreAVL(ArvAVL* root, int value);
int search_arvoreAVL(ArvAVL* root, int value);

#endif // ARVOREAVL_H_INCLUDED
