class Solution {
    public int calculateMinimumPathSum(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int res = f(m-1,n-1,grid,dp);
        return res;
    }
    
    public int f(int i, int j, int[][] grid, int[][] dp) {
        if(i==0 && j==0) {
            return grid[i][j];
        }
        if(i < 0 || j < 0) {
            return 99999;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = f(i-1,j,grid,dp) + grid[i][j];
        int left = f(i,j-1,grid,dp) + grid[i][j];
        dp[i][j] = Math.min(up,left);
        return dp[i][j];
    }
}
