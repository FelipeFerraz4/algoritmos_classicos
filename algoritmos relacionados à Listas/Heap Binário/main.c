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

    insert_heap(heap, "julia", 67);
    insert_heap(heap, "antonia", 1);
    insert_heap(heap, "jesica", 66);
    insert_heap(heap, "jaqueline", 78);
    insert_heap(heap, "joice", 37);
    insert_heap(heap, "julia", 6);
    insert_heap(heap, "antonia", 21);
    insert_heap(heap, "jesica", 37);
    insert_heap(heap, "jaqueline", 54);
    insert_heap(heap, "joice", 47);

    print_heap(heap);

    free_heap(heap);

    return 0;
}
