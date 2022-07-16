#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct Node
{

    void  *data;
    struct Node *next;
}Node;


/*defines functions*/
void insertFirst(struct Node** head_ref, void *new_data, size_t data_size);

void printList(struct Node *node, void (*fptr)(void *));
void print(void *n);
#endif