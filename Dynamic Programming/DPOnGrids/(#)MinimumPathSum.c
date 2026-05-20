class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        for(int[] row: dp) {
            Arrays.fill(row,-1);
        }
        int res = f(n-1,m-1,grid,dp);
        return res;
    }

    public int f(int i, int j, int[][] grid, int[][] dp) {
        if(i == 0 && j==0) {
            return grid[0][0];
        }
        if(i<0 || j<0) {
            return 9999999;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);
        int min = Math.min(up,left);
        dp[i][j] = min;
        return dp[i][j];
    }
}