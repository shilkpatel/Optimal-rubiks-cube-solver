#include "Cube.h"

#include <stdio.h>

typedef struct treenode
{
    Cube node;
    struct treenode* children;
};

// pointer to malloc of children
// to add, malloc again then memcopy
