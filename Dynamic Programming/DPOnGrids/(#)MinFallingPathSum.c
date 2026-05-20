class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        int minSum = Integer.MAX_VALUE;
        for(int i=0;i<m;i++) {
            minSum = Math.min(minSum, dfs(0,i,matrix,dp));
        }

        return minSum;
    }

    public int dfs(int i, int j, int[][] matrix, int[][] dp) {
        if(j < 0 || j > matrix[0].length-1) {
            return Integer.MAX_VALUE;
        }
        if(i == matrix.length-1) {
            return matrix[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int downLeft = dfs(i+1,j-1,matrix,dp);
        int down = dfs(i+1,j,matrix,dp);
        int downRight = dfs(i+1,j+1,matrix,dp);
        int ans = matrix[i][j] + Math.min(downLeft, (Math.min(down, downRight)));

        dp[i][j] = ans;
        return dp[i][j];
    }
}

//optimized
import java.util.*;

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);

        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            minSum = Math.min(minSum, dfs(0, j, matrix, dp));
        }

        return minSum;
    }

    public int dfs(int i, int j, int[][] matrix, int[][] dp) {
        if (j < 0 || j >= matrix[0].length) return (int)1e9;

        if (i == matrix.length - 1) return matrix[i][j];

        if (dp[i][j] != Integer.MAX_VALUE) return dp[i][j];

        int downLeft = dfs(i + 1, j - 1, matrix, dp);
        int down = dfs(i + 1, j, matrix, dp);
        int downRight = dfs(i + 1, j + 1, matrix, dp);

        dp[i][j] = matrix[i][j] + Math.min(downLeft, Math.min(down, downRight));
        return dp[i][j];
    }
}
