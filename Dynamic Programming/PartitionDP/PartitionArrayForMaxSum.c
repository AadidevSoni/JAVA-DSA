class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp,-1);
        int res = f(0,arr,n,k,dp);
        return res;
    }

    public int f(int i, int[] arr, int n, int k,int[] dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int len = 0;
        int max = Integer.MIN_VALUE;
        int maxAns = Integer.MIN_VALUE;
        for(int j=i;j<Math.min(i+k,n);j++) {
            len++;
            max = Math.max(max, arr[j]);
            int cost = f(j+1,arr,n,k,dp) + (len * max);
            maxAns = Math.max(maxAns, cost);
        }
        return dp[i] = maxAns;
    }
}