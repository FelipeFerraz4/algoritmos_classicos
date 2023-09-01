#define MAX_SIZE_HEAP 50

#define MAX_NAME 100

typedef struct aluno{
    int priority;
    char name[MAX_NAME];
} Aluno;

typedef struct heap{
    int size_heap;
    Aluno alunos[MAX_SIZE_HEAP];
} Heap;

Heap* create_heap();
void free_heap(Heap* heap);

int empty_heap(Heap* heap);
int full_heap(Heap* heap);

int insert_heap(Heap* heap, char* name, int priority);
int remove_heap(Heap* heap);
int search_heap(Heap* heap, char* name);
