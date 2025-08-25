package DynamicProgramming;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class HouseRobber2 {

	public static void main(String[] args) {
		
		//Memorization
		
		int[] nums = {1,2,3,1,2,3,4,7};
		int n = nums.length;
        if(n==1) {
            System.out.println("Max money: " + nums[0]);
        }
        
        List<Integer> dp1 = new ArrayList<>(Collections.nCopies(n+1,-1));
        List<Integer> dp2 = new ArrayList<>(Collections.nCopies(n+1,-1));
        
        //We create two copies of nums array one without first element and one without last elements
        //This is because since the houses are in a circular street, the first and last element will never be there together
        int[] temp1 = Arrays.copyOfRange(nums, 1, n);
        int[] temp2 = Arrays.copyOfRange(nums, 0, n - 1);

        int res1 = rob(temp1.length-1,temp1,dp1);
        int res2 = rob(temp2.length-1,temp2,dp2);

        int res = Math.max(res1,res2);
        System.out.println("Max money: " + res);
        
        //Tabulation
        
        if(n==1) {
            System.out.println("Max money: " + nums[0]);
        }
        
        int[] temp3 = Arrays.copyOfRange(nums, 1, n);
        int[] temp4 = Arrays.copyOfRange(nums, 0, n - 1);

        int res3 = rob(temp3.length-1,temp3);
        int res4 = rob(temp4.length-1,temp4);

        int result = Math.max(res3,res4);
        System.out.println("Max money: " + result);
        
        //Space Optimization
        
        if(n==1) {
            System.out.println("Max money: " + nums[0]);
        }
        
        int[] temp5 = Arrays.copyOfRange(nums, 1, n);
        int[] temp6 = Arrays.copyOfRange(nums, 0, n - 1);

        int res5 = rob1(temp5.length-1,temp5);
        int res6 = rob1(temp6.length-1,temp6);

        int result1 = Math.max(res5,res6);
        System.out.println("Max money: " + result1);
        
        

	}
	
	public static int rob(int n, int[] nums, List<Integer> dp) {
        if(n == 0) {
            return(nums[0]);
        }
        if(n<0) {
            return 0;
        }
        if(dp.get(n) != -1) return dp.get(n);
        int pick = nums[n] + rob(n-2,nums,dp);
        int notPick = rob(n-1,nums,dp);
        int res = Math.max(pick,notPick);
        dp.set(n,res);
        return res;
    }
	
	public static int rob(int n, int[] nums) {
		List<Integer> dp = new ArrayList<>(Collections.nCopies(n+1, -1));
        dp.set(0, nums[0]);
        if(n<0) {
            return 0;
        }
        for(int i=1;i<=n;i++) {
        	int pick = nums[i];
        	if(i > 1) {
        		pick += dp.get(i-2);
        	}
        	int notPick = dp.get(i-1);
        	dp.set(i, Math.max(pick, notPick));
        }
        return(dp.get(n));
    }
	
	public static int rob1(int n, int[] nums) {
		int prev1 = 0;
		int prev2 = nums[0];
        for(int i=1;i<=n;i++) {
        	int pick = nums[i];
        	if(i > 1) {
        		pick += prev1;
        	}
        	int notPick = prev2;
        	int curr = Math.max(pick, notPick);
        	prev1 = prev2;
        	prev2 = curr;
        }
        return prev2;
    }

}
