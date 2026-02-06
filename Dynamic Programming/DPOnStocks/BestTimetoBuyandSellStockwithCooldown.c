//Recursion
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int res = f(0,1,prices);
        return res;
    }

    public int f(int ind, int buy, int[] prices) {
        if(ind >= prices.length) {
            return 0;
        }
        int profit = 0;
        if(buy == 1) {
            profit = Math.max(-prices[ind]+f(ind+1,0,prices),0+f(ind+1,1,prices));
        }else {
            profit = Math.max(prices[ind]+f(ind+2,1,prices),0+f(ind+1,0,prices));
        }
        return profit;
    }
}

//Dynamic
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int res = f(0,1,prices,dp);
        return res;
    }

    public int f(int ind, int buy, int[] prices, int[][] dp) {
        if(ind >= prices.length) {
            return 0;
        }
        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        if(buy == 1) {
            dp[ind][buy] = Math.max(-prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
        }else {
            dp[ind][buy] = Math.max(prices[ind]+f(ind+2,1,prices,dp),0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy];
    }
}