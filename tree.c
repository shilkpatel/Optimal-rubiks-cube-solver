#include "Cube.h"

#include <stdio.h>
#include <stdlib.h>

struct treenode
{
    Cube node;
    int number_of_children;
    struct treenode* children;
};
typedef struct treenode treenode;

// pointer to malloc of children
// to add, malloc again then memcopy

treenode* create_treenode(Cube data,int number_of_children)
{
    treenode* node;
    node->node=data;
    treenode* tree_child = malloc(sizeof(treenode)*number_of_children);
    return node;
}

void add_child(treenode* node,treenode child,int index)
{
    *(node->children+index)=child;
}

