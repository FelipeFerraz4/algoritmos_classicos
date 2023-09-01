#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main()
{
    Heap* heap;
    heap = create_heap();

    int empty_heap_test = empty_heap(heap);
    printf("heap vazio: %d\n", empty_heap_test);

    int full_heap_test = full_heap(heap);
    printf("heap cheio: %d\n", full_heap_test);



    free_heap(heap);

    return 0;
}
