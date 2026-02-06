//Recursion
class Solution {
    public int maxProfit(int k, int[] prices) {
        int res = f(0,1,k,prices);
        return res;
    }

    public int f(int ind, int buy, int cap, int[] prices) {
        if(ind == prices.length) {
            return 0;
        }
        if(cap == 0) {
            return 0;
        }
        int profit = 0;
        if(buy == 1) {
            profit = Math.max(-prices[ind]+f(ind+1,0,cap,prices),0+f(ind+1,1,cap,prices));
        }else {
            profit = Math.max(prices[ind]+f(ind+1,1,cap-1,prices),0+f(ind+1,0,cap,prices));
        }
        return profit;
    }
}

//Dynamic
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][k+1];
        for(int i=0;i<n;i++) {
            for (int j = 0; j < 2; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        int res = f(0,1,k,prices,dp);
        return res;
    }

    public int f(int ind, int buy, int cap, int[] prices,int[][][] dp) {
        if(ind == prices.length) {
            return 0;
        }
        if(cap == 0) {
            return 0;
        }
        if(dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }
        if(buy == 1) {
            dp[ind][buy][cap] = Math.max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }else {
            dp[ind][buy][cap] = Math.max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap];
    }
}