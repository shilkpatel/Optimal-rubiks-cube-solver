#include <stdio.h>
#include <stdlib.h>
class cubie():
    def __init__(self,index,orientation):
        self.index  =index #0-11 for edges,0-7 for corners
        self.orientation=orientation #0-1 for edges,0-2 for corners

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

    def R(self):

        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)
        ## shifting corners
        # 0-FUR,1-FDR,2-FDL,3-FUL,4-BUR,5-BDR,6-BDL,7-BUL

        ## possible memory leak as memory is allocated but not deallocated
        temp = self.corners[0]
        new_cube.corners[0] = self.corners[1]
        new_cube.corners[1] = self.corners[5]
        new_cube.corners[5] = self.corners[4]
        new_cube.corners[4] = temp 
        ## I believe this is the solution

        new_cube.corners[0].update_corner_orientation(1)
        new_cube.corners[1].update_corner_orientation(2)
        new_cube.corners[5].update_corner_orientation(1)
        new_cube.corners[4].update_corner_orientation(2)

        temp = cubie(-1,-1)

        temp = self.edges[1]
        new_cube.edges[1] = self.edges[5]
        new_cube.edges[5] = self.edges[9]
        new_cube.edges[9] = self.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def R_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)
        ## shifting corners

        ## possible memory leak as memory is allocated but not deallocated
        temp = self.corners[0]
        new_cube.corners[0] = self.corners[4]
        new_cube.corners[4] = self.corners[5]
        new_cube.corners[5] = self.corners[1]
        new_cube.corners[1] = temp

        new_cube.corners[0].update_corner_orientation(1)
        new_cube.corners[1].update_corner_orientation(2)
        new_cube.corners[5].update_corner_orientation(1)
        new_cube.corners[4].update_corner_orientation(2)

        temp = self.edges[1]
        new_cube.edges[1] = self.edges[4]
        new_cube.edges[4] = self.edges[9]
        new_cube.edges[9] = self.edges[5]
        new_cube.edges[5] = temp

        return new_cube

    def R2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[0]
        new_cube.corners[0] = self.corners[5]
        new_cube.corners[5] = temp
        # 4,5
        temp = self.corners[4]
        new_cube.corners[4] = self.corners[1]
        new_cube.corners[1] = temp

        temp = self.edges[1]
        new_cube.edges[1] = self.edges[9]
        new_cube.edges[9] = temp

        temp = self.edges[4]
        new_cube.edges[4] = self.edges[5]
        new_cube.edges[5] = temp

        return new_cube
    
    def L(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[3]
        new_cube.corners[3] = self.corners[7]
        new_cube.corners[7] = self.corners[6]
        new_cube.corners[6] = self.corners[2]
        new_cube.corners[2] = temp

        new_cube.corners[3].update_corner_orientation(2)
        new_cube.corners[7].update_corner_orientation(1)
        new_cube.corners[6].update_corner_orientation(2)
        new_cube.corners[2].update_corner_orientation(1)

        temp = self.edges[3]
        new_cube.edges[3] = self.edges[7]
        new_cube.edges[7] = self.edges[11]
        new_cube.edges[11] = self.edges[6]
        new_cube.edges[6] = temp

        return new_cube
    
    def L_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)
        temp = self.corners[3]
        new_cube.corners[3] = self.corners[2]
        new_cube.corners[2] = self.corners[6]
        new_cube.corners[6] = self.corners[7]
        new_cube.corners[7] = temp

        new_cube.corners[3].update_corner_orientation(2)
        new_cube.corners[7].update_corner_orientation(1)
        new_cube.corners[6].update_corner_orientation(2)
        new_cube.corners[2].update_corner_orientation(1)

        temp = self.edges[3]
        new_cube.edges[3] = self.edges[6]
        new_cube.edges[6] = self.edges[11]
        new_cube.edges[11] = self.edges[7]
        new_cube.edges[7] = temp

        return new_cube

    def L2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[3]
        new_cube.corners[3] = self.corners[6] # 36 27
        new_cube.corners[6] = temp

        temp = self.corners[2]
        new_cube.corners[2] = self.corners[7]
        new_cube.corners[7] = temp

        temp = self.edges[3]
        new_cube.edges[3] = self.edges[11] # 311 67
        new_cube.edges[11] = temp

        temp = self.edges[6]
        new_cube.edges[6] = self.edges[7]
        new_cube.edges[7] = temp

        return new_cube
    
    def F(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[3]
        new_cube.corners[3] = self.corners[2]
        new_cube.corners[2] = self.corners[1]
        new_cube.corners[1] = self.corners[0]
        new_cube.corners[0] = temp

        new_cube.corners[3].update_corner_orientation(1)
        new_cube.corners[2].update_corner_orientation(2)
        new_cube.corners[1].update_corner_orientation(1)
        new_cube.corners[0].update_corner_orientation(2)

        temp = self.edges[0]
        new_cube.edges[0] = self.edges[3]
        new_cube.edges[3] = self.edges[2]
        new_cube.edges[2] = self.edges[1]
        new_cube.edges[1] = temp

        new_cube.edges[0].update_edge_orientation(1)
        new_cube.edges[3].update_edge_orientation(1)
        new_cube.edges[2].update_edge_orientation(1)
        new_cube.edges[1].update_edge_orientation(1)

        return new_cube

    def F_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners
        temp = cubie(-1,-1)

        temp = self.corners[3]
        new_cube.corners[3] = self.corners[0]
        new_cube.corners[0] = self.corners[1]
        new_cube.corners[1] = self.corners[2]
        new_cube.corners[2] = temp

        new_cube.corners[3].update_corner_orientation(1)
        new_cube.corners[2].update_corner_orientation(2)
        new_cube.corners[1].update_corner_orientation(1)
        new_cube.corners[0].update_corner_orientation(2)

        temp = self.edges[0]
        new_cube.edges[0] = self.edges[1]
        new_cube.edges[1] = self.edges[2]
        new_cube.edges[2] = self.edges[3]
        new_cube.edges[3] = temp
        
        new_cube.edges[0].update_edge_orientation(1)
        new_cube.edges[3].update_edge_orientation(1)
        new_cube.edges[2].update_edge_orientation(1)
        new_cube.edges[1].update_edge_orientation(1)

        return new_cube

    def F2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[3]
        new_cube.corners[3] = self.corners[1] # 31 02
        new_cube.corners[1] = temp

        temp = self.corners[0]
        new_cube.corners[0] = self.corners[2]
        new_cube.corners[2] = temp

        temp = self.edges[0]
        new_cube.edges[0] = self.edges[2] # 02 13
        new_cube.edges[2] = temp

        temp = self.edges[1]
        new_cube.edges[1] = self.edges[3]
        new_cube.edges[3] = temp

        return new_cube
        
    def B(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[4]
        new_cube.corners[4] = self.corners[5]
        new_cube.corners[5] = self.corners[6]
        new_cube.corners[6] = self.corners[7]
        new_cube.corners[7] = temp

        new_cube.corners[4].update_corner_orientation(1)
        new_cube.corners[5].update_corner_orientation(2)
        new_cube.corners[6].update_corner_orientation(1)
        new_cube.corners[7].update_corner_orientation(2)

        temp = self.edges[8]
        new_cube.edges[8] = self.edges[9]
        new_cube.edges[9] = self.edges[10]
        new_cube.edges[10] = self.edges[11]
        new_cube.edges[11] = temp
        

        new_cube.edges[8].update_edge_orientation(1)
        new_cube.edges[9].update_edge_orientation(1)
        new_cube.edges[10].update_edge_orientation(1)
        new_cube.edges[11].update_edge_orientation(1)

        return new_cube

    def B_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners
        temp = cubie(-1,-1)

        temp = self.corners[4]
        new_cube.corners[4] = self.corners[7]
        new_cube.corners[7] = self.corners[6]
        new_cube.corners[6] = self.corners[5]
        new_cube.corners[5] = temp

        new_cube.corners[4].update_corner_orientation(1)
        new_cube.corners[5].update_corner_orientation(2)
        new_cube.corners[6].update_corner_orientation(1)
        new_cube.corners[7].update_corner_orientation(2)

        temp = self.edges[8]
        new_cube.edges[8] = self.edges[11]
        new_cube.edges[11] = self.edges[10]
        new_cube.edges[10] = self.edges[9]
        new_cube.edges[9] = temp
        

        new_cube.edges[8].update_edge_orientation(1)
        new_cube.edges[9].update_edge_orientation(1)
        new_cube.edges[10].update_edge_orientation(1)
        new_cube.edges[11].update_edge_orientation(1)

        return new_cube

    def B2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners
        temp = cubie(-1,-1)

        temp = self.corners[4]
        new_cube.corners[4] = self.corners[6] # 46 75
        new_cube.corners[6] = temp

        temp = self.corners[7]
        new_cube.corners[7] = self.corners[5]
        new_cube.corners[5] = temp

        temp = self.edges[8]
        new_cube.edges[8] = self.edges[10] # 810 119
        new_cube.edges[10] = temp

        temp = self.edges[11]
        new_cube.edges[11] = self.edges[9]
        new_cube.edges[9] = temp

        return new_cube
        
    def U(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[0]
        new_cube.corners[0] = self.corners[4]
        new_cube.corners[4] = self.corners[7]
        new_cube.corners[7] = self.corners[3]
        new_cube.corners[3] = temp

        # corner orientation has not changed

        temp = self.edges[0]
        new_cube.edges[0] = self.edges[4]
        new_cube.edges[4] = self.edges[8]
        new_cube.edges[8] = self.edges[7]
        new_cube.edges[7] = temp

        return new_cube
    
        # edges are still orientated

    def U_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[0]
        new_cube.corners[0] = self.corners[3]
        new_cube.corners[3] = self.corners[7]
        new_cube.corners[7] = self.corners[4]
        new_cube.corners[4] = temp

        # corner orientation has not changed

        temp = self.edges[0]
        new_cube.edges[0] = self.edges[7]
        new_cube.edges[7] = self.edges[8]
        new_cube.edges[8] = self.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def U2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[0]
        new_cube.corners[0] = self.corners[7]# 07 34
        new_cube.corners[7] = temp

        temp = self.corners[3]
        self.corners[3] = self.corners[4]
        self.corners[4] = temp

        # corner orientation has not changed

        temp = self.edges[0]
        self.edges[0] = self.edges[8] # 08 74
        self.edges[8] = temp

        temp = self.edges[7]
        new_cube.edges[7] = self.edges[4]
        new_cube.edges[4] = temp

        return new_cube
        
    def D(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[2]
        new_cube.corners[2] = self.corners[6]
        new_cube.corners[6] = self.corners[5]
        new_cube.corners[5] = self.corners[1]
        new_cube.corners[1] = temp

        # corners not changed

        temp = self.edges[2]
        new_cube.edges[2] = self.edges[6]
        new_cube.edges[6] = self.edges[10]
        new_cube.edges[10] = self.edges[5]
        new_cube.edges[5] = temp

        return new_cube
        
    def D_prime(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[2]
        new_cube.corners[2] = self.corners[1]
        new_cube.corners[1] = self.corners[5]
        new_cube.corners[5] = self.corners[6]
        new_cube.corners[6] = temp

        # corners not changed

        temp = self.edges[2]
        new_cube.edges[2] = self.edges[5]
        new_cube.edges[5] = self.edges[10]
        new_cube.edges[10] = self.edges[6]
        new_cube.edges[6] = temp

        return new_cube
        
    def D2(self):
        new_cube = Cube()
        new_cube.edges = self.edges
        new_cube.corners = self.corners

        temp = cubie(-1,-1)

        temp = self.corners[2]
        new_cube.corners[2] = self.corners[5] # 25 16
        new_cube.corners[5] = temp

        temp = self.corners[1]
        new_cube.corners[1] = self.corners[6]
        new_cube.corners[6] = temp

        # corners not changed

        temp = self.edges[2]
        new_cube.edges[2] = self.edges[10] # 210 56
        new_cube.edges[10] = temp

        temp = self.edges[5]
        new_cube.edges[5] = self.edges[6]
        new_cube.edges[6] = temp

        return new_cube

    def is_group_1(self): # 0-false 1-true

        for i in range(12):
        
            if (self.edges[0].orientation == 1):
            
                return 0
            
        
        return 1

    def is_group_2(self):

        for i in range(8):
            if (self.corners[0].orientation == 1):
                return 0
            
        
    #0 8 10 2
        # edges in place
        if(not(self.edges[0].index==0 or self.edges[0].index==8 or self.edges[0].index==10 or self.edges[0].index==2)):
        
            return 0
        

        if(not(self.edges[8].index==0 or self.edges[8].index==8 or self.edges[8].index==10 or self.edges[8].index==2)):
        
            return 0
        

        if(not(self.edges[10].index==0 or self.edges[10].index==8 or self.edges[10].index==10 or self.edges[10].index==2)):
        
            return 0
        

        if(not(self.edges[2].index==0 or self.edges[2].index==8 or self.edges[2].index==10 or self.edges[2].index==2)):
        
            return 0
        

        return 1
    ##TODO-parity
    def is_group_3(self):
        #orbits UFR DFL UBL DRB 0 2 7 5
        #UFL DRF URB DLB 3 1 4 6

        if not(self.corners[0].index == 0 or self.corners[0].index == 2 or self.corners[0].index == 7 or self.corners[0].index == 5):
        
            return 0
        

        if not(self.corners[2].index == 0 or self.corners[2].index == 2 or self.corners[2].index == 7 or self.corners[2].index == 5):
        
            return 0
        

        if not(self.corners[7].index == 0 or self.corners[7].index == 2 or self.corners[7].index == 7 or self.corners[7].index == 5):
            return 0
        

        if not(self.corners[5].index == 0 or self.corners[5].index == 2 or self.corners[5].index == 7 or self.corners[5].index == 5):
        
            return 0
        

        #UFL DRF URB DLB 3 1 4 6
        if not(self.corners[3].index == 3 or self.corners[3].index == 1 or self.corners[3].index == 4 or self.corners[3].index == 6):
        
            return 0
        

        if not(self.corners[1].index == 3 or self.corners[1].index == 1 or self.corners[1].index == 4 or self.corners[1].index == 6):
        
            return 0
        

        if not(self.corners[4].index == 3 or self.corners[4].index == 1 or self.corners[4].index == 4 or self.corners[4].index == 6):
        
            return 0
        

        if not(self.corners[6].index == 3 or self.corners[6].index == 1 or self.corners[6].index == 4 or self.corners[6].index == 6):
        
            return 0
        

        #corner orbits

        #4 5
        if not(self.edges[4].index==4 or self.edges[4].index==5 or self.edges[5].index==5 or self.edges[5].index==4):
        
            return 0
        
        #1 9
        if not(self.edges[1].index==1 or self.edges[1].index==9 or self.edges[9].index==1 or self.edges[9].index==9):
        
            return 0
        
        #7 6
        if not(self.edges[7].index==7 or self.edges[7].index==6 or self.edges[6].index==6 or self.edges[6].index==7):
        
            return 0
        
        #3 11
        if not(self.edges[3].index==3 or self.edges[3].index==11 or self.edges[11].index==9 or self.edges[11].index==11):
        
            return 0
        

        return 1

    def is_solved(self):

        for i in range(12):
    
            if not (self.edges[i].index==i and self.edges[i].orientation==0):
        
                return 0
        
    

        for i in range(8):
    
            if(not((self.corners[i].index==i) and (self.corners[i].orientation==0))):
        
                return 0
        
    

        return 1