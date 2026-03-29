class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        if ((sum - target) < 0 || (sum - target) % 2 != 0)
            return 0;
        int subsetSum = (sum - target) / 2;
        int[][] dp = new int[n][subsetSum+1];
        for(int[] rows: dp) {
            Arrays.fill(rows,-1);
        }
        int ans = f(n-1,subsetSum,nums,dp);
        return ans;
    }

    public int f(int ind, int target, int[] nums, int[][] dp) {
        if(ind == 0) {
            if(target == 0 && nums[0] == 0) {
                return 2;
            }
            if(target == 0 || target == nums[0]) {
                return 1;
            }
            return 0;
        }
        if(dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int notPick = f(ind-1,target,nums,dp);
        int pick = 0;
        if(target >= nums[ind]) {
            pick = f(ind-1,target-nums[ind],nums,dp);
        }
        dp[ind][target] = pick+notPick;
        return dp[ind][target];
    }
}