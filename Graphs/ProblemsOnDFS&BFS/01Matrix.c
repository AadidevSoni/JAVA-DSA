class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;
        int[][] vis = new int[r][c];
        int[][] dist = new int[r][c];

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                vis[i][j] = 0;
                dist[i][j] = 0;
            }
        }

        Queue<Pair> queue = new LinkedList<>();
        
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    queue.add(new Pair(i,j,0));
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!queue.isEmpty()) {
            int ro = queue.peek().row;
            int co = queue.peek().col;
            int di = queue.peek().distance;
            queue.remove();
            dist[ro][co] = di;
            for(int i=0;i<4;i++) {
                int _row = ro + drow[i];
                int _col = co + dcol[i];
                int _d = di+1;
                if(_row >= 0 && _row < r && _col >= 0 && _col < c && vis[_row][_col] != 1) {
                    vis[_row][_col] = 1;
                    queue.add(new Pair(_row,_col,_d));
                }  
            }
        }

        return dist;
    }
}

class Pair {
    int row;
    int col;
    int distance;
    Pair(int row, int col, int distance) {
        this.row = row;
        this.col = col;
        this.distance = distance;
    }
}