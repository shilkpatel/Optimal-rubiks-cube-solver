This is when a 64 bit integer is used to represent a face and 6 64 bit integers for an entire cube

This means that face rotations can be done extremely quickly by rolq and rorq bitwise operations.
This representation also is memory efficient as it only takes integers.

Though this may seem as an optimal representation to use, Korfs algorithm uses pattern databases which need to have the information on the orientation of the edges and corners to effectively query the database.

These databases provides a lower bound heuristic to searches and therefore provide a significant speed up.

There is one more representation.
