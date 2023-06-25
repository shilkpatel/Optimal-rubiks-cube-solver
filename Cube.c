#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;//0-11 for edges,0-7 for corners
    int orientation;//0-1 for edges,0-2 for corners
}cubie;


//the cube will be oriented such that white is up and green is front
typedef struct
{
    cubie edges[12];
    //0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL
    cubie corners[8];
    //0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL
}Cube;

Cube* create_solved_cube()
{
    Cube* new_cube = malloc(sizeof(Cube));
    for(int i=0;i<12;i++)
    {
        new_cube->edges[i].index=i;
        new_cube->edges[i].index=0;
    }

    for(int i=0;i<8;i++)
    {
        new_cube->corners[i].index=i;
        new_cube->corners[i].orientation=0;
    }
    return new_cube;
}



int main()
{
    return 0;
}

