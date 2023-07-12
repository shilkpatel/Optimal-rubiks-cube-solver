 This algorithm works by reducing the number of moves that can be done by turning an unsolved cube to a format which can be solved by using less and less moves. This is shown by the groups down below.

G 0 = ⟨ L , L' , L2 , R , R' , R2 , F , F' , F2 , B , B' , B2 , U , U' , U2 , D , D' , D2⟩ max 18 branch factor

G 1 = ⟨ L , L' , L2 , R , R' , R2 , F2 , B2 , U , U' , U2 , D , D' , D2 ⟩ max 14 branch factor

G 2 = ⟨ L2 , R2 , F2 , B2 , U , U' , U2 , D , D' , D2 ⟩ max 10 branch factor

G 3 = ⟨ L2 , R2 , F2 , B2 , U2 , D2 ⟩ max 6 branch factor

G 4 = { 1 } solved

  

Due to the reduction of the branch factor the searches can be done much faster.

  

Group 1 is when all the "bad edges" are gone, this means all the edges are oriented and can be brought to their proper position without doing the move F or F'/ B or B'.

Group 2 is when the all the corners have an orientation of 0, and the edges in the E slice (FR,FL,BR,BL) are moved into said slice. This cuts out L and R half turns, leaving the only moves in G2.

Group 3 is when all the corners are moved into the correct "orbit"/tetrad, which means that the corners can be brought to their correct place with only 180 degree turns. The edges are in the correct slice.

[[Symmetries and Redundancies]]
[[Rubiks cube representation]]
  
  

heuristics for lower bound of solving