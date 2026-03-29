class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] count = new int[n];
        Arrays.fill(count, 1);
        Arrays.fill(dp,1);
        int maxLen = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i] && dp[j]+1>dp[i]) {
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }else if(dp[j]+1 == dp[i]) {
                    count[i] += count[j];
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        int c = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] == maxLen) {
                c += count[i];
            }
        }
        return c;
    }
}