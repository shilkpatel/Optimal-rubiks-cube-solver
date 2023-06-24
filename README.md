# Optimal-rubiks-cube-solver
A program which will compute the most optimal solution on how to solve a rubik's cube in an efficient manner.

I will initially implement Thistlethwaite's algorithm which splits the job of solving a rubik's cube into 5 groups, each of which require a relatively small amount of exploration compared to if we were to do a breadth first search.

The groups are as followed:
G 0 = ⟨ L , L' , L2 , R , R' , R2 , F , F' , F2 , B , B' , B2 , U , U' , U2 , D , D' , D2⟩ max 18 branch factor
G 1 = ⟨ L , L' , L2 , R , R' , R2 , F2 , B2 , U , U' , U2 , D , D' , D2 ⟩ max 14 branch factor
G 2 = ⟨ L2 , R2 , F2 , B2 , U , U' , U2 , D , D' , D2 ⟩ max 10 branch factor
G 3 = ⟨ L2 , R2 , F2 , B2 , U2 , D2 ⟩ max 6 branch factor
G 4 = { 1 }

Group 1 is when all the "bad edges" are gone, this means all the edges are oriented and can be brought to their proper position without doing the move F or F'/ B or B'.

