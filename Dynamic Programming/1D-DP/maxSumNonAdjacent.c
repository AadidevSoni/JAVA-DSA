package DynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaxSumNonAdjacent {

	public static void main(String[] args) {
		
		//Recursive
		int[] arr = {100,200,2,3,300,500};
		int n = arr.length;
		int res = maxSum(n-1,arr);
		System.out.println("Max sum of non adjacent elements: " + res);
		
		//Memorization
		List<Integer> ds = new ArrayList<>(Collections.nCopies(n+1, -1));
		int res1 = maxSum1(n-1,arr,ds);
		System.out.println("Max sum of non adjacent elements: " + res1);
		
		//Tabulation
		int res2 = maxSum2(n-1,arr);
		System.out.println("Max sum of non adjacent elements: " + res2);
		
		//Space optimization
		int res3 = maxSum3(n-1,arr);
		System.out.println("Max sum of non adjacent elements: " + res3);

	}
	
	public static int maxSum(int n, int[] arr) {
		if(n == 0) {
			return arr[n];
		}
		if(n < 0) {
			return 0;
		}
		int pick = arr[n] + maxSum(n-2,arr);
		int notPick = 0 + maxSum(n-1,arr);
		return (Math.max(pick,notPick));
	}
	
	public static int maxSum1(int n, int[] arr, List<Integer> ds) {
		if(n == 0) {
			return arr[n];
		}
		if(n < 0) {
			return 0;
		}
		if(ds.get(n) != -1) return ds.get(n);
		int pick = arr[n] + maxSum(n-2,arr);
		int notPick = 0 + maxSum(n-1,arr);
		int result = Math.max(pick,notPick);
		ds.set(n, result);
		return (result);
	}
	
	public static int maxSum2(int n, int[] arr) {
		List<Integer> dp = new ArrayList<>(Collections.nCopies(n+1, -1));
		dp.set(0, arr[0]);
		
		for (int i = 1; i <= n; i++) {
            int pick = arr[i];
            if (i > 1) pick += dp.get(i - 2);
            int notPick = dp.get(i - 1);
            dp.set(i, Math.max(pick, notPick));
        }
        return dp.get(n);
	}
	
	public static int maxSum3(int n, int[] arr) {
		int prev1 = 0;
		int prev2 = 0;
		
		for (int i = 1; i <= n; i++) {
            int pick = arr[i];
            if (i > 1) pick += prev1;
            int notPick = prev2;
            int curr = Math.max(pick, notPick);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
	}

}
