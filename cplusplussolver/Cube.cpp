#include "Cubie.h"

class Cube {
    public:
        Cubie* edges= new Cubie[12];
        Cubie* corners = new Cubie[8];
        Cube(){
            for(int i=0;i<8;i++){
                Cubie c(i,0);
                edges[i] = c;
            }
        }
        
};