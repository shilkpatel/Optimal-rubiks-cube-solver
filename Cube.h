#ifndef CUBE_HEADER
#define CUBE_HEADER

typedef struct
{
    int index;//0-11 for edges,0-7 for corners
    int orientation;//0-1 for edges,0-2 for corners
}cubie;

void update_corner_orientation(cubie* corner,int rotation);

void update_edge_orientation(cubie* edge,int rotation);

typedef struct
{
    cubie edges[12];
    //0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL
    cubie corners[8];
    //0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL
}Cube;

Cube* create_solved_cube();

void R(Cube* cube_state);

void R_prime(Cube* cube_state);

void R2(Cube* cube_state);

void L(Cube* cube_state);

void L_prime(Cube* cube_state);

void L2(Cube* cube_state);

void F(Cube* cube_state);

void F_prime(Cube* cube_state);

void F2(Cube* cube_state);

void B(Cube* cube_state);

void B_prime(Cube* cube_state);

void B2(Cube* cube_state);

void U(Cube* cube_state);

void U_prime(Cube* cube_state);

void U2(Cube* cube_state);

void D(Cube* cube_state);

void D_prime(Cube* cube_state);

void D2(Cube* cube_state);
#endif