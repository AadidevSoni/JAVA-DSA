class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }
        if(sum%2 == 1) {
            return false;
        }
        int target = sum/2;
        int[][] dp = new int[n][target+1];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        boolean res = f(n-1,target,nums,dp);
        return res;
    }

    public boolean f(int ind, int target, int[] nums, int[][] dp) {
        if(target == 0) {
            return true;
        }
        if(ind == 0) {
            return(nums[0] == target);
        }
        if(dp[ind][target] != -1) {
            return dp[ind][target] == 1;
        }
        boolean notTaken = f(ind-1,target,nums,dp);
        boolean taken = false;
        if(target >= nums[ind]) {
            taken = f(ind-1,target-nums[ind],nums,dp);
        }
        boolean ans = taken || notTaken;
        dp[ind][target] = ans ? 1:0;
        return ans;
    }
}