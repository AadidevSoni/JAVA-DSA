class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int max = Integer.MIN_VALUE;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
        }
        int left = 1;
        int right = max;
        int result = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            long sum = 0;
            for(int num: nums) {
                sum += (num + mid - 1) / mid;
            }
            if(sum <= threshold) {
                result = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return result;
    }
}