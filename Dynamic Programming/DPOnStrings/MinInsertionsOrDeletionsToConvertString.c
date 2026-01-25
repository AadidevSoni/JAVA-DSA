class Solution {
    public int minDistance(String word1, String word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int[][] dp = new int[l1][l2];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int commonLength = LCS(l1-1,l2-1,word1,word2,dp);
        int deletions = l1 - commonLength;
        int insertions = l2 - commonLength;
        return(deletions + insertions);
    }

    public int LCS(int ind1, int ind2, String word1, String word2, int[][] dp) {
        if(ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        } 
        if(word1.charAt(ind1) == word2.charAt(ind2)) {
            dp[ind1][ind2] = 1 + LCS(ind1-1,ind2-1,word1,word2,dp);
            return dp[ind1][ind2];
        }
        dp[ind1][ind2] = 0 + Math.max(LCS(ind1-1,ind2,word1,word2,dp),LCS(ind1,ind2-1,word1,word2,dp));
        return dp[ind1][ind2];
    }
}