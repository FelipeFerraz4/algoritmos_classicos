#define MAX_SIZE_LIST 100

typedef struct item{
    int key;
    void* data;
}Item;


typedef struct generic_list{
    int size_list;
    int SIZE_TYPE;
    Item element[MAX_SIZE_LIST];
} List;


List* create_list(int SIZE_TYPE);
void free_list(List* generic_list);

int add_sort_list(List* generic_list, int key, void* element);
int remove_list(List* generic_list, int key);
int search_list(List* generic_list, int key, void* element);

void print_list(List* generic_list, void (*print_element_list) (void *));





