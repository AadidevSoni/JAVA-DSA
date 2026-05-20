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
		int res = f(1,n-1,matrix,dp);
		System.out.println("Minimum cost: " + res);
		
	}
	
	public static int f(int i, int j, int[] matrix,int[][] dp) {
		if(i == j) {
			return 0;
		}
		if(dp[i][j] != -1) {
			return dp[i][j];
		}
		int min = Integer.MAX_VALUE;
		for(int k=i;k<j;k++) {
			int cost = matrix[i-1] * matrix[k] * matrix[j] + f(i,k,matrix,dp) + f(k+1,j,matrix,dp);
			min = Math.min(min, cost);
		}
		return dp[i][j] = min;
 	}
	
}
