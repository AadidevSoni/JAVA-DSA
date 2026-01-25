package entity;

import java.util.Arrays;

public class Practice {

	public static void main(String[] args) {
		
		int[] arr = {1,2,3,4};
		int target = 5;
		int n = arr.length;
		int[][] dp = new int[n][target+1];
		for(int[] rows: dp) {
			Arrays.fill(rows, -1);
		}
		boolean res = f(n-1,target,arr,dp);
		System.out.println(res);
	}
	
	public static boolean f(int ind, int target,int[] arr, int[][] dp) {
		if(target == 0) {
			return true;
		}
		if(ind == 0) {
			return(arr[0] == target);
		}
		if (dp[ind][target] != -1) {
            return dp[ind][target] == 1;
        }
		boolean notTaken = f(ind-1,target,arr,dp);
		boolean taken = false;
		if(target >= arr[ind]) {
			taken = f(ind-1,target-arr[ind],arr,dp);
		}
		boolean ans = taken || notTaken;
		dp[ind][target] = ans ? 1 : 0;
		return ans;
	}

}


public boolean f(int ind, int target, int[] nums) {
        if(target == 0) {
            return true;
        }
        if(ind == 0) {
            return(nums[0] == target);
        }
        boolean notTaken = f(ind-1,target,nums);
        boolean taken = false;
        if(target >= nums[ind]) {
            taken = f(ind-1,target-nums[ind],nums);
        }
        return(taken || notTaken);
    }