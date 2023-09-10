#include <stdlib.h>
#include "ArvoreAVL.h"

struct no{
    int info;
    int altura;
    struct no* left;
    struct no* right;
};

ArvAVL* create_arvoreAVL(){
    ArvAVL* arvore = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(arvore != NULL){
        *arvore = NULL;
    }
    return arvore;
}

void free_no(No* no){
    if(no == NULL){
        return;
    }
    free_no(no->left);
    free_no(no->right);
    free(no);
    no = NULL;
}

void free_arvoreAVL(ArvAVL* root){
    if(root == NULL){
        return;
    }
    free_no(*root);
    free(root);
}

int empty_arvoreAVL(ArvAVL* root){
    if(root == NULL){
        return 1;
    }
    if(*root == NULL){
        return 1;
    }
    return 0;
}

int height_no_arvoreAVL(No* no){
    if(no == NULL){
        return -1;
    }
    else{
        return no->altura;
    }
}

int fatorBalanceamento_No(No* no){
    return labs(height_no_arvoreAVL(no->left) -
                height_no_arvoreAVL(no->right));
}

int biggest(int number1, int number2){
    if(number1 > number2){
        return number1;
    }
    else{
        return number2;
    }
}

int total_no_arvoreAVL(ArvAVL* root){
    if(root == NULL){
        return 0;
    }

    if(*root == NULL){
        return 0;
    }

    int total_esquerdo = total_no_arvoreAVL(&((*root)->left));

    int total_direito = total_no_arvoreAVL(&((*root)->right));

    return (total_esquerdo + total_direito + 1);
}

void rotationLL(ArvAVL* root){
    No* no;

    no = (*root)->left;
    (*root)->left = no->right;
    no->right = *root;

    (*root)->altura = 1 + biggest(height_no_arvoreAVL((*root)->left),height_no_arvoreAVL((*root)->right));

    no->altura = 1 + biggest(height_no_arvoreAVL(no->left),(*root)->altura);

    *root = no;
}

void rotationRR(ArvAVL* root){
    No* no;

    no = (*root)->right;
    (*root)->right = no->left;
    no->left = (*root);

    (*root)->altura = 1 + biggest(height_no_arvoreAVL((*root)->left),height_no_arvoreAVL((*root)->right));

    no->altura = 1 + biggest(height_no_arvoreAVL(no->right),(*root)->altura);

    (*root) = no;
}

void rotationLR(ArvAVL* root){
    rotationRR(&(*root)->left);
    rotationLL(root);
}

void rotationRL(ArvAVL* root){
    rotationLL(&(*root)->right);
    rotationRR(root);
}

int insert_arvoreAVL(ArvAVL* root, int value){
    int res;

    if(*root == NULL){
        No* newNo;
        newNo = (No*) malloc(sizeof(No));
        if(newNo == NULL){
            return 0;
        }

        newNo->info = value;
        newNo->altura = 0;
        newNo->right = NULL;
        newNo->left = NULL;
        *root = newNo;
        return 1;
    }

    No* currentNo = *root;
    if(value < currentNo->info){
        if((res=insert_arvoreAVL(&(currentNo->left), value)) == 1){
            if(fatorBalanceamento_No(currentNo) >= 2){
                if(value < (*root)->left->info){
                    rotationLL(root);
                }
                else{
                    rotationLR(root);
                }
            }
        }
    }
    else{
        if(value > currentNo->info){
            if((res = insert_arvoreAVL(&(currentNo->right), value))== 1){
                if(fatorBalanceamento_No(currentNo) >= 2){
                    if((*root)->right->info < value){
                        rotationRR(root);
                    }
                    else{
                        rotationRL(root);
                    }
                }
            }
        }
        else{
            //valor duplicado
            return 0;
        }
    }

    currentNo->altura = 1 + biggest(height_no_arvoreAVL(currentNo->left),
                                height_no_arvoreAVL(currentNo->right));
    return res;
}

No* procuraMenor(No* currentNo){
    No* no1 = currentNo;
    No* no2 = currentNo->left;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->left;
    }
    return no1;
}

int remove_arvoreAVL(ArvAVL* root, int value){
    if(*root == NULL){
        return 0;
    }

    int res;

    if(value < (*root)->info){
        if((res = remove_arvoreAVL(&(*root)->left,value))==1){
            if(fatorBalanceamento_No(*root) >= 2){
                if(height_no_arvoreAVL((*root)->right->left) <=
                    height_no_arvoreAVL((*root)->right->right)){
                    rotationRR(root);
                }
                else{
                    rotationRL(root);
                }
            }
        }
    }
    if((*root)->info < value){
        if((res=remove_arvoreAVL(&(*root)->right, value))== 1){
            if(fatorBalanceamento_No(*root) >= 2){
                if(height_no_arvoreAVL((*root)->left->right) <=
                   height_no_arvoreAVL((*root)->left->left)){
                    rotationLL(root);
                }
                else{
                    rotationLR(root);
                }
            }
        }
    }
    if((*root)->info == value){
        if(((*root)->left == NULL || (*root)->right == NULL )){
            No* oldNo = (*root);
            if((*root)->left != NULL){
                *root = (*root)->left;
            }
            else{
                *root = (*root)->right;
            }
            free(oldNo);
        }
        else{
            No* tempNo = procuraMenor((*root)->right);
            (*root)->info = tempNo->info;
            remove_arvoreAVL(&(*root)->right, (*root)->info);
            if(fatorBalanceamento_No(*root) >= 2){
                if(height_no_arvoreAVL((*root)->left->right) <=
                   height_no_arvoreAVL((*root)->left->left)){
                    rotationLL(root);
                }
                else{
                    rotationLR(root);
                }
            }
        }
        return 1;
    }
    return res;

}

int search_arvoreAVL(ArvAVL* root, int value){
    if(root == NULL){
        return 0;
    }
    No* currentNo = *root;
    while(currentNo != NULL){
        if(value == currentNo->info){
            return 1;
        }
        if(value > currentNo->info){
            currentNo = currentNo->right;
        }
        else{
            currentNo = currentNo->left;
        }
    }
    return 0;
}
