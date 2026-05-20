class Solution {
    public long calculateUniquePaths(int rowCount, int columnCount) {
        
        long[][] dp = new long[rowCount][columnCount];
        for(long[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        long res = f(rowCount-1,columnCount-1,dp);
        return res;
        
    }
    
    public static long f(int i, int j, long[][] dp) {
        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        long up = f(i-1,j,dp);
        long left = f(i,j-1,dp);
        dp[i][j] = up+left;
        return dp[i][j];
    }
}
