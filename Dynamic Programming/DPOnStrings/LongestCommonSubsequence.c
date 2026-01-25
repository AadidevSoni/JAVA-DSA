class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int s1 = text1.length();
        int s2 = text2.length();
        int[][] dp = new int[s1][s2];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        int res = LCS(s1-1,s2-1,text1,text2,dp);
        return res;
    }

    public int LCS(int ind1, int ind2, String str1, String str2, int[][] dp) {
        if(ind1 < 0 || ind2 < 0) {
            return 0;
        } 
        if(dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if(str1.charAt(ind1) == str2.charAt(ind2)) {
            dp[ind1][ind2] = 1 + LCS(ind1-1,ind2-1,str1,str2,dp);
            return dp[ind1][ind2];
        }
        dp[ind1][ind2] = 0 + Math.max(LCS(ind1-1,ind2,str1,str2,dp), LCS(ind1,ind2-1,str1,str2,dp));
        return dp[ind1][ind2];
    }
}

//Tabulation
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int s1 = text1.length();
        int s2 = text2.length();
        int[][] dp = new int[s1+1][s2+1];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        for(int j=0;j<=s2;j++) {
            dp[0][j] = 0;
        }
        for(int i=0;i<=s1;i++) {
            dp[i][0] = 0;
        }
        for(int i=1;i<=s1;i++) {
            for(int j=1;j<=s2;j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)) { 
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = 0 + Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
}