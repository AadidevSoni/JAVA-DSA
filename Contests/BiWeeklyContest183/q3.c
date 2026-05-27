class Solution {
    public int maxScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][][] dp = new int[m][n][m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    Arrays.fill(dp[i][j][k], Integer.MIN_VALUE);
                }
            }
        }
        int res = f(0,0,m-1,0,grid,m,n,dp);
        return res;
    }

    public int f(int i1, int j1, int i2, int j2, int[][] grid, int m, int n, int[][][][] dp) {
        if (i1 >= m || j1 >= n || i2 < 0 || j2 >= n) {
            return Integer.MIN_VALUE / 2;
        }
        if(i1 == m-1 && j1 == n-1 && i2 == 0 && j2 == n-1) {
            if(i1 == i2 && j1 == j2) {
                return grid[i1][j1];
            }
            return 0;
        }
        if (dp[i1][j1][i2][j2] != Integer.MIN_VALUE) {
            return dp[i1][j1][i2][j2];
        }
        int shared = 0;
        if(i1 == i2 && j1 == j2) {
            shared = grid[i1][j1];
        }
        int ans = Integer.MIN_VALUE;

        ans = Math.max(ans, f(i1 + 1, j1, i2 - 1, j2, grid,m,n,dp));
        ans = Math.max(ans, f(i1 + 1, j1, i2, j2 + 1, grid,m,n,dp));
        ans = Math.max(ans, f(i1, j1 + 1, i2 - 1, j2, grid,m,n,dp));
        ans = Math.max(ans, f(i1, j1 + 1, i2, j2 + 1, grid,m,n,dp));
        return dp[i1][j1][i2][j2] = shared + ans;
    }
}©leetcode