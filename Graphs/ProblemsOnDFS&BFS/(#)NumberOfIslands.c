class Solution {
    public int numIslands(char[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] vis = new int[r][c];

        int[] drow = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dcol = {-1,  0,  1, -1, 1, -1, 0, 1};

        int islands = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid, vis, drow, dcol);
                }
            }
        }
        return islands;
    }

    private void dfs(int row, int col, char[][] grid, int[][] vis,
                     int[] drow, int[] dcol) {
        vis[row][col] = 1;

        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < grid.length &&
                ncol >= 0 && ncol < grid[0].length &&
                vis[nrow][ncol] == 0 &&
                grid[nrow][ncol] == '1') {

                dfs(nrow, ncol, grid, vis, drow, dcol);
            }
        }
    }
}
