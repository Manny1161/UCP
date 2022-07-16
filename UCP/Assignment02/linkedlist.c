#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int i;
void insertFirst(struct Node** head, void *new_data, size_t data_size)
{
    /*allocate memory for the nodes*/
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->data  = malloc(data_size);
    new_node->next = (*head);
 
    for (i=0; i<data_size; i++)
    {
        /*iterate to the size of the data, setting new node to the data given*/
        *(char *)(new_node->data) = *(char *)(new_data);
    }
    
    (*head) = new_node;
}
/*print function*/
void printList(struct Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}
/*prints linked list as chars*/
void print(void *n)
{
   printf(" %c", *(char *)n);
}

