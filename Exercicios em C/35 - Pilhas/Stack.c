#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack create_Stack(void){
    Stack pilha;
    pilha.topo = NULL;
    pilha.size_stack = 0;
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

int push(Stack* pilha, int dado){
    No* newNo = (No*) malloc(sizeof(No));
    if (newNo == NULL){
        return 0;
    }

    newNo->info = dado;
    newNo->next = pilha->topo;
    pilha->topo = newNo;
    pilha->size_stack++;
    return 1;
}

void print_stack(Stack pilha){
    No* current = pilha.topo;
    while(current != NULL){
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

int pop(Stack* pilha){
    if(pilha == NULL || pilha->topo == NULL){
        printf("pilha vazia\n");
        return 0;
    }

    No* topo = pilha->topo;
    int dado = topo->info;

    pilha->topo = topo->next;
    pilha->size_stack--;

    free(topo);
    return dado;
}
