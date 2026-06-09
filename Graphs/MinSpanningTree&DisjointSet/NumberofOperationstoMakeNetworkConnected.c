class Solution {
    public int makeConnected(int n, int[][] connections) {
        DisjointSet ds = new DisjointSet(n);
        int extraEdges = 0;
        int m = connections.length;
        for(int i=0;i<m;i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUPar(u) == ds.findUPar(v)) {
                extraEdges++;
            }else {
                ds.unionByRank(u,v);
            }
        }
        int components = 0;
        for(int i=0;i<n;i++) {
            if(ds.parent.get(i) == i) {
                components++;
            }
        }
        int ans = components - 1;
        if(extraEdges >= ans) {
            return ans;
        }
        return -1;
    }
}

class DisjointSet {
    List<Integer> rank = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    public DisjointSet(int n) {
        for(int i=0;i<n;i++) {
            rank.add(0);
            parent.add(i);
        }
    }

    public int findUPar(int node) {
        if(parent.get(node) == node) {
            return node;
        }
        int ulpar = findUPar(parent.get(node));
        parent.set(node,ulpar);
        return parent.get(node);
    }

    public void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank.get(ulp_u) < rank.get(ulp_v)) {
            parent.set(ulp_u,ulp_v);
        }else if(rank.get(ulp_u) > rank.get(ulp_v)) {
            parent.set(ulp_v,ulp_u);
        }else {
            parent.set(ulp_v, ulp_u); //rank increases if both equal rank
			int rankU = rank.get(ulp_u);
			rank.set(ulp_u, rankU+1);
        }
    }
}