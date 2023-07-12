#include "Cube.h"

typedef struct Cube_nod
{
    Cube node;
    Cube_nod* next;
}cube_node;


void push(cube_node *head, int info)
{
    cube_node *current=head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node *) malloc(sizeof(node));
    current->next->data = info;
    current->next->next = NULL;
}
