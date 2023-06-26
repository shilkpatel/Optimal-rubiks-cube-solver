This is when the colours are represented within a:

1d where each index is a place on a face
2d where each sub array is a face and the colours are within the sub arrays.

These representations are simple to implement and also print out/display.
On the other hand, this is slow.
For a single turn you would need to swap each colour on  the face and the surrounding faces as well.
eg
A turn on the U face results in an update on the F,R,B,L face.


This means that using this when coding an optimal solver, using this representation would be a terrible idea as it would take over a day.

