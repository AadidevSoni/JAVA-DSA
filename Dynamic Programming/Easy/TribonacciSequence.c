class Solution {
    public int tribonacci(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        int res = tb(n,dp);
        return res;
    }

    public int tb(int n, int[] dp) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = tb(n-1,dp) + tb(n-2,dp) + tb(n-3,dp);
        return dp[n];
    }
}