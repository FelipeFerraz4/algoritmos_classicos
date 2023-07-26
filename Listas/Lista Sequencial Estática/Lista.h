#define SIZE_LIST 100

struct student {
    int ID;
    char name[30];
    float test1, test2, test3;
};

typedef struct list List;
List* create_list();
void free_list(List* list);
int size_list(List* list);
int full_list(List* list);
int empty_list(List* list);
