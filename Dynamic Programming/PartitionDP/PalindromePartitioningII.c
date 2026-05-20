class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] pal = new boolean[n][n];
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(s.charAt(i) == s.charAt(j)) {//matching end characters
                    if(j-i <= 2 || pal[i + 1][j - 1]) {//checkign if middle characters are palindrome
                        pal[i][j] = true;
                    }
                }
            }
        }
        int[] dp = new int[n];
        Arrays.fill(dp,-1);
        int res = f(0,n,s,dp,pal);
        return res-1; //Number of cuts = number of partitions - 1
    }

    public int f(int i, int n, String s, int[] dp, boolean[][] pal) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        String temp = "";
        int minCost = Integer.MAX_VALUE;
        for(int j=i;j<n;j++) {
            temp += s.charAt(j);
            if(pal[i][j]) {
                int cost = 1 + f(j+1, n, s, dp, pal);
                minCost = Math.min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
}

//TLE
class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        Arrays.fill(dp,-1);
        int res = f(0,n,s,dp);
        return res-1; //Number of cuts = number of partitions - 1
    }

    public int f(int i, int n, String s, int[] dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        String temp = "";
        int minCost = Integer.MAX_VALUE;
        for(int j=i;j<n;j++) {
            temp += s.charAt(j);
            if(isPalindrome(temp)) {
                int cost = 1 + f(j+1,n,s,dp);
                minCost = Math.min(cost,minCost);
            }
        }
        return dp[i] = minCost;
    }

    public boolean isPalindrome(String s) {
        int i = 0;
        int n = s.length();
        int j = n-1;
        while(i < j) {
            if(s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            }else {
                return false;
            }
        }
        return true;
    }
}