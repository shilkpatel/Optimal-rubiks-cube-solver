#ifndef CUBE_LIST_HEADER
#define CUBE_LIST_HEADER
#include "Cube.h"

typedef struct Cube_nod
{
    Cube node;
    struct Cube_nod* next;
}cube_node;


void push(cube_node *head, Cube info);

Cube pop(cube_node *head);

Cube get(cube_node* head,int index);

void set(cube_node* head, int index, Cube data);

void insert(cube_node* head, int index, Cube data);

void list_delete(cube_node*head,int index,int data);

void list_print(cube_node* head);


#endif