class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] num = new int[n+2];
        num[0] = 1;
        num[n+1] = 1;
        for(int i=1;i<=n;i++) {
            num[i] = nums[i-1];
        }
        int[][] dp = new int[n+2][n+2];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int res = f(1,n,num,dp);
        return res;
    }

    public int f(int i, int j, int[] nums, int[][] dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int max = Integer.MIN_VALUE;
        for(int ind=i;ind<=j;ind++) {
            int coins = nums[i-1] * nums[ind] * nums[j+1] + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
            max = Math.max(max,coins);
        }
        return dp[i][j] =  max;
    }
}