class Solution {
    public int longestPalindromeSubseq(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int res = LCS(n-1,n-1,s,rev,dp);
        return res;
    }

    public int LCS(int ind1, int ind2, String s1, String s2, int[][] dp) {
        if(ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if(s1.charAt(ind1) == s2.charAt(ind2)) {
            dp[ind1][ind2] = 1 + LCS(ind1-1,ind2-1,s1,s2,dp);
            return dp[ind1][ind2];
        }
        dp[ind1][ind2] = 0 + Math.max(LCS(ind1-1,ind2,s1,s2,dp),LCS(ind1,ind2-1,s1,s2,dp));
        return dp[ind1][ind2];
    }
}