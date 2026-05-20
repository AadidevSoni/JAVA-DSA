class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int sum = 0;
        int[][] dp = new int[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                }else {
                    if(i > 0 && j > 0) {
                        int n1 = dp[i-1][j];
                        int n2 = dp[i][j-1];
                        int n3 = dp[i-1][j-1];
                        int min = Math.min(n1,Math.min(n2,n3));
                        dp[i][j] = min+1;
                    }else {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
}