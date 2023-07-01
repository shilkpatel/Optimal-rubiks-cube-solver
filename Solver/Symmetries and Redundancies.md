Within the Rubik's cube there are many symmetries and redundancies which need to be addressed, or the program ends up doing much more processing than needed.

An example is if a face quarter turn is made {R,L,F,B,U,D,R',L',F',B',U',D'} the next move cannot be the same face turn but in the opposite direction eg R then R'. This is because this brings the cube back to the position it was in before, and therefore wastes processing. This presents a much bigger problem when doing searches with a large depth of up to 12. This shows how important it is to ensure we catch all of these redundancies.

All Symmetries, Transpositions and Redundancies
1. When a quarter face is done, the face cannot be turned on the next move, if the quarter face turn is done again then this is equivalent to turning the page twice, if the inverse is done then we make no progress, if a half turn is done then it is equivalent as the inverse. So if {R} then not {R,R',R2}
2. When 2 opposing faces are turned, the next turn cannot be either of the 2 faces because of the first symmetry. So if {L,R} then not {L,L',L2,R,R',R2}.