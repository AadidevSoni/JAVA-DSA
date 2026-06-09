class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n*n);
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                if(grid[row][col] == 0) {
                    continue;
                }
                int[] drow = {-1,0,1,0};
                int[] dcol = {0,1,0,-1};
                for(int i=0;i<4;i++) {
                    int row_ = row + drow[i];
                    int col_ = col + dcol[i];
                    if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < n && grid[row_][col_] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = row_ * n + col_;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }

        int max = 0;
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                if(grid[row][col] == 1) {
                    continue;
                }
                int[] drow = {-1,0,1,0};
                int[] dcol = {0,1,0,-1};
                Set<Integer> components = new HashSet<>();
                for(int i=0;i<4;i++) {
                    int row_ = row + drow[i];
                    int col_ = col + dcol[i];
                    if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < n && grid[row_][col_] == 1) {
                        components.add(ds.findUPar(row_ * n + col_));
                    }
                }
                int size = 0;
                for(Integer parents: components) {
                    size += ds.size.get(parents);
                }
                max = Math.max(max,size+1);
            }
        }

        //If All 1
        for(int cell = 0; cell < n * n; cell++) {
            max = Math.max(max,ds.size.get(ds.findUPar(cell)));
        }
        return max;
    }
}

class DisjointSet {
	List<Integer> rank = new ArrayList<>();
	List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();

	public DisjointSet(int n) {
		for(int i=0;i<=n;i++) {
			rank.add(0);
			parent.add(i);
            size.add(1);
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

    public void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size.get(pu) < size.get(pv)) {
            parent.set(pu, pv);
            size.set(pv, size.get(pv) + size.get(pu));
        } else {
            parent.set(pv, pu);
            size.set(pu, size.get(pu) + size.get(pv));
        }
    }
}s