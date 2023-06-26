#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;//0-11 for edges,0-7 for corners
    int orientation;//0-1 for edges,0-2 for corners
}cubie;


void update_corner_orientation(cubie* corner,int rotation)
{
    corner->orientation+=rotation;
    corner->orientation%=3;
}

void update_edge_orientation(cubie* edge,int rotation)
{
    edge->orientation+=rotation;
    edge->orientation%=2;
}


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

void R(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));
    // shifting corners

    //possible memory leak as memory is allocated but not deallocated
    temp = &cube_state->corners[0];
    cube_state->corners[0]=cube_state->corners[1];
    cube_state->corners[1]=cube_state->corners[5];
    cube_state->corners[5]=cube_state->corners[4];
    cube_state->corners[4]=*temp;//Because we use the dereference operator
    free(temp);//I believe this is the solution

    update_corner_orientation(&cube_state->corners[0],2);
    update_corner_orientation(&cube_state->corners[1],1);
    update_corner_orientation(&cube_state->corners[5],2);
    update_corner_orientation(&cube_state->corners[4],1);

    cubie* temp = malloc(sizeof(cubie));

    temp = &cube_state->edges[1];
    cube_state->edges[1]=cube_state->edges[5];
    cube_state->edges[5]=cube_state->edges[9];
    cube_state->edges[9]=cube_state->edges[4];
    cube_state->edges[4]=*temp;
    free(temp);
}

void L(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));
    temp = &cube_state->corners[3];
    cube_state->corners[3]=cube_state->corners[7];
    cube_state->corners[7]=cube_state->corners[6];
    cube_state->corners[6]=cube_state->corners[2];
    cube_state->corners[2]=*temp;

    update_corner_orientation(&cube_state->corners[3],1);
    update_corner_orientation(&cube_state->corners[7],2);
    update_corner_orientation(&cube_state->corners[6],1);
    update_corner_orientation(&cube_state->corners[2],2);

    temp=&cube_state->edges[3];
    cube_state->edges[3]=cube_state->edges[7];
    cube_state->edges[7]=cube_state->edges[11];
    cube_state->edges[11]=cube_state->edges[6];
    cube_state->edges[6]=*temp;

}
//0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL
//0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL

void F(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));

    temp =&cube_state->corners[3];
    cube_state->corners[3]=cube_state->corners[2];
    cube_state->corners[2]=cube_state->corners[1];
    cube_state->corners[1]=cube_state->corners[0];
    cube_state->corners[0]=*temp;

    update_corner_orientation(&cube_state->corners[3],2);
    update_corner_orientation(&cube_state->corners[2],1);
    update_corner_orientation(&cube_state->corners[1],2);
    update_corner_orientation(&cube_state->corners[0],1);

    temp = &cube_state->edges[0];
    cube_state->edges[0]=cube_state->edges[3];
    cube_state->edges[3]=cube_state->edges[2];
    cube_state->edges[2]=cube_state->edges[1];
    cube_state->edges[1]=*temp;
    free(temp);

    update_edge_orientation(&cube_state->edges[0],1);
    update_edge_orientation(&cube_state->edges[3],1);
    update_edge_orientation(&cube_state->edges[2],1);
    update_edge_orientation(&cube_state->edges[1],1);

}

void B(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[4];
    cube_state->corners[4]=cube_state->corners[5];
    cube_state->corners[5]=cube_state->corners[6];
    cube_state->corners[6]=cube_state->corners[7];
    cube_state->corners[7]=*temp;

    update_corner_orientation(&cube_state->corners[4],2);
    update_corner_orientation(&cube_state->corners[5],1);
    update_corner_orientation(&cube_state->corners[6],2);
    update_corner_orientation(&cube_state->corners[7],1);

    temp = &cube_state->edges[8];
    cube_state->edges[8]=cube_state->edges[9];
    cube_state->edges[9]=cube_state->edges[10];
    cube_state->edges[10]=cube_state->edges[11];
    cube_state->edges[11]=*temp;
    free(temp);

    update_edge_orientation(&cube_state->edges[8],1);
    update_edge_orientation(&cube_state->edges[9],1);
    update_edge_orientation(&cube_state->edges[10],1);
    update_edge_orientation(&cube_state->edges[11],1);
}

void U(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[0];
    cube_state->corners[0]=cube_state->corners[4];
    cube_state->corners[4]=cube_state->corners[7];
    cube_state->corners[7]=cube_state->corners[3];
    cube_state->corners[3]=*temp;

    // corner orientation has not changed

    temp = &cube_state->edges[0];
    cube_state->edges[0]=cube_state->edges[4];
    cube_state->edges[4]=cube_state->edges[8];
    cube_state->edges[8]=cube_state->edges[7];
    cube_state->edges[7]=*temp;
    free(temp);

    //edges are still orientated
}

void D(Cube* cube_state)
{
    cubie* temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[2];
    cube_state->corners[2]=cube_state->corners[6];
    cube_state->corners[6]=cube_state->corners[5];
    cube_state->corners[5]=cube_state->corners[1];
    cube_state->corners[1]=*temp;
    
    // corners not changed

    temp = &cube_state->edges[2];
    cube_state->edges[2]=cube_state->edges[6];
    cube_state->edges[6]=cube_state->edges[10];
    cube_state->edges[10]=cube_state->edges[5];
    cube_state->edges[5]=*temp;
    free(temp);
}

int main()
{
    return 0;
}

