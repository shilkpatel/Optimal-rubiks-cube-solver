package solverv2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class CubeTree {
	Cube state;
	
	ArrayList<CubeTree> children;
	
	public int depth;
	
	public static Map<Integer,Integer[]> lookup = new LimitedHash<>();
	
	public static int hit =0;
	
	
	public CubeTree(Cube state) 
	{
		this.state = state;
		this.children = new ArrayList<CubeTree>();
	}
	/**
	public void generate_children() 
	{
		
		CubeTree  r_child =new CubeTree(state.R());
		Integer[] r_info = lookup.get(r_child.state.hashCode());
		if(r_info == null) 
		{
			children.add(r_child);
			lookup.put(r_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(r_info[0]==r_child.depth+1 && r_info[1] ==0) 
			{
				r_info[1]+=1;
				lookup.put(r_child.state.hashCode(), r_info);
				children.add(r_child);
			}
			hit+=1;
		}
		
		
		CubeTree r_prime_child = new CubeTree(state.R_prime());
		Integer[] rprime_info = lookup.get(r_prime_child.state.hashCode());
		if(rprime_info == null) 
		{
			children.add(r_prime_child);
			lookup.put(r_prime_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(rprime_info[0]==r_prime_child.depth+1 && rprime_info[1] ==0) 
			{
				rprime_info[1]+=1;
				children.add(r_prime_child);
			}
			hit+=1;
		}
		
		
		
		
		
		
		
		
		CubeTree r2_child = new CubeTree(state.R2());

		Integer[] r2_info = lookup.get(r2_child.state.hashCode());
		if(r2_info == null) 
		{
			children.add(r2_child);
			lookup.put(r2_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(r2_info[0]==r2_child.depth+1 && r2_info[1] ==0) 
			{
				r2_info[1]+=1;
				children.add(r2_child);
			}
			hit+=1;
		}
		
		
		CubeTree  l_child =new CubeTree(state.L());
		Integer[] l_info = lookup.get(l_child.state.hashCode());
		if(l_info == null) 
		{
			children.add(l_child);
			lookup.put(l_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(l_info[0]==l_child.depth+1 && l_info[1] ==0) 
			{
				l_info[1]+=1;
				children.add(l_child);
			}
			hit+=1;
		}
		
		CubeTree  l_prime_child =new CubeTree(state.L_prime());
		Integer[] l_prime_info = lookup.get(l_prime_child.state.hashCode());
		if(l_prime_info == null) 
		{
			children.add(l_prime_child);
			lookup.put(l_prime_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(l_prime_info[0]==l_prime_child.depth+1 && l_prime_info[1] ==0) 
			{
				l_prime_info[1]+=1;
				children.add(l_prime_child);
			}
			hit+=1;
		}
		
		CubeTree  l2_child =new CubeTree(state.L2());
		Integer[] l2_info = lookup.get(l2_child.state.hashCode());
		if(l2_info == null) 
		{
			children.add(l2_child);
			lookup.put(l2_child.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(l2_info[0]==l2_child.depth+1 && l2_info[1] ==0) 
			{
				l2_info[1]+=1;
				children.add(l2_child);
			}
			hit+=1;
		}
		
		
		CubeTree  root =new CubeTree(state.U());
		Integer[] u_info = lookup.get(root.state.hashCode());
		if(u_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(u_info[0]==depth+1 && u_info[1] ==0) 
			{
				u_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.U_prime());
		Integer[] u_prime_info = lookup.get(root.state.hashCode());
		if(u_prime_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(u_prime_info[0]==depth+1 && u_prime_info[1] ==0) 
			{
				u_prime_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.U2());
		Integer[] u2_info = lookup.get(root.state.hashCode());
		if(u2_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(u2_info[0]==depth+1 && u2_info[1] ==0) 
			{
				u2_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		
		
		CubeTree  root =new CubeTree(state.D());
		Integer[] d_info = lookup.get(root.state.hashCode());
		if(d_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(d_info[0]==depth+1 && d_info[1] ==0) 
			{
				d_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.D_prime());
		Integer[] d_prime_info = lookup.get(root.state.hashCode());
		if(d_prime_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(d_prime_info[0]==depth+1 && d_prime_info[1] ==0) 
			{
				d_prime_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.D2());
		Integer[] d2_info = lookup.get(root.state.hashCode());
		if(d2_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(d2_info[0]==depth+1 && d2_info[1] ==0) 
			{
				d2_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		
		
		CubeTree  root =new CubeTree(state.F());
		Integer[] f_info = lookup.get(root.state.hashCode());
		if(f_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(f_info[0]==depth+1 && f_info[1] ==0) 
			{
				f_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.F_prime());
		Integer[] f_prime_info = lookup.get(root.state.hashCode());
		if(f_prime_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(f_prime_info[0]==depth+1 && f_prime_info[1] ==0) 
			{
				f_prime_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.F2());
		Integer[] f2_info = lookup.get(root.state.hashCode());
		if(f2_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(f2_info[0]==depth+1 && f2_info[1] ==0) 
			{
				f2_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		
		CubeTree  root =new CubeTree(state.B());
		Integer[] b_info = lookup.get(root.state.hashCode());
		if(b_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(b_info[0]==depth+1 && b_info[1] ==0) 
			{
				b_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.B_prime());
		Integer[] b_prime_info = lookup.get(root.state.hashCode());
		if(b_prime_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(b_prime_info[0]==depth+1 && b_prime_info[1] ==0) 
			{
				b_prime_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		CubeTree  root =new CubeTree(state.B2());
		Integer[] b2_info = lookup.get(root.state.hashCode());
		if(b2_info == null) 
		{
			children.add(root);
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		}else {
			if(b2_info[0]==depth+1 && b2_info[1] ==0) 
			{
				b2_info[1]+=1;
				children.add(root);
			}
			hit+=1;
		}
		
		
		
	}	
	
	
	public static int dfs(CubeTree root,int depth) 
	{
		int total=0;
		
		if(depth ==0) 
		{
			return 1;
		}
		root.generate_children();
		for(CubeTree i:root.children) 
		{
			total+=dfs(i,depth-1) ;
		}
		return total;
	}
	
	**/

	public static int dfs_v2(CubeTree root,int depth,int max_depth) 
	{
		int total =0;
		if(depth ==max_depth) 
		{
			return 1;
		}
		
		
		root.state.R();
		Integer[] r_info = lookup.get(root.state.hashCode());
		
		
		if(r_info == null) 
		{
			
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
			
			total += dfs_v2(root,depth+1,max_depth);

			
			
		}else {
		
			if(r_info[0]==depth+1 && (r_info[1] ==0)) 
			{
	
				r_info[1]+=1;
				
		
		
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.R_prime();
		
		
		root.state.R_prime();
		Integer[] rprime_info = lookup.get(root.state.hashCode());
		if(rprime_info == null) 
		{
	
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(rprime_info[0]==depth+1 && rprime_info[1] ==0) 
			{
				rprime_info[1]+=1;
		
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.R();
		
		
		root.state.R2();
		Integer[] r2_info = lookup.get(root.state.hashCode());
		if(r2_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
			
		}else {
			if(r2_info[0]==depth+1 && r2_info[1] ==0) 
			{
				r2_info[1]+=1;
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.R2();
		
		
		root.state.L();
		Integer[] l_info = lookup.get(root.state.hashCode());
		if(l_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(l_info[0]==depth+1 && (l_info[1] ==0))
			{
				l_info[1]+=1;
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.L_prime();
		
		root.state.L_prime();
		Integer[] l_prime_info = lookup.get(root.state.hashCode());
		if(l_prime_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(l_prime_info[0]==depth+1 && l_prime_info[1] ==0) 
			{
				l_prime_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.L();
		
		
		
		root.state.L2();
		Integer[] l2_info = lookup.get(root.state.hashCode());
		if(l2_info == null)
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});

			total += dfs_v2(root,depth+1,max_depth);
			 
			
			
		}
		else 
		{
			if(l2_info[0]==depth+1 && l2_info[1] ==0) 
			{
				l2_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.L2();
		
		
		root.state.U();
		Integer[] u_info = lookup.get(root.state.hashCode());
		if(u_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(u_info[0]==depth+1 && u_info[1] ==0) 
			{
				u_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.U_prime();
		
		root.state.U_prime();
		Integer[] u_prime_info = lookup.get(root.state.hashCode());
		if(u_prime_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(u_prime_info[0]==depth+1 && u_prime_info[1] ==0) 
			{
				u_prime_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
			
			}
			hit+=1;
		}
		root.state.U();
		
		root.state.U2();
		Integer[] u2_info = lookup.get(root.state.hashCode());
		if(u2_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(u2_info[0]==depth+1 && u2_info[1] ==0) 
			{
				u2_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.U2();
		
		
		
		root.state.D();
		Integer[] d_info = lookup.get(root.state.hashCode());
		if(d_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(d_info[0]==depth+1 && d_info[1] ==0) 
			{
				d_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.D_prime();
		
		root.state.D_prime();
		Integer[] d_prime_info = lookup.get(root.state.hashCode());
		if(d_prime_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(d_prime_info[0]==depth+1 && d_prime_info[1] ==0) 
			{
				d_prime_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.D();
		
		root.state.D2();
		Integer[] d2_info = lookup.get(root.state.hashCode());
		if(d2_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(d2_info[0]==depth+1 && d2_info[1] ==0) 
			{
				d2_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.D2();
		
		
		root.state.F();
		Integer[] f_info = lookup.get(root.state.hashCode());
		if(f_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
			
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(f_info[0]==depth+1 && f_info[1] ==0) 
			{
				f_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.F_prime();
		
		root.state.F_prime();
		Integer[] f_prime_info = lookup.get(root.state.hashCode());
		if(f_prime_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
			
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(f_prime_info[0]==depth+1 && f_prime_info[1] ==0) 
			{
				f_prime_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.F();
		
		root.state.F2();
		Integer[] f2_info = lookup.get(root.state.hashCode());
		if(f2_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(f2_info[0]==depth+1 && f2_info[1] ==0) 
			{
				f2_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.F2();
		
		
		root.state.B();
		Integer[] b_info = lookup.get(root.state.hashCode());
		if(b_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(b_info[0]==depth+1 && b_info[1] ==0) 
			{
				b_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.B_prime();
		
		root.state.B_prime();
		Integer[] b_prime_info = lookup.get(root.state.hashCode());
		if(b_prime_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
		
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(b_prime_info[0]==depth+1 && b_prime_info[1] ==0) 
			{
				b_prime_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.B();
		
		root.state.B2();
		Integer[] b2_info = lookup.get(root.state.hashCode());
		if(b2_info == null) 
		{
			lookup.put(root.state.hashCode(), new Integer[] {depth+1,1});
	
			total += dfs_v2(root,depth+1,max_depth);
			 
			
		}else {
			if(b2_info[0]==depth+1 && b2_info[1] ==0) 
			{
				b2_info[1]+=1;
				 
				total += dfs_v2(root,depth+1,max_depth);
				 
				
			}
			hit+=1;
		}
		root.state.B2();
		return total;
		
		
	}
	
	public static void clearLookupOccurances() 
	{
		for(Integer[] i: CubeTree.lookup.values()) 
		{
			i[1]=0;
		}
	}
	
	public static void iterativeDeepeningDepthFirstSearch(CubeTree root,int limit) {
		for(int i=1;i<i+1;i++) 
		{
			long start = System.currentTimeMillis();
			int result = CubeTree.dfs_v2(root, 0,i);
			long end = System.currentTimeMillis();
			
			System.out.println("result "+result);
			System.out.println("depth "+i);
			System.out.println("lookup size "+CubeTree.lookup.size());
			System.out.println("runtime "+(end-start));
			System.out.println(" ");
			CubeTree.clearLookupOccurances();
		}
	}
}
