class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int curr = 0;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(nums[i] == 1) {
                curr++;
            }else{
                curr = 0;
            }
            if(curr > max) {
                max = curr;
            }
        }
        return max;
    }
}