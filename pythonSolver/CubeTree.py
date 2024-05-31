from Cube import *



class CubeTree():
    def __init__(self,cubeState):

        self.current_state = cubeState

        self.children =  []

    def generate_all_children(self):

        self.children.append(CubeTree(self.current_state.R()))
        self.children.append(CubeTree(self.current_state.R_prime()))
        self.children.append(CubeTree(self.current_state.R2()))

        self.children.append(CubeTree(self.current_state.L()))
        self.children.append(CubeTree(self.current_state.L_prime()))
        self.children.append(CubeTree(self.current_state.L2()))

        self.children.append(CubeTree(self.current_state.F()))
        self.children.append(CubeTree(self.current_state.F_prime()))
        self.children.append(CubeTree(self.current_state.F2()))

        self.children.append(CubeTree(self.current_state.B()))
        self.children.append(CubeTree(self.current_state.B_prime()))
        self.children.append(CubeTree(self.current_state.B2()))

        self.children.append(CubeTree(self.current_state.U()))
        self.children.append(CubeTree(self.current_state.U_prime()))
        self.children.append(CubeTree(self.current_state.U2()))

        self.children.append(CubeTree(self.current_state.D()))
        self.children.append(CubeTree(self.current_state.D_prime()))
        self.children.append(CubeTree(self.current_state.D2()))



