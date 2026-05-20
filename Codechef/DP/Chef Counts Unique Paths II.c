class Solution {
    public long countUniquePaths(int[][] grid) {
        
        int m = grid.length;
        int n = grid[0].length;
        long[][] dp = new long[m][n];
        for(long[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        long res = f(m-1,n-1,grid,dp);
        return res;
    }
    
    public static long f(int i, int j, int[][] grid, long[][] dp) {
        if(i==0 && j ==0) {
            if(grid[i][j] == 0) {
                return 1;
            }else {
                return 0;
            }
        }
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(grid[i][j] == 1) {
            return 0;
        }
        long up = f(i-1,j,grid,dp);
        long left = f(i,j-1,grid,dp);
        dp[i][j] = up + left;
        return dp[i][j];
    }
}