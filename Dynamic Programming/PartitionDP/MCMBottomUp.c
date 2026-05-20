package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] matrix = {10,20,30,40,50};
		int n = matrix.length;
		int[][] dp = new int[n][n];
		for(int[] rows: dp) {
			Arrays.fill(rows, -1);
		}
		//BASE CASE
		for(int i=1;i<=n-1;i++) {
			dp[i][i] = 0;
		}
		//RECURSION BUT I IS IN OPPOSITE DIRECTION AND J STARTS AFTER I
		for(int i=n-1;i>=1;i--) {
			for(int j=i+1;j<n;j++) {
				int min = Integer.MAX_VALUE;
				for(int k=i;k<j;k++) {
					int cost = matrix[i-1] * matrix[k] * matrix[j] + dp[i][k] + dp[k+1][j];
					min = Math.min(min, cost);
				}
				dp[i][j] = min;
			}
		}
		System.out.println("Minimum cost: " + dp[1][n-1]);
		
	}
	
}
