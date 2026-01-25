class Solution {
    public int minInsertions(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int length = LPS(n-1,n-1,s,rev,dp);
        return n - length;
    }

    public int LPS(int ind1,int ind2, String s1, String s2, int[][] dp) {
        if(ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if(s1.charAt(ind1) == s2.charAt(ind2)) {
            dp[ind1][ind2] = 1 + LPS(ind1-1,ind2-1,s1,s2,dp);
            return dp[ind1][ind2];
        }
        dp[ind1][ind2] = 0 + Math.max(LPS(ind1-1,ind2,s1,s2,dp),LPS(ind1,ind2-1,s1,s2,dp));
        return dp[ind1][ind2];
    }
}