class Solution {
    public int minimumDifference(int[] nums) {
        int sum = 0;
        int n = nums.length;
        for(int num: nums) {
            sum += num;
        }
        int target = sum;
        int[][] dp = new int[n][target+1];
        for(int[] rows: dp) {
            Arrays.fill(rows, -1);
        }
        for(int t=0;t<=target;t++) {
            subsetTarget(n-1,t,nums,dp);
        }
        int minDiff = Integer.MAX_VALUE;
        for(int i=0;i<=target/2;i++) {
            if(dp[n-1][i] == 1) {
                int other = sum - i;
                minDiff = Math.min(minDiff,Math.abs(i-other));
            }
        }
        return minDiff;
    }

    public boolean subsetTarget(int ind, int target, int[] nums, int[][] dp) {
        if(target == 0) {
            return true;
        }
        if(ind == 0) {
            return nums[0] == target;
        }
        if(dp[ind][target] != -1) {
            return dp[ind][target] == 1;
        }
        boolean notTaken = subsetTarget(ind-1,target,nums,dp);
        boolean taken = false;
        if(target >= nums[ind]) {
            taken = subsetTarget(ind-1,target-nums[ind],nums,dp);
        }
        boolean ans = taken || notTaken;
        dp[ind][target] = ans ? 1 : 0;
        return ans;
    }
}