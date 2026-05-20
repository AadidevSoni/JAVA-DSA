class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        int res = decode(0,n,s,dp);
        return res;
    }

    public int decode(int ind, int n, String s, int[] dp) {
        if(ind == n) {
            return 1;
        }
        if(s.charAt(ind) == '0') {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int ways = decode(ind+1,n,s,dp);
        if(ind+1 < n) {
            int num = (s.charAt(ind)-'0') * 10 + s.charAt(ind+1)-'0';
            if(num >= 10 && num <= 26) {
                ways += decode(ind+2,n,s,dp);
            }
        }
        return dp[ind] = ways;
    }
}