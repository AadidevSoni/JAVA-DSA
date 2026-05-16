package DynamicProgramming;

public class ClimbingStairs {

	public static void main(String[] args) {
		
		// Count the total number of ways
		// Try all possible ways
		// Give min or max output then we have to use recursion and hence DP
		
		//Shortcut
		//Represent problem in terms of index
		// Do all possible stuffs on that index as per problem statement
		// Sum up all stuffs if to count all ways
		// min of all stuffs to find minimum
		
		int n=5;
		int res = climb(n);
		System.out.println("No of ways to climb 10 stairs: " + res);

	}
	
	public static int climb(int nn) {
		int prev1 = 1;
        int prev2 = 1;
        int curr = 1;
        for(int i=2;i<=nn;i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
	}

}

//Recursion 

class Solution {
    public int climbStairs(int n) {
        int res = f(n);
        return res;
    }

    public int f(int ind) {
        if(ind == 0) {
            return 1;
        }
        if(ind == 1) {
            return 1;
        }
        int left = f(ind-1);
        int right = f(ind-2);
        return left+right;
    }
}

//DP 

class Solution {
    public int climbStairs(int n) {
        int dp[] = new int[n+1];

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
}
