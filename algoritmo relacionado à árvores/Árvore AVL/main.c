#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
    ArvAVL* arvoreAVL;
    arvoreAVL = create_arvoreAVL();


    free_arvoreAVL(arvoreAVL);
    printf("Hello world!\n");
    return 0;
}
