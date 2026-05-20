class Solution {
    public int minCost(int n, int[] cuts) {
        int sz = cuts.length;
        int[] cut = new int[sz+2];
        cut[0] = 0;
        cut[sz+1] = n;
        Arrays.sort(cuts);
        int[][] dp = new int[sz+2][sz+2];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        for(int i=1;i<=sz;i++) {
            cut[i] = cuts[i-1];
        }
        int res = f(1,sz,cut,dp);
        return res;
    }

    public int f(int i, int j, int[] cuts, int[][] dp) {
        if(i > j) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        for(int ind=i;ind<=j;ind++) {
            int cost = cuts[j+1]-cuts[i-1] + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            min = Math.min(min,cost);
        }
        dp[i][j] =  min;
        return dp[i][j];
    }
}