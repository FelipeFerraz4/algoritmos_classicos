#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack pilha = create_Stack();

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    print_stack(pilha);

    printf("%d\n", pop(&pilha));

    print_stack(pilha);

    printf("Hello world!\n");
    return 0;
}
