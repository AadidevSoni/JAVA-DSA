package DynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HouseRobber1 {

	public static void main(String[] args) {
		
		//Memorization
		int nums[] = {2,7,9,3,1};
		int n = nums.length;
        List<Integer> dp = new ArrayList<>(Collections.nCopies(n+1,-1));
        int res = rob(n-1,nums,dp);
        System.out.println("Max money: " + res);
        
        //Tabulation
        int res1 = rob1(n-1,nums);
        System.out.println("Max money: " + res1);
        
        //Space Optimization
        int res2 = rob2(n-1,nums);
        System.out.println("Max money: " + res2);

	}
	
	public static int rob(int n, int[] nums, List<Integer> dp) {
        if(n == 0) {
            return(nums[n]);
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
	
	public static int rob1(int n, int[] nums) {
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
        return dp.get(n);
    }
	
	public static int rob2(int n, int[] nums) {
		int prev1 = 0;
		int prev2 = nums[0];
        for(int i=1;i<=n;i++) {
        	int pick = nums[i];
        	if(i > 1) {
        		pick += prev1;
        	}
        	int notPick = prev1;
        	int curr = Math.max(pick, notPick);
        	prev1 = prev2;
        	prev2 =  curr;
        }
        return prev2;
    }

}
