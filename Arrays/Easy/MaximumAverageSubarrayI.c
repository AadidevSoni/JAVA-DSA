class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double avg = Integer.MIN_VALUE;
        int n = nums.length;
        if(n < k) {
            int sum = 0;
            for(int nu: nums) {
                sum += nu;
            }
            return sum/n;
        }
        for(int i=0;i<=n-k;i++) {
            int sum = 0;
            for(int j=i;j<i+k;j++) {
                sum += nums[j];
            }
            avg = Math.max(avg, (double)sum/k);
        }
        return avg;
    }
}