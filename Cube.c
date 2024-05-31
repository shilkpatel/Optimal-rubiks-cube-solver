#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;       // 0-11 for edges,0-7 for corners
    int orientation; // 0-1 for edges,0-2 for corners
} cubie;

void update_corner_orientation(cubie *corner, int rotation)
{
    corner->orientation += rotation;
    corner->orientation %= 3;
}

void update_edge_orientation(cubie *edge, int rotation)
{
    edge->orientation += rotation;
    edge->orientation %= 2;
}

// the cube will be oriented such that white is up and green is front
typedef struct
{
    cubie edges[12];
    // 0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL
    cubie corners[8];
    // 0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL
} Cube;

Cube *create_solved_cube()
{
    Cube *new_cube = malloc(sizeof(Cube));
    for (int i = 0; i < 12; i++)
    {
        new_cube->edges[i].index = i;
        new_cube->edges[i].index = 0;// should be orientation
    }

    for (int i = 0; i < 8; i++)
    {
        new_cube->corners[i].index = i;
        new_cube->corners[i].orientation = 0;
    }
    return new_cube;
}

void R(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));
    // shifting corners

    // possible memory leak as memory is allocated but not deallocated
    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[1];
    cube_state->corners[1] = cube_state->corners[5];
    cube_state->corners[5] = cube_state->corners[4];
    cube_state->corners[4] = *temp; // Because we use the dereference operator
    ;                     // I believe this is the solution

    update_corner_orientation(&cube_state->corners[0], 2);
    update_corner_orientation(&cube_state->corners[1], 1);
    update_corner_orientation(&cube_state->corners[5], 2);
    update_corner_orientation(&cube_state->corners[4], 1);

    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->edges[1];
    cube_state->edges[1] = cube_state->edges[5];
    cube_state->edges[5] = cube_state->edges[9];
    cube_state->edges[9] = cube_state->edges[4];
    cube_state->edges[4] = *temp;
    ;
}

void R_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));
    // shifting corners

    // possible memory leak as memory is allocated but not deallocated
    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[5];
    cube_state->corners[5] = cube_state->corners[1];
    cube_state->corners[1] = *temp;

    update_corner_orientation(&cube_state->corners[0], 2);
    update_corner_orientation(&cube_state->corners[1], 1);
    update_corner_orientation(&cube_state->corners[5], 2);
    update_corner_orientation(&cube_state->corners[4], 1);

    temp = &cube_state->edges[1];
    cube_state->edges[1] = cube_state->edges[4];
    cube_state->edges[4] = cube_state->edges[9];
    cube_state->edges[9] = cube_state->edges[5];
    cube_state->edges[5] = *temp;
    ;
}

void R2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[5];
    cube_state->corners[5] = *temp;

    // 4,5
    temp = &cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[1];
    cube_state->corners[1] = *temp;

    temp = &cube_state->edges[1];
    cube_state->edges[1] = cube_state->edges[9];
    cube_state->edges[9] = *temp;

    temp = &cube_state->edges[4];
    cube_state->edges[4] = cube_state->edges[5];
    cube_state->edges[5] = *temp;
    ;
}

void L(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));
    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[7];
    cube_state->corners[7] = cube_state->corners[6];
    cube_state->corners[6] = cube_state->corners[2];
    cube_state->corners[2] = *temp;

    update_corner_orientation(&cube_state->corners[3], 1);
    update_corner_orientation(&cube_state->corners[7], 2);
    update_corner_orientation(&cube_state->corners[6], 1);
    update_corner_orientation(&cube_state->corners[2], 2);

    temp = &cube_state->edges[3];
    cube_state->edges[3] = cube_state->edges[7];
    cube_state->edges[7] = cube_state->edges[11];
    cube_state->edges[11] = cube_state->edges[6];
    cube_state->edges[6] = *temp;
    ;
}

void L_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));
    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[6];
    cube_state->corners[6] = cube_state->corners[7];
    cube_state->corners[7] = *temp;

    update_corner_orientation(&cube_state->corners[3], 1);
    update_corner_orientation(&cube_state->corners[7], 2);
    update_corner_orientation(&cube_state->corners[6], 1);
    update_corner_orientation(&cube_state->corners[2], 2);

    temp = &cube_state->edges[3];
    cube_state->edges[3] = cube_state->edges[6];
    cube_state->edges[6] = cube_state->edges[11];
    cube_state->edges[11] = cube_state->edges[7];
    cube_state->edges[7] = *temp;
}

void L2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));
    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[6]; // 36 27
    cube_state->corners[6] = *temp;

    temp = &cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[7];
    cube_state->corners[7] = *temp;

    temp = &cube_state->edges[3];
    cube_state->edges[3] = cube_state->edges[11]; // 311 67
    cube_state->edges[11] = *temp;

    temp = &cube_state->edges[6];
    cube_state->edges[6] = cube_state->edges[7];
    cube_state->edges[7] = *temp;
    ;
}

void F(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[1];
    cube_state->corners[1] = cube_state->corners[0];
    cube_state->corners[0] = *temp;

    update_corner_orientation(&cube_state->corners[3], 2);
    update_corner_orientation(&cube_state->corners[2], 1);
    update_corner_orientation(&cube_state->corners[1], 2);
    update_corner_orientation(&cube_state->corners[0], 1);

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[3];
    cube_state->edges[3] = cube_state->edges[2];
    cube_state->edges[2] = cube_state->edges[1];
    cube_state->edges[1] = *temp;
    ;

    update_edge_orientation(&cube_state->edges[0], 1);
    update_edge_orientation(&cube_state->edges[3], 1);
    update_edge_orientation(&cube_state->edges[2], 1);
    update_edge_orientation(&cube_state->edges[1], 1);
}

void F_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[1];
    cube_state->corners[1] = cube_state->corners[2];
    cube_state->corners[2] = *temp;

    update_corner_orientation(&cube_state->corners[3], 2);
    update_corner_orientation(&cube_state->corners[2], 1);
    update_corner_orientation(&cube_state->corners[1], 2);
    update_corner_orientation(&cube_state->corners[0], 1);

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[1];
    cube_state->edges[1] = cube_state->edges[2];
    cube_state->edges[2] = cube_state->edges[3];
    cube_state->edges[3] = *temp;
    ;

    update_edge_orientation(&cube_state->edges[0], 1);
    update_edge_orientation(&cube_state->edges[3], 1);
    update_edge_orientation(&cube_state->edges[2], 1);
    update_edge_orientation(&cube_state->edges[1], 1);
}

void F2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[1]; // 31 02
    cube_state->corners[1] = *temp;

    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[2];
    cube_state->corners[2] = *temp;

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[2]; // 02 13
    cube_state->edges[2] = *temp;

    temp = &cube_state->edges[1];
    cube_state->edges[1] = cube_state->edges[3];
    cube_state->edges[3] = *temp;
    ;
}

void B(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[5];
    cube_state->corners[5] = cube_state->corners[6];
    cube_state->corners[6] = cube_state->corners[7];
    cube_state->corners[7] = *temp;

    update_corner_orientation(&cube_state->corners[4], 2);
    update_corner_orientation(&cube_state->corners[5], 1);
    update_corner_orientation(&cube_state->corners[6], 2);
    update_corner_orientation(&cube_state->corners[7], 1);

    temp = &cube_state->edges[8];
    cube_state->edges[8] = cube_state->edges[9];
    cube_state->edges[9] = cube_state->edges[10];
    cube_state->edges[10] = cube_state->edges[11];
    cube_state->edges[11] = *temp;
    ;

    update_edge_orientation(&cube_state->edges[8], 1);
    update_edge_orientation(&cube_state->edges[9], 1);
    update_edge_orientation(&cube_state->edges[10], 1);
    update_edge_orientation(&cube_state->edges[11], 1);
}

void B_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[7];
    cube_state->corners[7] = cube_state->corners[6];
    cube_state->corners[6] = cube_state->corners[5];
    cube_state->corners[5] = *temp;

    update_corner_orientation(&cube_state->corners[4], 2);
    update_corner_orientation(&cube_state->corners[5], 1);
    update_corner_orientation(&cube_state->corners[6], 2);
    update_corner_orientation(&cube_state->corners[7], 1);

    temp = &cube_state->edges[8];
    cube_state->edges[8] = cube_state->edges[11];
    cube_state->edges[11] = cube_state->edges[10];
    cube_state->edges[10] = cube_state->edges[9];
    cube_state->edges[9] = *temp;
    ;

    update_edge_orientation(&cube_state->edges[8], 1);
    update_edge_orientation(&cube_state->edges[9], 1);
    update_edge_orientation(&cube_state->edges[10], 1);
    update_edge_orientation(&cube_state->edges[11], 1);
}

void B2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[6]; // 46 75
    cube_state->corners[6] = *temp;

    temp = &cube_state->corners[7];
    cube_state->corners[7] = cube_state->corners[5];
    cube_state->corners[5] = *temp;

    temp = &cube_state->edges[8];
    cube_state->edges[8] = cube_state->edges[10]; // 810 119
    cube_state->edges[10] = *temp;

    temp = &cube_state->edges[11];
    cube_state->edges[11] = cube_state->edges[9];
    cube_state->edges[9] = *temp;
    ;
}

void U(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[4];
    cube_state->corners[4] = cube_state->corners[7];
    cube_state->corners[7] = cube_state->corners[3];
    cube_state->corners[3] = *temp;

    // corner orientation has not changed

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[4];
    cube_state->edges[4] = cube_state->edges[8];
    cube_state->edges[8] = cube_state->edges[7];
    cube_state->edges[7] = *temp;
    ;

    // edges are still orientated
}

void U_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[7];
    cube_state->corners[7] = cube_state->corners[4];
    cube_state->corners[4] = *temp;

    // corner orientation has not changed

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[7];
    cube_state->edges[7] = cube_state->edges[8];
    cube_state->edges[8] = cube_state->edges[4];
    cube_state->edges[4] = *temp;
    ;
}

void U2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[0];
    cube_state->corners[0] = cube_state->corners[7]; // 07 34
    cube_state->corners[7] = *temp;

    temp = &cube_state->corners[3];
    cube_state->corners[3] = cube_state->corners[4];
    cube_state->corners[4] = *temp;

    // corner orientation has not changed

    temp = &cube_state->edges[0];
    cube_state->edges[0] = cube_state->edges[8]; // 08 74
    cube_state->edges[8] = *temp;

    temp = &cube_state->edges[7];
    cube_state->edges[7] = cube_state->edges[4];
    cube_state->edges[4] = *temp;
    ;
}

void D(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[6];
    cube_state->corners[6] = cube_state->corners[5];
    cube_state->corners[5] = cube_state->corners[1];
    cube_state->corners[1] = *temp;

    // corners not changed

    temp = &cube_state->edges[2];
    cube_state->edges[2] = cube_state->edges[6];
    cube_state->edges[6] = cube_state->edges[10];
    cube_state->edges[10] = cube_state->edges[5];
    cube_state->edges[5] = *temp;
    ;
}

void D_prime(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[1];
    cube_state->corners[1] = cube_state->corners[5];
    cube_state->corners[5] = cube_state->corners[6];
    cube_state->corners[6] = *temp;

    // corners not changed

    temp = &cube_state->edges[2];
    cube_state->edges[2] = cube_state->edges[5];
    cube_state->edges[5] = cube_state->edges[10];
    cube_state->edges[10] = cube_state->edges[6];
    cube_state->edges[6] = *temp;
    ;
}

void D2(Cube *cube_state)
{
    cubie *temp = malloc(sizeof(cubie));

    temp = &cube_state->corners[2];
    cube_state->corners[2] = cube_state->corners[5]; // 25 16
    cube_state->corners[5] = *temp;

    temp = &cube_state->corners[1];
    cube_state->corners[1] = cube_state->corners[6];
    cube_state->corners[6] = *temp;

    // corners not changed

    temp = &cube_state->edges[2];
    cube_state->edges[2] = cube_state->edges[10]; // 210 56
    cube_state->edges[10] = *temp;

    temp = &cube_state->edges[5];
    cube_state->edges[5] = cube_state->edges[6];
    cube_state->edges[6] = *temp;
    ;
}

int is_group_1(Cube *cube_state) // 0-false 1-true
{
    for (int i = 0; i < 12; i++)
    {
        if (cube_state->edges[0].orientation == 1)
        {
            return 0;
        }
    }
    return 1;
}

int is_group_2(Cube *cube_state)
{
    for (int i = 0; i < 8; i++)
    {
        if (cube_state->corners[0].orientation == 1)
        {
            return 0;
        }
    }
//0 8 10 2
    // edges in place
    if(!(cube_state->edges[0].index==0 || cube_state->edges[0].index==8 || cube_state->edges[0].index==10 || cube_state->edges[0].index==2))
    {
        return 0;
    }

    if(!(cube_state->edges[8].index==0 || cube_state->edges[8].index==8 || cube_state->edges[8].index==10 || cube_state->edges[8].index==2))
    {
        return 0;
    }

    if(!(cube_state->edges[10].index==0 || cube_state->edges[10].index==8 || cube_state->edges[10].index==10 || cube_state->edges[10].index==2))
    {
        return 0;
    }

    if(!(cube_state->edges[2].index==0 || cube_state->edges[2].index==8 || cube_state->edges[2].index==10 || cube_state->edges[2].index==2))
    {
        return 0;
    }

    return 1;
}
//TODO-parity
int is_group_3(Cube *cube_state)
{
    //orbits UFR DFL UBL DRB 0 2 7 5
    //UFL DRF URB DLB 3 1 4 6
    if(!(cube_state->corners[0].index == 0 || cube_state->corners[0].index == 2 ||cube_state->corners[0].index == 7 ||cube_state->corners[0].index == 5))
    {
        return 0;
    }

    if(!(cube_state->corners[2].index == 0 || cube_state->corners[2].index == 2 ||cube_state->corners[2].index == 7 ||cube_state->corners[2].index == 5))
    {
        return 0;
    }

    if(!(cube_state->corners[7].index == 0 || cube_state->corners[7].index == 2 ||cube_state->corners[7].index == 7 ||cube_state->corners[7].index == 5))
    {
        return 0;
    }

    if(!(cube_state->corners[5].index == 0 || cube_state->corners[5].index == 2 ||cube_state->corners[5].index == 7 ||cube_state->corners[5].index == 5))
    {
        return 0;
    }
/*
    //UFL DRF URB DLB 3 1 4 6
    if(!(cube_state->corners[3].index == 3 || cube_state->corners[3].index == 1 ||cube_state->corners[3].index == 4 ||cube_state->corners[3].index == 6))
    {
        return 0;
    }

    if(!(cube_state->corners[1].index == 3 || cube_state->corners[1].index == 1 ||cube_state->corners[1].index == 4 ||cube_state->corners[1].index == 6))
    {
        return 0;
    }

    if(!(cube_state->corners[4].index == 3 || cube_state->corners[4].index == 1 ||cube_state->corners[4].index == 4 ||cube_state->corners[4].index == 6))
    {
        return 0;
    }

    if(!(cube_state->corners[6].index == 3 || cube_state->corners[6].index == 1 ||cube_state->corners[6].index == 4 ||cube_state->corners[6].index == 6))
    {
        return 0;
    }
*/
    //corner orbits

    //4 5
    if(!(cube_state->edges[4].index==4 || cube_state->edges[4].index==5 ||cube_state->edges[5].index==5 ||cube_state->edges[5].index==4))
    {
        return 0;
    }
    //1 9
    if(!(cube_state->edges[1].index==1 || cube_state->edges[1].index==9 ||cube_state->edges[9].index==1 ||cube_state->edges[9].index==9))
    {
        return 0;
    }
    //7 6
    if(!(cube_state->edges[7].index==7 || cube_state->edges[7].index==6 ||cube_state->edges[6].index==6 ||cube_state->edges[6].index==7))
    {
        return 0;
    }
    //3 11
    if(!(cube_state->edges[3].index==3 || cube_state->edges[3].index==11 ||cube_state->edges[11].index==9 ||cube_state->edges[11].index==11))
    {
        return 0;
    }

    return 1;
}

int is_solved(Cube *cube_state)
{
    for(int i=0;i<12;i++)
    {
        if(!((cube_state->edges[i].index==i) && (cube_state->edges[i].orientation=0)))
        {
            return 0;
        }
    }

    for(int i=0;i<8;i++)
    {
        if(!((cube_state->corners[i].index==i) && (cube_state->corners[i].orientation=0)))
        {
            return 0;
        }
    }

    return 1;
}