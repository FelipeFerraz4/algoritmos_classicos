#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} No;



// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir os valores da lista
void imprimirLista(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void liberarLista(No* lista){
    if(lista != NULL){
        struct Node *aux = lista;
        while(aux->next != NULL){
            free(lista);
            aux = aux->next;
        }
        free(aux);
    }
}

/*
int inserirElementoOrdenado(Node* lista, int dado){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        return 0;
    }
    newNode->data = dado;

    Node* anterior, aux = lista;
    while(aux != NULL && aux->data < dado){
        anterior = aux;
        aux = aux->next;
    }

    if(aux == NULL){
        if(anterior == NULL){
            aux =
        }
    }

    }

}
*/

int add_end(struct Node *lista, int dado){
    struct Node *no = (No*) malloc(sizeof(No));

    if(no == NULL){
        return 0;
    }

    no->data = dado;
    no->next = NULL;

    if(lista == NULL){
        lista = no;
    }
    else{
        struct Node* aux = lista;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = no;
    }

    return 1;
}
int add_start(struct Node *lista, int dado){
    struct Node *no = (struct Node*) malloc(sizeof(struct Node));

    if(no == NULL){
        return 0;
    }

    no->data = dado;
    no->next = lista;

    lista = no;
    return 1;
}

int remove_end(struct Node* lista){
    struct Node *anterior, *no = lista;
    while(no->next != NULL){
        anterior = no;
        no = no->next;
    }

    if(no == lista){
        lista = no->next;
    }
    else{
        anterior->next = no->next;
    }

    free(no);
    return 1;
}

int consulta(struct Node* lista, int dado){
    struct Node *no = lista;

    while(no != NULL && no->data != dado){
        no = no->next;
    }

    if(no == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int add_sort(struct Node* lista, int dado){
    struct Node* no = (struct Node*) malloc(sizeof(struct Node));
    if(no == NULL){
        return 0;
    }
    no->data = dado;

    if(lista == NULL){
        lista = no;
    }
    else{
        struct Node *anterior, *atual = lista;

        while(atual != NULL && atual->data < dado){
            anterior = atual;
            atual = atual->next;
        }

        if(atual == lista){
            no->next = lista;
            lista = no;
        }
        else{
            no->next = anterior->next;
            anterior->next = no;
        }
    }
    return 1;
}

int copia(struct Node* lista1, struct Node* lista2){
    struct Node *no = (struct Node*) malloc(sizeof(struct Node));
    if(no == NULL){
        return 0;
    }
    no = lista1;
    while(no != NULL){
        add_end(lista2, no->data);
        no = no->next;
    }
    return 1;
}

int main() {
    struct Node *lista1 = NULL;
    struct Node *lista2 = NULL;

    lista1 = createNode(3);
    lista2 = createNode(8);

    imprimirLista(lista1);

    add_end(lista1, 5);
    imprimirLista(lista1);

    add_end(lista1, 7);
    imprimirLista(lista1);

    add_start(lista1, 9);
    imprimirLista(lista1);

    remove_end(lista1);
    imprimirLista(lista1);

    int resultado = consulta(lista1, 5);
    printf("%d\n", resultado);

    add_sort(lista1, 9);
    imprimirLista(lista1);
    imprimirLista(lista2);

    copia(lista1, lista2);

    imprimirLista(lista2);
    imprimirLista(lista1);
    /*

    // Operações na lista 1
    inserirElementoOrdenado(&lista1, 3);
    inserirElementoOrdenado(&lista1, 1);
    inserirElementoOrdenado(&lista1, 5);

    printf("Lista 1: ");
    imprimirLista(lista1);

    // Operações na lista 2
    inserirElementoOrdenado(&lista2, 2);
    inserirElementoOrdenado(&lista2, 4);
    inserirElementoOrdenado(&lista2, 6);

    printf("Lista 2: ");
    imprimirLista(lista2);

    //Verificar se um número pertence à lista
    int numVerificar = 3;

    if (pertenceLista(lista1, numVerificar)) {
        printf("%d pertence à Lista 1\n", numVerificar);
    } else {
        printf("%d não pertence à Lista 1\n", numVerificar);
    }

    // Inserir um novo elemento na lista mantendo a ordem
    int novoElemento = 4;
    inserirElementoOrdenado(&lista1, novoElemento);
    printf("Lista 1 após inserção de %d: ", novoElemento);
    imprimirLista(lista1);

    //Remover um elemento da lista
    int elementoRemover = 1;
    removerElemento(&lista1, elementoRemover);
    printf("Lista 1 após remoção de %d: ", elementoRemover);
    imprimirLista(lista1);


    // Imprimir os valores da lista
    printf("Lista 2: ");
    imprimirLista(lista2);

    // Copiar uma lista l1 para uma lista l2
    copiarLista(lista1, &lista2);
    printf("Lista 2 após cópia da Lista 1: ");
    imprimirLista(lista2);

    */

    printf("Hello World!\n");

    // Liberar a memória ocupada pelas listas
    liberarLista(lista1);
    liberarLista(lista2);
    return 0;
}
