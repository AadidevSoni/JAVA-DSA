import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		while(T-- > 0) {
		    int n = scanner.nextInt();
		    int[][] triangle = new int[n][n];
		    int[][] dp = new int[n][n];
		    for(int[] rows: dp) {
		        Arrays.fill(rows, -1);
		    }
		    for(int i=0;i<n;i++) {
		        for(int j=0;j<=i;j++) {
		            triangle[i][j] = scanner.nextInt();
		        }
		    }
		    System.out.println(f(0,0,triangle,n,dp));
		}
	}
	
	public static int f(int i, int j, int[][] triangle, int n, int[][] dp) {
	    if(i == n-1) {
	        return(triangle[i][j]);
	    }
	    if(dp[i][j] != -1) {
	        return dp[i][j];
	    }
	    int down = f(i+1,j,triangle,n,dp) + triangle[i][j];
	    int diagonal = f(i+1,j+1,triangle,n,dp) + triangle[i][j];
	    dp[i][j] = Math.max(down,diagonal);
	    return dp[i][j];
	}
}
