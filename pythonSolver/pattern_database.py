from Cube import *
from CubeTree import *
import random

def create_corner_database():
    cube = Cube.create_solved_cube()
    corners = [i for i in range(8)]
    counter = 0
    corner_orientations=[]
    corner_permutation = []
    for a in corners:
        corners.remove(a)
        for b in corners:
            corners.remove(b)
            for c in corners:
                corners.remove(c)
                for d in corners:
                    corners.remove(d)
                    for e in corners:
                        corners.remove(e)
                        for f in corners:
                            corners.remove(f)
                            for g in corners:
                                corners.remove(g)
                                for h in corners:
                                    corners.remove(h)
                                    corner_permutation.append([a,b,c,d,e,f,g,h])
                                    corners.append(h)
                                corners.append(g)
                            corners.append(f)
                        corners.append(e)
                    corners.append(d)
                corners.append(c)
            corners.append(b)
        corners.append(a)

    for a in [0,1,2]:
        for b in [0,1,2]:
            for c in [0,1,2]:
                for d in [0,1,2]:
                    for e in [0,1,2]:
                        for f in [0,1,2]:
                            for g in [0,1,2]:
                                c_orientation = [a,b,c,d,e,f,g]
                                orientation = (3 - (sum(c_orientation)%3))%3
                                c_orientation.append(orientation)
                                corner_orientations.append(c_orientation)
    
    
    for i in corner_permutation:
        for j in corner_orientations:
            print(i)
            print(j)

            for k in range(8):
                cube.corners[k]=cubie(i[k],j[k])

            root = CubeTree(cube)
            depth_limit = 0
            while True:
                print("Current Depth",depth_limit)
                result = CubeTree.corner_dfs(root,depth_limit)

                if result:
                    print("Depth for given position",depth_limit)
                    break
                else:
                    depth_limit+=1


create_corner_database()


            
