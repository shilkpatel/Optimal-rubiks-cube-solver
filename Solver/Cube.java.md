package solverv2;

import java.util.Arrays;
import java.util.Objects;

public class Cube {
	Cubie[] edges;
	Cubie[] corners;
	
	public Cube() 
	{
		edges= new Cubie[12];
		corners = new Cubie[8];
		
		for(int i=0;i<12;i++) 
		{
			edges[i] = new Cubie(i,0);
		}
		
		for(int i=0;i<8;i++) 
		{
			corners[i] = new Cubie(i,0);
		}
	}
	
	public void R() 
	{
		Cube new_cube = this;

        Cubie temp = new Cubie(-1,-1);
        
        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[1];
        new_cube.corners[1] = new_cube.corners[5];
        new_cube.corners[5] = new_cube.corners[4];
        new_cube.corners[4] = temp;

        new_cube.corners[0].update_corner_orientation(1);
        new_cube.corners[1].update_corner_orientation(2);
        new_cube.corners[5].update_corner_orientation(1);
        new_cube.corners[4].update_corner_orientation(2);

        //Cubie temp = new Cubie(-1,-1);

        temp = new_cube.edges[1];
        new_cube.edges[1] = new_cube.edges[5];
        new_cube.edges[5] = new_cube.edges[9];
        new_cube.edges[9] = new_cube.edges[4];
        new_cube.edges[4] = temp;

        
	}

	public void R_prime() 
	{
		Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[5];
        new_cube.corners[5] = new_cube.corners[1];
        new_cube.corners[1] = temp;

        new_cube.corners[0].update_corner_orientation(1);
        new_cube.corners[1].update_corner_orientation(2);
        new_cube.corners[5].update_corner_orientation(1);
        new_cube.corners[4].update_corner_orientation(2);

        temp = new_cube.edges[1];
        new_cube.edges[1] = new_cube.edges[4];
        new_cube.edges[4] = new_cube.edges[9];
        new_cube.edges[9] = new_cube.edges[5];
        new_cube.edges[5] = temp;

  
	}
        
	public void R2() 
	{
		Cube new_cube = this;
		

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[5];
        new_cube.corners[5] = temp;
        //4,5
        temp = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[1];
        new_cube.corners[1] = temp;

        temp = new_cube.edges[1];
        new_cube.edges[1] = new_cube.edges[9];
        new_cube.edges[9] = temp;

        temp = new_cube.edges[4];
        new_cube.edges[4] = new_cube.edges[5];
        new_cube.edges[5] = temp;


	}

	public void L() 
	{
		Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[7];
        new_cube.corners[7] = new_cube.corners[6];
        new_cube.corners[6] = new_cube.corners[2];
        new_cube.corners[2] = temp;

        new_cube.corners[3].update_corner_orientation(2);
        new_cube.corners[7].update_corner_orientation(1);
        new_cube.corners[6].update_corner_orientation(2);
        new_cube.corners[2].update_corner_orientation(1);

        temp = new_cube.edges[3];
        new_cube.edges[3] = new_cube.edges[7];
        new_cube.edges[7] = new_cube.edges[11];
        new_cube.edges[11] = new_cube.edges[6];
        new_cube.edges[6] = temp;

         
	}

	public void L_prime() 
	{
		Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);
        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[6];
        new_cube.corners[6] = new_cube.corners[7];
        new_cube.corners[7] = temp;

        new_cube.corners[3].update_corner_orientation(2);
        new_cube.corners[7].update_corner_orientation(1);
        new_cube.corners[6].update_corner_orientation(2);
        new_cube.corners[2].update_corner_orientation(1);

        temp = new_cube.edges[3];
        new_cube.edges[3] = new_cube.edges[6];
        new_cube.edges[6] = new_cube.edges[11];
        new_cube.edges[11] = new_cube.edges[7];
        new_cube.edges[7] = temp;

         
	}
        
    public void L2()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[6];
        new_cube.corners[6] = temp;

        temp = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[7];
        new_cube.corners[7] = temp;

        temp = new_cube.edges[3];
        new_cube.edges[3] = new_cube.edges[11];
        new_cube.edges[11] = temp;

        temp = new_cube.edges[6];
        new_cube.edges[6] = new_cube.edges[7];
        new_cube.edges[7] = temp;

         
    }
        
    public void F()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[1];
        new_cube.corners[1] = new_cube.corners[0];
        new_cube.corners[0] = temp;

        new_cube.corners[3].update_corner_orientation(1);
        new_cube.corners[2].update_corner_orientation(2);
        new_cube.corners[1].update_corner_orientation(1);
        new_cube.corners[0].update_corner_orientation(2);

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[3];
        new_cube.edges[3] = new_cube.edges[2];
        new_cube.edges[2] = new_cube.edges[1];
        new_cube.edges[1] = temp;

        new_cube.edges[0].update_edge_orientation(1);
        new_cube.edges[3].update_edge_orientation(1);
        new_cube.edges[2].update_edge_orientation(1);
        new_cube.edges[1].update_edge_orientation(1);

         
    }
       
    public void F_prime()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[1];
        new_cube.corners[1] = new_cube.corners[2];
        new_cube.corners[2] = temp;

        new_cube.corners[3].update_corner_orientation(1);
        new_cube.corners[2].update_corner_orientation(2);
        new_cube.corners[1].update_corner_orientation(1);
        new_cube.corners[0].update_corner_orientation(2);

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[1];
        new_cube.edges[1] = new_cube.edges[2];
        new_cube.edges[2] = new_cube.edges[3];
        new_cube.edges[3] = temp;
        
        new_cube.edges[0].update_edge_orientation(1);
        new_cube.edges[3].update_edge_orientation(1);
        new_cube.edges[2].update_edge_orientation(1);
        new_cube.edges[1].update_edge_orientation(1);

         
    }
        
    public void F2()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[1]; 
        new_cube.corners[1] = temp;

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[2];
        new_cube.corners[2] = temp;

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[2];
        new_cube.edges[2] = temp;

        temp = new_cube.edges[1];
        new_cube.edges[1] = new_cube.edges[3];
        new_cube.edges[3] = temp;

         
    } 
        
    public void B()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[5];
        new_cube.corners[5] = new_cube.corners[6];
        new_cube.corners[6] = new_cube.corners[7];
        new_cube.corners[7] = temp;

        new_cube.corners[4].update_corner_orientation(1);
        new_cube.corners[5].update_corner_orientation(2);
        new_cube.corners[6].update_corner_orientation(1);
        new_cube.corners[7].update_corner_orientation(2);

        temp = new_cube.edges[8];
        new_cube.edges[8] = new_cube.edges[9];
        new_cube.edges[9] = new_cube.edges[10];
        new_cube.edges[10] = new_cube.edges[11];
        new_cube.edges[11] = temp;
        

        new_cube.edges[8].update_edge_orientation(1);
        new_cube.edges[9].update_edge_orientation(1);
        new_cube.edges[10].update_edge_orientation(1);
        new_cube.edges[11].update_edge_orientation(1);

         
    }
        
    public void B_prime()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[7];
        new_cube.corners[7] = new_cube.corners[6];
        new_cube.corners[6] = new_cube.corners[5];
        new_cube.corners[5] = temp;

        new_cube.corners[4].update_corner_orientation(1);
        new_cube.corners[5].update_corner_orientation(2);
        new_cube.corners[6].update_corner_orientation(1);
        new_cube.corners[7].update_corner_orientation(2);

        temp = new_cube.edges[8];
        new_cube.edges[8] = new_cube.edges[11];
        new_cube.edges[11] = new_cube.edges[10];
        new_cube.edges[10] = new_cube.edges[9];
        new_cube.edges[9] = temp;
        

        new_cube.edges[8].update_edge_orientation(1);
        new_cube.edges[9].update_edge_orientation(1);
        new_cube.edges[10].update_edge_orientation(1);
        new_cube.edges[11].update_edge_orientation(1);

         
    }
        
    public void B2()
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[6]; 
        new_cube.corners[6] = temp;

        temp = new_cube.corners[7];
        new_cube.corners[7] = new_cube.corners[5];
        new_cube.corners[5] = temp;

        temp = new_cube.edges[8];
        new_cube.edges[8] = new_cube.edges[10];
        new_cube.edges[10] = temp;

        temp = new_cube.edges[11];
        new_cube.edges[11] = new_cube.edges[9];
        new_cube.edges[9] = temp;

         
    }
         
    public void U()
    {
    	Cube new_cube = this;
		 


        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[4];
        new_cube.corners[4] = new_cube.corners[7];
        new_cube.corners[7] = new_cube.corners[3];
        new_cube.corners[3] = temp;

        //# corner orientation has not changed

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[4];
        new_cube.edges[4] = new_cube.edges[8];
        new_cube.edges[8] = new_cube.edges[7];
        new_cube.edges[7] = temp;

         
    }
        
    public void U_prime()
    {
    	Cube new_cube = this;
		 
 

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[7];
        new_cube.corners[7] = new_cube.corners[4];
        new_cube.corners[4] = temp;

        //# corner orientation has not changed

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[7];
        new_cube.edges[7] = new_cube.edges[8];
        new_cube.edges[8] = new_cube.edges[4];
        new_cube.edges[4] = temp;

         
    }
    
    public void U2()
    {
    	Cube new_cube = this;


        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[0];
        new_cube.corners[0] = new_cube.corners[7];
        new_cube.corners[7] = temp;

        temp = new_cube.corners[3];
        new_cube.corners[3] = new_cube.corners[4];
        new_cube.corners[4] = temp;

     

        temp = new_cube.edges[0];
        new_cube.edges[0] = new_cube.edges[8]; 
        new_cube.edges[8] = temp;

        temp = new_cube.edges[7];
        new_cube.edges[7] = new_cube.edges[4];
        new_cube.edges[4] = temp;

         
    }
          
    public void D()
    {
    	Cube new_cube = this;
		 
  

        Cubie temp = new Cubie(-1,-1);

        temp = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[6];
        new_cube.corners[6] = new_cube.corners[5];
        new_cube.corners[5] = new_cube.corners[1];
        new_cube.corners[1] = temp;

  
        temp = new_cube.edges[2];
        new_cube.edges[2] = new_cube.edges[6];
        new_cube.edges[6] = new_cube.edges[10];
        new_cube.edges[10] = new_cube.edges[5];
        new_cube.edges[5] = temp;

         
    }
          
    public void D_prime()
    {
    	Cube new_cube = this;
		 
        

        Cubie temp = new Cubie(-1,-1);

        

        temp = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[1];
        new_cube.corners[1] = new_cube.corners[5];
        new_cube.corners[5] = new_cube.corners[6];
        new_cube.corners[6] = temp;

    

        temp = new_cube.edges[2];
        new_cube.edges[2] = new_cube.edges[5];
        new_cube.edges[5] = new_cube.edges[10];
        new_cube.edges[10] = new_cube.edges[6];
        new_cube.edges[6] = temp;

         
    }
          
    public void D2() 
    {
    	Cube new_cube = this;
		 
         

        Cubie temp = new Cubie(-1,-1);


        temp = new_cube.corners[2];
        new_cube.corners[2] = new_cube.corners[5]; 
        new_cube.corners[5] = temp;

        temp = new_cube.corners[1];
        new_cube.corners[1] = new_cube.corners[6];
        new_cube.corners[6] = temp;

   

        temp = new_cube.edges[2];
        new_cube.edges[2] = new_cube.edges[10];
        new_cube.edges[10] = temp;

        temp = new_cube.edges[5];
        new_cube.edges[5] = new_cube.edges[6];
        new_cube.edges[6] = temp;

         
    }
        
    public int hashCode() 
    {
    	
    	return Arrays.hashCode(corners)+Arrays.hashCode(edges);
    }
    
    public boolean equals(Object o) 
    {
    	Cube c = (Cube)o;
    	boolean match = true;
    	for(int i =0;i<8;i++) 
    	{
    		if(!(corners[i].index==c.corners[i].index && corners[i].orientation==corners[i].orientation)) 
    		{
    			match = false;
    		}
    	}
    	
    	for(int i =0;i<12;i++) 
    	{
    		if(!(edges[i].index==c.edges[i].index && edges[i].orientation==edges[i].orientation)) 
    		{
    			match = false;
    		}
    	}
    	return match;
    }
    
}
