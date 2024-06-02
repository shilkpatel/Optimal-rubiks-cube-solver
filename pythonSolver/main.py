from CubeTree import *
from Cube import *
import time

def depth_benchmark(root,depth_limit):
    total_children = 0
    if depth_limit==0:
        return 1
    else:
        root.generate_children_v1()
        
        for i in root.children:
            total_children+= depth_benchmark(i,depth_limit-1) +1# for total nodes visited rather than total children

    return total_children
        

start = time.perf_counter_ns()
result =depth_benchmark(CubeTree(Cube.create_solved_cube()),5)
end = time.perf_counter_ns()

print(end-start)

print(result)



    

