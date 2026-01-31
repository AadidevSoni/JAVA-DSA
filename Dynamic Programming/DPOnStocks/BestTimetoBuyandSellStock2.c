//Recursion
class Solution {
    public int maxProfit(int[] prices) {
        //f(ind, buy, prices) buy=1 -  can buy
        int profit = f(0,1,prices);
        return profit;
    }

    public int f(int ind, int buy, int[] prices) {
        if(ind == prices.length) {
            return 0;
        }
        int profit = 0;
        if(buy == 1) { // buy means negative
            profit = Math.max(0+f(ind+1,1,prices),-prices[ind]+f(ind+1,0,prices));
        }else {
            profit = Math.max(0+f(ind+1,0,prices),prices[ind]+f(ind+1,1,prices));
        }
        return profit;
    }
}