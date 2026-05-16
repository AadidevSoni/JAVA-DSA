package DynamicProgramming;

public class frogKJumps {

	public static void main(String[] args) {
		
		int[] arr = {10,5,20,0,15};
		int n = arr.length;
		int k = 2;
		int res = jump(n-1,k,arr);
		System.out.println("Min Jumps: " + res);
	}
	
	public static int jump(int n, int k, int[] arr) {
		if(n == 0) {
			return 0;
		}
		int minSteps = Integer.MAX_VALUE;
		for(int i=1;i<=k;i++) {
			if((n-i) >= 0) {
				int step = jump(n-i,k,arr) + Math.abs(arr[n] - arr[n-i]);
				minSteps = Math.min(minSteps, step);
			}
		}
		return minSteps;
	}

}

//DP 

package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {10,5,20,0,15};
		int n = arr.length;
		int k = 2;
		int[] dp = new int[n+1];
		Arrays.fill(dp, -1);
		int res = jump(n-1,k,arr,dp);
		System.out.println("Min Jumps: " + res);
		
	}
	
	public static int jump(int ind, int k, int[] arr,int[] dp) {
		if(ind == 0) {
			return 0;
		}
		
		if(dp[ind] != -1) {
			return dp[ind];
		}
		
		int minSteps = Integer.MAX_VALUE;
		for(int i=1;i<=k;i++) {
			if((ind-i) >= 0) {
				int steps = jump(ind-i,k,arr,dp) + Math.abs(arr[ind] - arr[ind-i]);
				minSteps = Math.min(steps, minSteps);
			}
		}
		
		dp[ind] =  minSteps;
		return dp[ind];
	}
	
}

//Tabulation

package Arrays;

import java.util.*;

public class Practice {
	
	public static void main(String[] args) {
		
		int[] arr = {10,5,20,0,15};
		int n = arr.length;
		int k = 2;
		int res = jump(n-1,k,arr);
		System.out.println("Min Jumps: " + res);
		
	}
	
	public static int jump(int ind, int k, int[] arr) {
		
		int[] dp = new int[arr.length+1];
		Arrays.fill(dp, -1);
		
		dp[0] = 0;
		
		for(int i=1;i<=ind;i++) {
			int minSteps = Integer.MAX_VALUE;
			for(int j=1;j<=k;j++) {
				if(i-j >= 0) {
					int steps = dp[i-j] + Math.abs(arr[i]-arr[i-j]);
					dp[i] = Math.min(minSteps,steps);
				}
			}
		}
		
		return dp[ind];
	}
	
}

