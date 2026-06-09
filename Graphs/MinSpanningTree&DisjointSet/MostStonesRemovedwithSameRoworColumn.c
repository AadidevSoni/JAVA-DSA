class Solution {
    public int removeStones(int[][] stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.length;
        for(int i=0;i<n;i++) {
            maxRow = Math.max(maxRow,stones[i][0]);
            maxCol = Math.max(maxCol,stones[i][1]);
        }
        DisjointSet ds = new DisjointSet(maxRow+maxCol+2);
        HashMap<Integer,Integer> stoneNodes = new HashMap<>();
        for(int i=0;i<n;i++) {
            int noderow = stones[i][0];
            int nodecol = stones[i][1] + maxRow + 1;
            ds.unionByRank(noderow,nodecol); 
            stoneNodes.put(noderow,1);
            stoneNodes.put(nodecol,1);
        }

        int cnt = 0;
        for(Map.Entry<Integer, Integer> it: stoneNodes.entrySet()) {
            if(ds.findUPar(it.getKey()) == it.getKey()) {
                cnt++;
            }
        }
        return n-cnt;
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