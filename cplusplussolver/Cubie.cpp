

class Cubie{
    public:
        int index;
        int orientation;

        Cubie(){
            
        }

        Cubie(int index,int orientation){
            index = index;
            orientation = orientation;
        }

        void update_corner_orientation(int rotation){
            orientation += rotation;
            orientation %= 3;
        }

        void update_edge_orientation(int rotation)
        {
            orientation += rotation;
            orientation %= 2;
        }
        
};