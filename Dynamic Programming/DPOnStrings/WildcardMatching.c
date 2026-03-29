class Solution {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();
        int[][] dp = new int[n][m];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        int res = f(n-1,m-1,s,p,dp);
        if(res == 1) {
            return true;
        }else {
            return false;
        }
    }

    public int f(int i, int j, String s, String p, int[][] dp) {
        if(j < 0 && i < 0) {
            return 1;
        }
        if(j < 0) {
            return 0;
        }
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p.charAt(k) != '*') return 0;
            }
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if((s.charAt(i) == p.charAt(j)) || p.charAt(j) == '?') {
            dp[i][j] = f(i-1,j-1,s,p,dp);
            return dp[i][j];
        }
        if (p.charAt(j) == '*') {
            if (f(i, j - 1, s, p, dp) == 1 || 
                f(i - 1, j, s, p, dp) == 1) {
                return dp[i][j] = 1;
            }
            return dp[i][j] = 0;
        }

        return dp[i][j] = 0;
    }
}