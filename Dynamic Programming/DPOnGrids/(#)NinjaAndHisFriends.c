package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[][] grid = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};
		int n = grid.length;
		int m = grid[0].length;
		int[][][] dp = new int[n][m][m];
		for (int[][] layer : dp) {
		    for (int[] row : layer) {
		        Arrays.fill(row, -1);
		    }
		}
		int res = f(0,0,0,m-1,grid,m,n,dp);
		System.out.println("Max chocolates: " + res);
		
	}
	
	public static int f(int i1, int j1, int i2, int j2, int[][] grid, int m, int n, int[][][] dp) {
		if(j1 < 0 || j1 >=m || j2 < 0 || j2 >= m) {
			return -9999;
		}
		if(i1 == n-1) {
			if(j1 == j2) { //Alice and bob ends on the same cell then return only one
				return grid[i1][j1];
			}else {
				return grid[i1][j1] + grid[i2][j2];
			}
		}
		if(dp[i1][j1][j2] != -1) {
			return dp[i1][j1][j2];
		}
		int max = 0;
		//9 paths possible as for every path alice takes, bob can take any of the other 3 paths
		for(int i=-1;i<=1;i++) {
			for(int j=-1;j<=1;j++) {
				if(j1 == j2) {
					max = Math.max(max, grid[i1][j1] + f(i1+1,j1+i,i2+1,j2+j,grid,m,n,dp));
				}else {
					max = Math.max(max, grid[i1][j1] + grid[i2][j2] + f(i1+1,j1+i,i2+1,j2+j,grid,m,n,dp));
				}
			}
		}
		dp[i1][j1][j2] = max;
		return dp[i1][j1][j2];
	}
	
}
