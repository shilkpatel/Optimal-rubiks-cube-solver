from CubeTree import *
from Cube import *

def depth_benchmark(root,depth_limit):
    total_children = 0
    if depth_limit==0:
        return 1
    else:
        root.generate_all_children()
        
        for i in root.children:
            total_children+= depth_benchmark(i,depth_limit-1)

    return total_children
        



origin = CubeTree(Cube.create_solved_cube())

print("number of children: ",depth_benchmark(origin,5))
    

