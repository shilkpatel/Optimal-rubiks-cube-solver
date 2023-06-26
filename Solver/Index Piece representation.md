This is when we store  the pieces of the cube as if it would be in real life, we store the position and the orientation of each of the pieces.

There is an array of 12 edges and 8 corners, within the arrays are stored the colour of the piece and the orientation (0-1 for edges, 0-2 for corners).

Because there is only a total of 20 cubies, performing rotations requires less steps than if the cube was in an array, and the orientations can be updated each turn. This would allow much easier look up for a pattern database.

This is the representation I will use