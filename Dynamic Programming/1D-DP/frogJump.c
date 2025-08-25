package DynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class frogJump {

	public static void main(String[] args) {
		
		//Memorization
		int[] arr = {30,10,40,50,20,50};
		int n = arr.length;
		List<Integer> dp = new ArrayList<>(Collections.nCopies(n+1, -1));
		int res = jump(n-1,arr,dp);
		System.out.println("Min Jumps: " + res);
		
		//Tabulation
		int res1 = jump1(n-1,arr);
		System.out.println("Min Jumps: " + res1);
		
		//Tabulation non array
		int res2 = jump2(n-1,arr);
		System.out.println("Min Jumps: " + res2);

	}
	
	public static int jump(int n, int[] arr, List<Integer> dp) {
		if(n == 0) {
			return 0;
		}
		if(dp.get(n) != -1) return dp.get(n);
		int right = Integer.MAX_VALUE;
		int left = jump(n-1,arr,dp) + Math.abs(arr[n] - arr[n-1]);
		if(n > 1) {
			right = jump(n-2,arr,dp) + Math.abs(arr[n] - arr[n-2]);
		}
		int res = Math.min(left, right);
		dp.set(n, res);
		return res;
	}
	
	public static int jump1(int n, int[] arr) {
		List<Integer> dp = new ArrayList<>(Collections.nCopies(n+1, -1));
		dp.set(0, 0);	
		
		for(int i=1;i<=n;i++) {
			int left = dp.get(i - 1) + Math.abs(arr[i] - arr[i - 1]);
	        int right = Integer.MAX_VALUE;
	        if (i > 1) {
	            right = dp.get(i - 2) + Math.abs(arr[i] - arr[i - 2]);
	        }
	        dp.set(i, Math.min(left, right));
		}
		return(dp.get(n));
	}
	
	public static int jump2(int n, int[] arr) {
		int prev1 = 0;
		int prev2 = 0;
		for(int i=1;i<=n;i++) {
			int  left = prev2 + Math.abs(arr[i] - arr[i-1]);
			int right = Integer.MAX_VALUE;
			if(i>1) {
				right = prev1 + Math.abs(arr[i] - arr[i-2]);
			}
			int curr = Math.min(left, right);
			prev1 = prev2;
			prev2 = curr;
		}
		return prev2; //curr goes beyond index
	}

}
