package solverv2;

  

import java.util.Objects;

  

public class Cubie

{

int index;

int orientation;

public Cubie(int index, int orientation)

{

this.index=index;

this.orientation=orientation;

}

public void update_corner_orientation(int rotation)

{

orientation+= rotation;

orientation%=3;

}

public void update_edge_orientation(int rotation)

{

orientation+= rotation;

orientation%=2;

}

public int hashCode() {

return Objects.hash(index,orientation);

}

  

  

}