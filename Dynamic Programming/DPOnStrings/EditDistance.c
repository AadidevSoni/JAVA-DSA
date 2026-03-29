class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int[][] dp = new int[n][m];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        int res = f(n-1,m-1,word1,word2,dp);
        return res;
    }
    public int f(int i, int j, String word1, String word2, int[][] dp) {
        if(i < 0) {
            return j+1;
        }
        if(j < 0) {
            return i+1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(word1.charAt(i) == word2.charAt(j)) {
            return 0 + f(i-1,j-1,word1,word2,dp);
        }
        dp[i][j] = 1 + Math.min(f(i-1,j,word1,word2,dp), Math.min(f(i,j-1,word1,word2,dp), f(i-1,j-1,word1,word2,dp)));
        return(dp[i][j]);
    }
}