#include <stdio.h>
#include <stdlib.h>

import copy
class cubie():
    def __init__(self,index,orientation):
        self.index  =index #0-11 for edges,0-7 for corners
        self.orientation=orientation #0-1 for edges,0-2 for corners

    def serialize(self):
        return str(self.index)+"," +str(self.orientation)

    def update_corner_orientation(self,rotation):

        self.orientation += rotation
        self.orientation %= 3

    def update_edge_orientation(self,rotation):
        self.orientation += rotation
        self.orientation %= 2


#the cube will be oriented such that white is up and green is front
class Cube():

    def __init__(self):
        self.edges=[]
        #0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL
        self.corners=[]
        #0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL

    def serialize(self):
        return ",".join(x.serialize() for x in self.edges)+ "," + ",".join(x.serialize() for x in self.corners)

    def print_cube(self):
        #🟨🟥🟧🟦🟩⬜
        cube_corner_colours = {0:["⬜","🟥","🟩"],
                               1:["🟨","🟩","🟥"],
                               2:["🟨","🟧","🟩"],
                               3:["⬜","🟩","🟧"],
                               4:["⬜","🟦","🟥"],
                               5:["🟨","🟥","🟦"],
                               6:["🟨","🟦","🟧"],
                               7:["⬜","🟧","🟦"]}
        
        cube_edge_colours = {0:["⬜","🟩"],
                             1:["🟩","🟥"],
                             2:["🟨","🟩"],
                             3:["🟩","🟧"],
                             4:["⬜","🟥"],
                             5:["🟨","🟥"],
                             6:["🟨","🟧"],
                             7:["⬜","🟧"],
                             8:["⬜","🟦"],
                             9:["🟦","🟥"],
                             10:["🟨","🟦"],
                             11:["🟦","🟧"]}
        

        cubestring = [[["","",""],
                      ["","⬜",""],
                      ["","",""]],

                      [["","",""],
                      ["","🟩",""],
                      ["","",""]],

                      [["","",""],
                      ["","🟧",""],
                      ["","",""]],

                      [["","",""],
                      ["","🟥",""],
                      ["","",""]],

                      [["","",""],
                      ["","🟨",""],
                      ["","",""]],

                      [["","",""],
                      ["","🟦",""],
                      ["","",""]]]
        
        orientation = self.corners[0].orientation
        cubestring[0][2][2]=cube_corner_colours[self.corners[0].index][(0+orientation)%3]#w #0
        cubestring[3][0][0]=cube_corner_colours[self.corners[0].index][(1+orientation)%3]#r #1
        cubestring[1][0][2]=cube_corner_colours[self.corners[0].index][(2+orientation)%3]#g #2
#########################
        orientation = self.corners[1].orientation
        cubestring[4][0][2]=cube_corner_colours[self.corners[1].index][(0+orientation)%3] #0
        cubestring[1][2][2]=cube_corner_colours[self.corners[1].index][(1+orientation)%3] #1
        cubestring[3][2][0]=cube_corner_colours[self.corners[1].index][(2+orientation)%3] #2
        
        orientation = self.corners[2].orientation
        cubestring[4][0][0]=cube_corner_colours[self.corners[2].index][(0+orientation)%3]#0
        cubestring[2][2][2]=cube_corner_colours[self.corners[2].index][(1+orientation)%3]#1
        cubestring[1][2][0]=cube_corner_colours[self.corners[2].index][(2+orientation)%3]#2
        
        orientation = self.corners[3].orientation
        cubestring[0][2][0]=cube_corner_colours[self.corners[3].index][(0+orientation)%3]#0
        cubestring[1][0][0]=cube_corner_colours[self.corners[3].index][(1+orientation)%3]#1
        cubestring[2][0][2]=cube_corner_colours[self.corners[3].index][(2+orientation)%3]#2
        
        orientation = self.corners[4].orientation
        cubestring[0][0][2]=cube_corner_colours[self.corners[4].index][(0+orientation)%3]#0
        cubestring[5][2][2]=cube_corner_colours[self.corners[4].index][(1+orientation)%3]#1
        cubestring[3][0][2]=cube_corner_colours[self.corners[4].index][(2+orientation)%3]#2
        
        
        orientation = self.corners[5].orientation
        cubestring[4][2][2]=cube_corner_colours[self.corners[5].index][(0+orientation)%3]#0
        cubestring[3][2][2]=cube_corner_colours[self.corners[5].index][(1+orientation)%3]#1
        cubestring[5][0][2]=cube_corner_colours[self.corners[5].index][(2+orientation)%3]#2
        
        # 0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL
        
        orientation = self.corners[6].orientation
        cubestring[4][2][0]=cube_corner_colours[self.corners[6].index][(0+orientation)%3]#0
        cubestring[5][0][0]=cube_corner_colours[self.corners[6].index][(1+orientation)%3]#1
        cubestring[2][2][0]=cube_corner_colours[self.corners[6].index][(2+orientation)%3]#2
        
        orientation = self.corners[7].orientation
        cubestring[0][0][0]=cube_corner_colours[self.corners[7].index][(0+orientation)%3]#0
        cubestring[2][0][0]=cube_corner_colours[self.corners[7].index][(1+orientation)%3]#1
        cubestring[5][2][0]=cube_corner_colours[self.corners[7].index][(2+orientation)%3]#2

        #0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL

        orientation = self.edges[0].orientation
        cubestring[0][2][1] = cube_edge_colours[self.edges[0].index][(0+orientation)%2]#0
        cubestring[1][0][1] = cube_edge_colours[self.edges[0].index][(1+orientation)%2]#1

        orientation = self.edges[1].orientation
        cubestring[1][1][2] = cube_edge_colours[self.edges[1].index][(0+orientation)%2]#0
        cubestring[3][1][0] = cube_edge_colours[self.edges[1].index][(1+orientation)%2]#1

        orientation = self.edges[2].orientation
        cubestring[4][0][1] = cube_edge_colours[self.edges[2].index][(0+orientation)%2]#0
        cubestring[1][2][1] = cube_edge_colours[self.edges[2].index][(1+orientation)%2]#1

        orientation = self.edges[3].orientation
        cubestring[1][1][0] = cube_edge_colours[self.edges[3].index][(0+orientation)%2]#0
        cubestring[2][1][2] = cube_edge_colours[self.edges[3].index][(1+orientation)%2]#1

        orientation = self.edges[4].orientation
        cubestring[0][1][2] = cube_edge_colours[self.edges[4].index][(0+orientation)%2]#0
        cubestring[3][0][1] = cube_edge_colours[self.edges[4].index][(1+orientation)%2]#1

        orientation = self.edges[5].orientation
        cubestring[4][1][2] = cube_edge_colours[self.edges[5].index][(0+orientation)%2]#0
        cubestring[3][2][1] = cube_edge_colours[self.edges[5].index][(1+orientation)%2]#1

        #0-FU,1-FR,2-FD,3-FL,4-UR,5-DR,6-DL,7-UL,8-BU,9-BR,10-BD,11-BL

        orientation = self.edges[6].orientation
        cubestring[4][1][0] = cube_edge_colours[self.edges[6].index][(0+orientation)%2]#0
        cubestring[2][2][1] = cube_edge_colours[self.edges[6].index][(1+orientation)%2]#1

        orientation = self.edges[7].orientation
        cubestring[0][1][0] = cube_edge_colours[self.edges[7].index][(0+orientation)%2]#0
        cubestring[2][0][1] = cube_edge_colours[self.edges[7].index][(1+orientation)%2]#1

        orientation = self.edges[8].orientation
        cubestring[0][0][1] = cube_edge_colours[self.edges[8].index][(0+orientation)%2]#0
        cubestring[5][2][1] = cube_edge_colours[self.edges[8].index][(1+orientation)%2]#1

        orientation = self.edges[9].orientation
        cubestring[5][1][2] = cube_edge_colours[self.edges[9].index][(0+orientation)%2]#0
        cubestring[3][1][2] = cube_edge_colours[self.edges[9].index][(1+orientation)%2]#1

        orientation = self.edges[10].orientation
        cubestring[4][2][1] = cube_edge_colours[self.edges[10].index][(0+orientation)%2]#0
        cubestring[5][0][1] = cube_edge_colours[self.edges[10].index][(1+orientation)%2]#1

        orientation = self.edges[11].orientation
        cubestring[5][1][0] = cube_edge_colours[self.edges[11].index][(0+orientation)%2]#0
        cubestring[2][1][0] = cube_edge_colours[self.edges[11].index][(1+orientation)%2]#1

        for i in cubestring[0]:
            print("                  "+str(i))

        #print(cubestring[2]+cubestring[1]+cubestring[3])
        for i in range(3):
            print(cubestring[2][i]+cubestring[1][i]+cubestring[3][i])

      
        for i in cubestring[4]:
            print("                  "+str(i))

      
        for i in cubestring[5]:
            print("                  "+str(i))

        #w1 - c7 e8 c4
        #w2 - e7 w  e4
        #w3 - c3 e0 c0

        #g1 - c3 e0 c0
        #g2 - e3 g  e1
        #g3 - c2 e2 c1

        #o1 - c7 e7 c3
        #o2 - e11 o e3
        #o3 - c6 e6 c2

        #r1 - c0 e4 c4
        #r2 - e1 r  e9
        #r3 - c1 e5 c5

        #y1 - c2 e2 c1
        #y2 - e6 y  e5
        #y3 - c6 e10 c5

        #b1 - c6 e2 c1
        #b2 - e11 b e9
        #b3 - c7 e8 c4

    def create_solved_cube():
    
        new_cube = Cube()
        for i in range(12):
            new_cubie = cubie(i,0)

            new_cube.edges.append(new_cubie)
        

        for i in range(8):
            new_cubie = cubie(i,0)
            new_cube.corners.append(new_cubie)

        return new_cube

    def R(state):

        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)
        ## shifting corners
        # 0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL

        ## possible memory leak as memory is allocated but not deallocated
        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[1]
        new_cube.corners[1] = new_cube.corners[5]
        new_cube.corners[5] = new_cube.corners[4]
        new_cube.corners[4] = temp 
        ## I believe this is the solution

        new_cube.corners[0].update_corner_orientation(1)
        new_cube.corners[1].update_corner_orientation(2)
        new_cube.corners[5].update_corner_orientation(1)
        new_cube.corners[4].update_corner_orientation(2)

        temp = cubie(-1,-1)

        temp = new_cube.edges[1]
        new_cube.edges[1] = new_cube.edges[5]
        new_cube.edges[5] = new_cube.edges[9]
        new_cube.edges[9] = new_cube.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def R_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)
        ## shifting corners

        ## possible memory leak as memory is allocated but not deallocated
        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[5]
        new_cube.corners[5] = new_cube.corners[1]
        new_cube.corners[1] = temp

        new_cube.corners[0].update_corner_orientation(1)
        new_cube.corners[1].update_corner_orientation(2)
        new_cube.corners[5].update_corner_orientation(1)
        new_cube.corners[4].update_corner_orientation(2)

        temp = new_cube.edges[1]
        new_cube.edges[1] = new_cube.edges[4]
        new_cube.edges[4] = new_cube.edges[9]
        new_cube.edges[9] = new_cube.edges[5]
        new_cube.edges[5] = temp

        return new_cube

    def R2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[5]
        new_cube.corners[5] = temp
        # 4,5
        temp = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[1]
        new_cube.corners[1] = temp

        temp = new_cube.edges[1]
        new_cube.edges[1] = new_cube.edges[9]
        new_cube.edges[9] = temp

        temp = new_cube.edges[4]
        new_cube.edges[4] = new_cube.edges[5]
        new_cube.edges[5] = temp

        return new_cube
    
    def L(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[7]
        new_cube.corners[7] = new_cube.corners[6]
        new_cube.corners[6] = new_cube.corners[2]
        new_cube.corners[2] = temp

        new_cube.corners[3].update_corner_orientation(2)
        new_cube.corners[7].update_corner_orientation(1)
        new_cube.corners[6].update_corner_orientation(2)
        new_cube.corners[2].update_corner_orientation(1)

        temp = new_cube.edges[3]
        new_cube.edges[3] = new_cube.edges[7]
        new_cube.edges[7] = new_cube.edges[11]
        new_cube.edges[11] = new_cube.edges[6]
        new_cube.edges[6] = temp

        return new_cube
    
    def L_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)
        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[6]
        new_cube.corners[6] = new_cube.corners[7]
        new_cube.corners[7] = temp

        new_cube.corners[3].update_corner_orientation(2)
        new_cube.corners[7].update_corner_orientation(1)
        new_cube.corners[6].update_corner_orientation(2)
        new_cube.corners[2].update_corner_orientation(1)

        temp = new_cube.edges[3]
        new_cube.edges[3] = new_cube.edges[6]
        new_cube.edges[6] = new_cube.edges[11]
        new_cube.edges[11] = new_cube.edges[7]
        new_cube.edges[7] = temp

        return new_cube

    def L2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[6] # 36 27
        new_cube.corners[6] = temp

        temp = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[7]
        new_cube.corners[7] = temp

        temp = new_cube.edges[3]
        new_cube.edges[3] = new_cube.edges[11] # 311 67
        new_cube.edges[11] = temp

        temp = new_cube.edges[6]
        new_cube.edges[6] = new_cube.edges[7]
        new_cube.edges[7] = temp

        return new_cube
    
    def F(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[1]
        new_cube.corners[1] = new_cube.corners[0]
        new_cube.corners[0] = temp

        new_cube.corners[3].update_corner_orientation(1)
        new_cube.corners[2].update_corner_orientation(2)
        new_cube.corners[1].update_corner_orientation(1)
        new_cube.corners[0].update_corner_orientation(2)

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[3]
        new_cube.edges[3] = new_cube.edges[2]
        new_cube.edges[2] = new_cube.edges[1]
        new_cube.edges[1] = temp

        new_cube.edges[0].update_edge_orientation(1)
        new_cube.edges[3].update_edge_orientation(1)
        new_cube.edges[2].update_edge_orientation(1)
        new_cube.edges[1].update_edge_orientation(1)

        return new_cube

    def F_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners
        temp = cubie(-1,-1)

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[1]
        new_cube.corners[1] = new_cube.corners[2]
        new_cube.corners[2] = temp

        new_cube.corners[3].update_corner_orientation(1)
        new_cube.corners[2].update_corner_orientation(2)
        new_cube.corners[1].update_corner_orientation(1)
        new_cube.corners[0].update_corner_orientation(2)

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[1]
        new_cube.edges[1] = new_cube.edges[2]
        new_cube.edges[2] = new_cube.edges[3]
        new_cube.edges[3] = temp
        
        new_cube.edges[0].update_edge_orientation(1)
        new_cube.edges[3].update_edge_orientation(1)
        new_cube.edges[2].update_edge_orientation(1)
        new_cube.edges[1].update_edge_orientation(1)

        return new_cube

    def F2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[1] # 31 02
        new_cube.corners[1] = temp

        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[2]
        new_cube.corners[2] = temp

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[2] # 02 13
        new_cube.edges[2] = temp

        temp = new_cube.edges[1]
        new_cube.edges[1] = new_cube.edges[3]
        new_cube.edges[3] = temp

        return new_cube
        
    def B(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[5]
        new_cube.corners[5] = new_cube.corners[6]
        new_cube.corners[6] = new_cube.corners[7]
        new_cube.corners[7] = temp

        new_cube.corners[4].update_corner_orientation(1)
        new_cube.corners[5].update_corner_orientation(2)
        new_cube.corners[6].update_corner_orientation(1)
        new_cube.corners[7].update_corner_orientation(2)

        temp = new_cube.edges[8]
        new_cube.edges[8] = new_cube.edges[9]
        new_cube.edges[9] = new_cube.edges[10]
        new_cube.edges[10] = new_cube.edges[11]
        new_cube.edges[11] = temp
        

        new_cube.edges[8].update_edge_orientation(1)
        new_cube.edges[9].update_edge_orientation(1)
        new_cube.edges[10].update_edge_orientation(1)
        new_cube.edges[11].update_edge_orientation(1)

        return new_cube

    def B_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners
        temp = cubie(-1,-1)

        temp = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[7]
        new_cube.corners[7] = new_cube.corners[6]
        new_cube.corners[6] = new_cube.corners[5]
        new_cube.corners[5] = temp

        new_cube.corners[4].update_corner_orientation(1)
        new_cube.corners[5].update_corner_orientation(2)
        new_cube.corners[6].update_corner_orientation(1)
        new_cube.corners[7].update_corner_orientation(2)

        temp = new_cube.edges[8]
        new_cube.edges[8] = new_cube.edges[11]
        new_cube.edges[11] = new_cube.edges[10]
        new_cube.edges[10] = new_cube.edges[9]
        new_cube.edges[9] = temp
        

        new_cube.edges[8].update_edge_orientation(1)
        new_cube.edges[9].update_edge_orientation(1)
        new_cube.edges[10].update_edge_orientation(1)
        new_cube.edges[11].update_edge_orientation(1)

        return new_cube

    def B2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners
        temp = cubie(-1,-1)

        temp = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[6] # 46 75
        new_cube.corners[6] = temp

        temp = new_cube.corners[7]
        new_cube.corners[7] = new_cube.corners[5]
        new_cube.corners[5] = temp

        temp = new_cube.edges[8]
        new_cube.edges[8] = new_cube.edges[10] # 810 119
        new_cube.edges[10] = temp

        temp = new_cube.edges[11]
        new_cube.edges[11] = new_cube.edges[9]
        new_cube.edges[9] = temp

        return new_cube
        
    def U(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[4]
        new_cube.corners[4] = new_cube.corners[7]
        new_cube.corners[7] = new_cube.corners[3]
        new_cube.corners[3] = temp

        # corner orientation has not changed

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[4]
        new_cube.edges[4] = new_cube.edges[8]
        new_cube.edges[8] = new_cube.edges[7]
        new_cube.edges[7] = temp

        return new_cube
    
        # edges are still orientated

    def U_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[7]
        new_cube.corners[7] = new_cube.corners[4]
        new_cube.corners[4] = temp

        # corner orientation has not changed

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[7]
        new_cube.edges[7] = new_cube.edges[8]
        new_cube.edges[8] = new_cube.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def U2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[0]
        new_cube.corners[0] = new_cube.corners[7]# 07 34
        new_cube.corners[7] = temp

        temp = new_cube.corners[3]
        new_cube.corners[3] = new_cube.corners[4]
        new_cube.corners[4] = temp

        # corner orientation has not changed

        temp = new_cube.edges[0]
        new_cube.edges[0] = new_cube.edges[8] # 08 74
        new_cube.edges[8] = temp

        temp = new_cube.edges[7]
        new_cube.edges[7] = new_cube.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def D(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[6]
        new_cube.corners[6] = new_cube.corners[5]
        new_cube.corners[5] = new_cube.corners[1]
        new_cube.corners[1] = temp

        # corners not changed

        temp = new_cube.edges[2]
        new_cube.edges[2] = new_cube.edges[6]
        new_cube.edges[6] = new_cube.edges[10]
        new_cube.edges[10] = new_cube.edges[5]
        new_cube.edges[5] = temp

        return new_cube
        
    def D_prime(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[1]
        new_cube.corners[1] = new_cube.corners[5]
        new_cube.corners[5] = new_cube.corners[6]
        new_cube.corners[6] = temp

        # corners not changed

        temp = new_cube.edges[2]
        new_cube.edges[2] = new_cube.edges[5]
        new_cube.edges[5] = new_cube.edges[10]
        new_cube.edges[10] = new_cube.edges[6]
        new_cube.edges[6] = temp

        return new_cube
        
    def D2(state):
        new_cube = state
        new_cube.edges = new_cube.edges = state.edges
        new_cube.corners = new_cube.corners = state.corners

        temp = cubie(-1,-1)

        temp = new_cube.corners[2]
        new_cube.corners[2] = new_cube.corners[5] # 25 16
        new_cube.corners[5] = temp

        temp = new_cube.corners[1]
        new_cube.corners[1] = new_cube.corners[6]
        new_cube.corners[6] = temp

        # corners not changed

        temp = new_cube.edges[2]
        new_cube.edges[2] = new_cube.edges[10] # 210 56
        new_cube.edges[10] = temp

        temp = new_cube.edges[5]
        new_cube.edges[5] = new_cube.edges[6]
        new_cube.edges[6] = temp

        return new_cube

    def is_equal(state1,state2):
        return state1.serialize()==state2.serialize()

    def null_move(state):
        return state
    

    def is_solved(state):

        for i in range(12):
    
            if not (state.edges[i].index==i and state.edges[i].orientation==0):
        
                return False
        
    

        for i in range(8):
    
            if(not((state.corners[i].index==i) and (state.corners[i].orientation==0))):
        
                return False
        
        return True
    
    def is_corners_solved(state):
        for i in range(8):
    
            if(not((state.corners[i].index==i) and (state.corners[i].orientation==0))):
        
                return False
        
        return True

    def is_edges_solved(state):
        for i in range(12):
    
            if not (state.edges[i].index==i and state.edges[i].orientation==0):
        
                return False
        
        return True