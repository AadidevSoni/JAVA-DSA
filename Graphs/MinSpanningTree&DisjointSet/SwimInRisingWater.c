class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        List<int[]> cells = new ArrayList<>();
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                cells.add(new int[]{grid[row][col],row,col});
            }
        }
        Collections.sort(cells, (a,b) -> a[0]-b[0]);
        int[][] vis = new int[n][n];
        DisjointSet ds = new DisjointSet(n*n);
        int[] drow = {-1,0,1,0};
        int[] dcol = {0,1,0,-1};

        for(int[] cell: cells) {
            int time = cell[0];
            int row = cell[1];
            int col = cell[2];
            vis[row][col] = 1;
            int cellNo = row * n + col;
            for(int i=0;i<4;i++) {
                int row_ = row + drow[i];
                int col_ = col + dcol[i];
                if(row_ >= 0 && row_ < n && col_ >= 0 && col_ < n && vis[row_][col_] == 1) {
                    int adjNodeNo = row_ * n + col_;
                    ds.unionBySize(cellNo,adjNodeNo);
                }
            }
            if(vis[0][0] == 1 && vis[n-1][n-1] == 1 && ds.findUPar(0) == ds.findUPar(n * n-1)) {
                return time;
            }
        }
        return -1;
    }
}

class DisjointSet {
    List<Integer> parent = new ArrayList<>();
    List<Integer> size = new ArrayList<>();

    public DisjointSet(int n) {
        for(int i = 0; i < n; i++) {
            parent.add(i);
            size.add(1);
        }
    }

    public int findUPar(int node) {
        if(parent.get(node) == node) return node;

        int ulp = findUPar(parent.get(node));
        parent.set(node, ulp);

        return ulp;
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
}