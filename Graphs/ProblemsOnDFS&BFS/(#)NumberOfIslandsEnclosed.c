class Solution {
    public int numIslands(char[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] vis = new int[r][c];
        int islands = 0;

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return islands;
    }

    public void dfs(int row, int col, char[][] grid, int[][] vis) {
        vis[row][col] = 1;
        int r = grid.length;
        int c = grid[0].length;
        int[] drow = {-1,0,1,0};
        int[] dcol = {0,1,0,-1};
        for(int i=0;i<4;i++) {
            int row_ = row + drow[i];
            int col_ = col + dcol[i];
            if(row_ >= 0 && row_ < r && col_ >= 0 && col_ < c && grid[row_][col_] == '1' && vis[row_][col_] == 0) {
                dfs(row_,col_,grid,vis);
            }
        }
    }
}