from Cube import *
from collections import deque


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
    
    inverse_move_table={Cube.R:Cube.R_prime,
                        Cube.R_prime:Cube.R,
                        Cube.R2:Cube.R2,

                        Cube.L:Cube.L_prime,
                        Cube.L_prime:Cube.L,
                        Cube.L2:Cube.L2,

                        Cube.F:Cube.F_prime,
                        Cube.F_prime:Cube.F,
                        Cube.F2:Cube.F2,

                        Cube.B:Cube.B_prime,
                        Cube.B_prime:Cube.B,
                        Cube.B2:Cube.B2,

                        Cube.U:Cube.U_prime,
                        Cube.U_prime:Cube.U,
                        Cube.U2:Cube.U2,

                        Cube.D:Cube.D_prime,
                        Cube.D_prime:Cube.D,
                        Cube.D2:Cube.D2
                        }

    inverted_equivalences={Cube.R:Cube.L,
                        Cube.R_prime:Cube.L_prime,
                        Cube.R2:Cube.L2,

                        Cube.L:Cube.R,
                        Cube.L_prime:Cube.R_prime,
                        Cube.L2:Cube.R2,

                        Cube.F:Cube.B,
                        Cube.F_prime:Cube.B_prime,
                        Cube.F2:Cube.B2,

                        Cube.B:Cube.F,
                        Cube.B_prime:Cube.F_prime,
                        Cube.B2:Cube.F2,

                        Cube.U:Cube.D,
                        Cube.U_prime:Cube.D_prime,
                        Cube.U2:Cube.D2,

                        Cube.D:Cube.U,
                        Cube.D_prime:Cube.U_prime,
                        Cube.D2:Cube.U2
                        }

    prune_table = set()

    pruned = 0

    test_set = set()

    expected_test_set_size=0

    inverted_moves_table = {Cube.R:0,Cube.R_prime:0,Cube.R2:0,
                            Cube.L:1,Cube.L_prime:1,Cube.L2:1,
                            Cube.F:2,Cube.F_prime:2,Cube.F2:2,
                            Cube.B:3,Cube.B_prime:3,Cube.B2:3,
                            Cube.U:4,Cube.U_prime:4,Cube.U2:4,
                            Cube.D:5,Cube.D_prime:5,Cube.D2:5,}
    
    def __init__(self,cubeState,lastMove = 6, current_move = Cube.null_move):
        
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

        self.current_move = current_move

    def generate_children_v0(self):
        for i in CubeTree.moves:
            self.children.append(CubeTree(i(self.current_state),6))#doesn't cut down on number of moves
   
    def generate_children_v1(self):
        # do not turn the face which was used to enter this state
        valid_moves = CubeTree.reduced_moves_table[self.move]

        for i in range(len(valid_moves)):
            self.children.append(CubeTree(valid_moves[i](self.current_state),
                                          CubeTree.inverted_moves_table[valid_moves[i]]))
            
    def generate_children_v2(self):
        # do not turn the face which was used to enter this state
        valid_moves = CubeTree.reduced_moves_table[self.move]

        for i in range(len(valid_moves)):
            child_state = valid_moves[i](self.current_state)

            child_key = child_state.serialize()

            if child_key in CubeTree.prune_table:# if child is in prune table then we want to not add it to the children
                
                CubeTree.pruned+=1
                continue
            else:
                CubeTree.prune_table.add(child_key)
            
                self.children.append(CubeTree(child_state,
                                          CubeTree.inverted_moves_table[valid_moves[i]]))
        
    def dfs_v0(root,depth_limit):
        total_children = 0
        if depth_limit==0:
            return 1
        else:
            
        
            for i in root.moves:
                i(root.current_state)#do current move
                total_children+= CubeTree.dfs_v0(root,depth_limit-1) #+1# for total nodes visited rather than total children
                CubeTree.inverse_move_table[i](root.current_state)#undo moves
                

        return total_children
    
    def dfs_v1(root,depth_limit):
        total_children = 0

        if depth_limit==0:
            return 1
        else:
            valid_moves = CubeTree.reduced_moves_table[root.move]
        
            for i in valid_moves:
                i(root.current_state)#do current move

                last_move = CubeTree.inverted_moves_table[i]
                total_children+= CubeTree.dfs_v1(CubeTree(root.current_state,last_move),depth_limit-1) #+1# for total nodes visited rather than total children
                CubeTree.inverse_move_table[i](root.current_state)#undo moves
                

        return total_children
    
    def dfs_v2(root,depth_limit):
        total_children = 0

        if depth_limit==0:
            return 1
        else:
            if len(root.children)!=0:
                for i in root.children:
                    current_function = i.current_move

                    current_function(root.current_state)
                    CubeTree.dfs_v2(i,depth_limit-1)

                    CubeTree.inverse_move_table[i.current_move](root.current_state)

                # navigate
            else:
                #create
                
                valid_moves = CubeTree.reduced_moves_table[root.move]
        
                for i in valid_moves:
                    i(root.current_state)#do current move
                    serial_state =root.current_state.serialize()

                    if not(serial_state in CubeTree.prune_table):
                        
                        CubeTree.prune_table.add(serial_state)

                        last_move = CubeTree.inverted_moves_table[i]#pass in last move for reduced set for children

                        new_child = CubeTree(root.current_state,last_move,i)

                        root.children.append(new_child)

                        total_children+= CubeTree.dfs_v2(new_child,depth_limit-1) #+1# for total nodes visited rather than total children

                    else:
                       
                        CubeTree.pruned+=1
                       

                    CubeTree.inverse_move_table[i](root.current_state)#undo moves
                

        return total_children
    
    def iddfs_v2(root,depth_limit):
        result = 0
        for i in range(1,depth_limit+1):
            print(i)
            print(CubeTree.dfs_v2(root,i))

            

        return result

    def solve_v1(root,num_moves):####
        total_children = 0
        if Cube.is_solved(root.current_state):
            print(num_moves)
        
        valid_moves = CubeTree.reduced_moves_table[root.move]
        for i in valid_moves:

            i(root.current_state)#do current move
            serial_state =root.current_state.serialize()

            if not(serial_state in CubeTree.prune_table):
                        
                CubeTree.prune_table.add(serial_state)

                last_move = CubeTree.inverted_moves_table[i]#pass in last move for reduced set for children

                new_child = CubeTree(root.current_state,last_move,i)

                root.children.append(new_child)
            else:
                CubeTree.pruned+=1

                
            
            CubeTree.inverse_move_table[i](root.current_state)#undo moves
        
        for i in root.children:
            i.current_move(root.current_state)
            #total_children+= CubeTree.bfs_v2(i,num_moves+1)
            CubeTree.inverse_move_table[i.current_move](root.current_state)
        
        return total_children
    
    def corner_dfs(root,depth_limit):
        corner_solved = False
        if depth_limit==0:
            return Cube.is_corners_solved(root.current_state)
        else:
                #create
                
                valid_moves = CubeTree.reduced_moves_table[root.move]
        
                for i in valid_moves:
                    i(root.current_state)#do current move  

                    last_move = CubeTree.inverted_moves_table[i]#pass in last move for reduced set for children

                    new_child = CubeTree(root.current_state,last_move,i)

                    root.children.append(new_child)

                    corner_solved = corner_solved or CubeTree.corner_dfs(new_child,depth_limit-1) #+1# for total nodes visited rather than total children

                    CubeTree.inverse_move_table[i](root.current_state)#undo moves
                

        return corner_solved

        
        
            

        
        