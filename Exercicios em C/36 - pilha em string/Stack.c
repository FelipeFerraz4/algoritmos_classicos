#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"

Stack create_stack(){
    Stack pilha;
    pilha.topo = NULL;
    return pilha;
}

void free_stack(Stack* pilha){
    No* aux = pilha->topo;
    while(aux != NULL){
        No* aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(pilha);
}

int push(Stack* pilha, char dado[]){
    No* newNo = (No*) malloc(sizeof(No));
    if (newNo == NULL){
        return 0;
    }
    strcpy(newNo->info, dado);
    newNo->next = pilha->topo;
    pilha->topo = newNo;
    return 1;
}

void pop(Stack* pilha, char palavra[]){
    if(pilha == NULL || pilha->topo == NULL){
        printf("pilha vazia\n");
        return 0;
    }

    No* topo = pilha->topo;
    strcpy(palavra, topo->info);

    pilha->topo = topo->next;

    free(topo);
}

void print_stack(Stack* pilha){
    No* current = pilha->topo;
    while(current != NULL){
        printf("%s ", current->info);
        current = current->next;
    }
    printf("\n");
}
