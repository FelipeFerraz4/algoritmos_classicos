#define SIZE_LIST 100

typedef struct student {
    int ID;
    char name[30];
    float test1, test2, test3;
} Student;

typedef struct list List;
List* create_list();
void free_list(List* list);
int size_list(List* list);
int full_list(List* list);
int empty_list(List* list);
int add_list_element(List* list, Student student);
int add_beginning_list(List* list, Student student);
