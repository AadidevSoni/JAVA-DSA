class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        int left = 0;
        int right = sum;
        for(int i=0;i<n;i++) {
            right -= nums[i];
            if(left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
}