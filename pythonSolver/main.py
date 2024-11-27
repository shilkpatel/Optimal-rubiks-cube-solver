from CubeTree import *
from Cube import *
import time
import sqlite3

def depth_benchmark(root,depth_limit):
    total_children = 0
    if depth_limit==0:
        return 1
    else:
        root.generate_children_v1()
        
        for i in root.children:
            total_children+= depth_benchmark(i,depth_limit-1) #+1# for total nodes visited rather than total children
    return total_children


                                

'''

start_state = CubeTree(Cube.create_solved_cube())


start = time.perf_counter()
result =CubeTree.corner_dfs(start_state,0)
end = time.perf_counter()

print(result)

'''



'''
conn = sqlite3.connect('heuristic.db')

conn.execute(CREATE TABLE corners 
    (hash TEXT PRIMARY KEY,
	distance INTEGER NOT NULL
);)


'''
testcube = Cube.create_solved_cube()
testcube.print_cube()






    

