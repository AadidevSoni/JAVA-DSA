class Solution {
    public int longestSubarray(int[] nums) {
        int count = 0;
        int n = nums.length;
        int max = 0;
        int left = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                count++;
            }
            if(count > 1) {
                while(count > 1) {
                    if(nums[left] == 0) {
                        count--;
                    }
                    left++;
                }
            }
            max = Math.max(max,i-left);
        }
        return max;
    }
}