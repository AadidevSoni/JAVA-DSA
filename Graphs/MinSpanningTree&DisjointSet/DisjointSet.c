package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		DisjointSet ds = new DisjointSet(7);
		ds.unionByRank(1, 2);
		ds.unionByRank(2, 3);
		ds.unionByRank(4, 5);
		ds.unionByRank(6, 7);
		ds.unionByRank(5, 6);
		
		//If 3 and 7 on same component;
		if(ds.findUPar(3) == ds.findUPar(7)) {
			System.out.println("Same component");
		}else {
			System.out.println("Diff component");
		}
		
		ds.unionByRank(3, 4);
		
		if(ds.findUPar(3) == ds.findUPar(7)) {
			System.out.println("Same component");
		}else {
			System.out.println("Diff component");
		}
		
    }
	
	
}

class DisjointSet {
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
	public DisjointSet(int n) {
		for(int i=0;i<=n;i++) {
			rank.add(0);
			parent.add(i);
		}
	}
	
	public int findUPar(int node) {
		if(node == parent.get(node)) {
			return node;
		}
		int ulpar = findUPar(parent.get(node));
		parent.set(node, ulpar);
		return parent.get(node);
	}
	
	public void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		if(ulp_u == ulp_v) return; //belongs to same parent
		if(rank.get(ulp_u) < rank.get(ulp_v)) {
			parent.set(ulp_u, ulp_v);
		}else if(rank.get(ulp_u) > rank.get(ulp_v)) {
			parent.set(ulp_v, ulp_u);
		}else {
			parent.set(ulp_v, ulp_u);
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU+1);
		}
	}
}


