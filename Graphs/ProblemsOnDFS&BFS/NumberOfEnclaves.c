class Solution {
    public int numEnclaves(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] vis = new int[r][c];
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                vis[i][j] = 0;
            }
        }

        int[] drow = {-1,0,1,0};
        int[] dcol = {0,1,0,-1};
        for(int i=0;i<c;i++) {
            if(grid[0][i] == 1 && vis[0][i] == 0) {
                dfs(0,i,drow,dcol,vis,grid);
            }
            if(grid[r-1][i] == 1 && vis[r-1][i] == 0) {
                dfs(r-1,i,drow,dcol,vis,grid);
            }
        }
        for(int i=0;i<r;i++) {
            if(grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i,0,drow,dcol,vis,grid);
            }
            if(grid[i][c-1] == 1 && vis[i][c-1] == 0) {
                dfs(i,c-1,drow,dcol,vis,grid);
            }
        }

        int count = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void dfs(int row, int col, int[] drow, int[] dcol, int[][] vis, int[][] grid) {
        vis[row][col] = 1;
        int r = grid.length;
        int c = grid[0].length;
        for(int i=0;i<4;i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(nrow,ncol,drow,dcol,vis,grid);
            }
        }
    }
}