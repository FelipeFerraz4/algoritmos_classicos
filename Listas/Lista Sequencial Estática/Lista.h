#define SIZE_LIST 100

typedef struct student {
    int ID;
    char name[30];
    float test1, test2, test3;
} Student;

typedef struct list_student{
    int size_element;
    Student data[SIZE_LIST];
} List;

List* create_list();
void free_list(List* list_student);

int size_list(List* list_student);
int full_list(List* list_student);
int empty_list(List* list_student);

int add_end_list_element(List* list_student, Student student);
int add_beginning_list(List* list_student, Student student);
int add_sort_list(List* list_student, Student student);

int remove_end_list(List* list_student);
int remove_beginning_list(List* list_student);
