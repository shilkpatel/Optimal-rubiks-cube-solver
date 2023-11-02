#include "Cube.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Cube_nod
{
    Cube node;
    struct Cube_nod* next;
}cube_node;


void push(cube_node *head, Cube info)
{
    cube_node *current=head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (cube_node *) malloc(sizeof(cube_node));
    current->next->node = info;
    current->next->next = NULL;
}

Cube pop(cube_node *head)
{
    cube_node* current= head;
    while(1)
    {

        if(current->next->next==NULL)
        {
            Cube data=current->next->node;
            free(current->next);
            current->next=NULL;
            return data;
        }
        else
        {
            current=current->next;
        }
    }
}

Cube get(cube_node* head,int index)
{
    cube_node *current_node=head;
    int counter=0;
    while(1)
    {
        if(counter==index)
        {
            return current_node->node;
        }
        else
        {
            current_node=current_node->next;
            counter++;
        }
    }
}

void set(cube_node* head, int index, Cube data)
{
    int counter=0;
    cube_node* current_node= head;
    cube_node* nxt = NULL;

    while(1)
    {
        if(counter==index)
        {
            current_node->node=data;
            return;
        }
        else if (current_node->next==NULL)
        {
            return;
        }
        else
        {
            nxt=current_node->next;
            current_node=nxt;
            counter++;
        }
    }
}

//adds the data to the index given and therefore
//pushes the data later on further
void insert(cube_node* head, int index, Cube data)
{
    int counter=0;
    cube_node* current_node= head;
    cube_node* nxt = NULL;
    if(index==0)
    {
        cube_node *new_node = malloc(sizeof(cube_node));
        new_node->node=data;
        new_node->next=current_node;
        
        return;
    }

    while(1)
    {
        if(counter==index-1)
        {
            cube_node *new_node = malloc(sizeof(cube_node));//creates node
            new_node->node=data;
            new_node->next=current_node->next;//next pointer is set to the pointer present in current node
            current_node->next=new_node;//current node changed to fit new node in chain
            return;
        }
        else if ((*current_node).next==NULL)
        {
            return;
        }
        else
        {
            nxt=(*current_node).next;
            current_node=nxt;
            counter++;
        }
    }
}

void list_delete(cube_node*head,int index,int data)
{
    int counter=0;
    cube_node* current_node=head;
    cube_node* nxt=NULL;

    if(index==0)
    {
        // the current node
        head=current_node->next;
    }

    while(1)
    {
        if(counter==index-1)
        {
            cube_node* next_node_pointer=current_node->next;
            cube_node next_node=*next_node_pointer;
            current_node->next=next_node.next;
            return;
        }
        else if ((*current_node).next==NULL)
        {
            return;
        }
        else
        {
            nxt=(*current_node).next;
            current_node=nxt;
            counter++;
        }
    }

}

void list_print(cube_node* head)
{
    cube_node* current_node=head;
    cube_node* nxt=NULL;
/*
    while(!((*current_node).next==NULL))
    {
        printf("%d\n",(*current_node).data);
        nxt=(*current_node).next;
        current_node=nxt;
    }
*/

    while(1)
    {
        //printf("%d",current_node->data);
        if(current_node->next==NULL)
        {
            printf("%d",current_node->node);
            return;
        }
        else
        {
            printf("%d\n",current_node->node);
            nxt=current_node->next;
            current_node=nxt;
        }
    }
}