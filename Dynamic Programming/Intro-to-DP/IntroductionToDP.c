package DynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class IntroductionToDP {

	public static void main(String[] args) {
		
		//Memorization
		int n = 8;
		List<Integer> dp = new ArrayList<>(Collections.nCopies(n + 1, -1));
		int res = fib(n,dp);
		System.out.println(res);
		
		//Tabulation with SC=O(N)
		int n1 = 8;
		int res1 = fibTab1(n1);
		System.out.println(res1);
		
		//Tabulation with SC=O(1)
		int n2 = 8;
		int res2 = fibTab2(n2);
		System.out.println(res2);
	}
	
	public static int fib(int n, List<Integer> dp) {
		if(n <= 1) return n;
		if(dp.get(n)!= -1) return dp.get(n);
		
		int result = fib(n-1,dp) + fib(n-2,dp);
		dp.set(n, result);
		return result;
	}
	
	public static int fibTab1(int n) {
		int[] dp = new int[n+1];
		//Base case to required
		dp[0] = 0;
		dp[1] = 1;
		for(int i=2;i<n+1;i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}
	
	public static int fibTab2(int n) {
		int prev2 = 0;
		int prev = 1;
		int curr = 0;
		for(int i=2;i<=n;i++) {
			curr = prev + prev2;
			prev2 = prev;
			prev = curr;
		}
		return curr;
	}
	

}
