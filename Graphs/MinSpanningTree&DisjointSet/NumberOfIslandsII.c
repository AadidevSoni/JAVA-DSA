package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int n = 4;
		int m = 5;
		int[][] operators = {
				{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2}
		};
		DisjointSet ds = new DisjointSet(n*m);
		int[][] vis = new int[n][m];
		List<Integer> ans = new ArrayList<>();
		int count = 0;
		int len = operators.length;
		for(int i=0;i<len;i++) {
			int row = operators[i][0];
			int col = operators[i][1];
			if(vis[row][col] == 1) {
				ans.add(count);
				continue;
			}
			vis[row][col] = 1;
			count += 1;
			int[] drow = {-1,0,1,0};
			int[] dcol = {0,1,0,-1};
			for(int j=0;j<4;j++) {
				int row_ = row + drow[j];
				int col_ = col + dcol[j];
				if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < m && vis[row_][col_] == 1) {
					int nodeNo = row * m + col;
					int adjNodeNo = row_ * m + col_;
					if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
						count--;
						ds.unionByRank(nodeNo, adjNodeNo);
					}
				}
			}
			ans.add(count);
		}
		
		for(int i=0;i<ans.size();i++) {
			System.out.print(ans.get(i) + " ");
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


