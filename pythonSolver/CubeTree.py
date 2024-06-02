from Cube import *



class CubeTree():
    moves = [Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2]
    
    reduced_moves_table={0:[
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2],

             1:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2],
             
             2:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2],
             
             3:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2],
             
             4:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.D,Cube.D_prime,Cube.D2],
             
             5:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2],
             
             6:[Cube.R,Cube.R_prime,Cube.R2,
             Cube.L,Cube.L_prime,Cube.L2,
             Cube.F,Cube.F_prime,Cube.F2,
             Cube.B,Cube.B_prime,Cube.B2,
             Cube.U,Cube.U_prime,Cube.U2,
             Cube.D,Cube.D_prime,Cube.D2]}
    
    inverted_moves_table = {Cube.R:0,Cube.R_prime:0,Cube.R2:0,
                            Cube.L:1,Cube.L_prime:1,Cube.L2:1,
                            Cube.F:2,Cube.F_prime:2,Cube.F2:2,
                            Cube.B:3,Cube.B_prime:3,Cube.B2:3,
                            Cube.U:4,Cube.U_prime:4,Cube.U2:4,
                            Cube.D:5,Cube.D_prime:5,Cube.D2:5,}
    def __init__(self,cubeState,lastMove = 6):
        
        self.current_state = cubeState

        self.children =  []

        self.move =lastMove
        #R - 0
        #L - 1
        #F - 2
        #B - 3
        #U - 4
        #D - 5
        #null - 6

    def generate_all_children(self):
        for i in CubeTree.moves:
            self.children.append(CubeTree(i(self.current_state),6))#doesn't cut down on number of moves
        
    def generate_children_v1(self):
        # do not turn the face which was used to enter this state
        valid_moves = CubeTree.reduced_moves_table[self.move]

        for i in range(len(valid_moves)):
            self.children.append(CubeTree(valid_moves[i](self.current_state),
                                          CubeTree.inverted_moves_table[valid_moves[i]]))
        

