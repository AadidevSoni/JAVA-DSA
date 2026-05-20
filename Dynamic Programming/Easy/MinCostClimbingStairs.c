class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n];
        int[] dp1 = new int[n];
        Arrays.fill(dp,-1);
        Arrays.fill(dp1,-1);
        int cost1 = f(0,cost,n,dp);
        int cost2 = f(1,cost,n,dp1);
        return(Math.min(cost1,cost2));
    }

    public int f(int ind, int[] cost, int n,int[] dp) {
        if(ind == n-1) {
            return cost[ind];
        }
        if(ind >= n) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int c1 = cost[ind] + f(ind+1,cost,n,dp);
        int c2 = cost[ind] + f(ind+2,cost,n,dp);
        dp[ind] = Math.min(c1,c2);
        return dp[ind];
    }
}