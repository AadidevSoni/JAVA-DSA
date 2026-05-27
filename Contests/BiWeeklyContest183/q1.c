class Solution {
    public int minimumSwaps(int[] nums) {
        int n = nums.length;
        int zeros = 0;
        for(int num: nums) {
            if(num == 0) {
                zeros++;
            }
        }
        int swaps = 0;
        for(int i=n-zeros;i<n;i++) {
            if(nums[i] != 0) {
                swaps++;
            }
        }
        return swaps;
    }
}