class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        for (int[] row : dp) Arrays.fill(row, -1);
        return f(0, 1, prices, dp, fee);
    }

    public int f(int i, int buy, int[] p, int[][] dp, int fee) {
        if (i == p.length){
            return 0;
        }
        if (dp[i][buy] != -1){
            return dp[i][buy];
        }
        if (buy == 1) {
            dp[i][buy] = Math.max(-p[i] + f(i+1, 0, p, dp, fee),0+f(i+1, 1, p, dp, fee));
        } else {
            dp[i][buy] = Math.max(p[i] - fee + f(i+1, 1, p, dp, fee),0+f(i+1, 0, p, dp, fee));
        }

        return dp[i][buy];
    }
}
