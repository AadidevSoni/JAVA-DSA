class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;
        int[][] dp = new int[n][m];
        for(int[] row: dp) {
            Arrays.fill(row,-1);
        }
        int res = f(n-1,m-1,obstacleGrid,dp);
        return res;
    }

    public int f(int i, int j, int[][] grid, int[][] dp) {
        if(i==0 && j==0) {
            if(grid[i][j] == 0) {
                return 1;
            }else {
                return 0;
            }
        }
        if(i<0 || j<0) {
            return 0;
        }
        if(grid[i][j] == 1) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = f(i-1,j,grid,dp);
        int left = f(i,j-1,grid,dp);
        dp[i][j] = up + left;
        return dp[i][j];
    }
}