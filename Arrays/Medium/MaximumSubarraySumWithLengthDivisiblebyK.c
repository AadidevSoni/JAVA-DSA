class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxSum = Integer.MIN_VALUE;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                long sum = 0;
                if((j-i+1) % k == 0) {
                    for(int l=i;l<=j;l++) {
                        sum += nums[l];
                    }
                    maxSum = Math.max(sum, maxSum);
                }
            }
        }
        return maxSum;
    }
}