package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		String S = "T|F&T";
		int n = S.length();
		int[][][] dp = new int[n][n][2];
		for(int[][] row: dp) {
			for(int[] col: row) {
				Arrays.fill(col, -1);
			}
		}
		int res = f(0,n-1,1,S,dp);
		System.out.println("No of ways to get True: " + res);
		
	}
	
	public static int f(int i, int j, int isTrue, String S, int[][][] dp) {
		if(i > j ) {
			return 0;
		}
		if(i == j) {
			if(isTrue == 1) {
				return S.charAt(i) == 'T' ? 1 : 0;
			}else {
				return S.charAt(i) == 'F' ? 1 : 0;
			}
		}
		if(dp[i][j][isTrue] != -1) {
			return dp[i][j][isTrue];
		}
		int ways = 0;
		for(int k = i+1;k<=j-1;k+=2) {
			int LT = f(i,k-1,1,S,dp);
			int LF = f(i,k-1,0,S,dp);
			int RT = f(k+1,j,1,S,dp);
			int RF = f(k+1,j,0,S,dp);
			char op = S.charAt(k);
			
			if(op == '&') {
				if(isTrue == 1) {
					ways += LT * RT;
				}else {
					ways += (LT*RT) + (LT*RF) + (LF*RT);
				}
			}else if(op == '|') {
				if(isTrue == 1) {
					ways += (LT*RT) + (LT*RF) + (LF*RT);
				}else {
					ways += LF * RF;
				}
			}else if(op == '^' ) {
				if(isTrue == 1) {
                    ways += LT*RF + RT*LF;
                }
                else {
                    ways += LT*RT + LF*RF;
                }
			}
		}
		
		return dp[i][j][isTrue] = ways;
	}
	
}
