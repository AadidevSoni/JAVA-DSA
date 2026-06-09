class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        int x = 0;
        int y = sum;
        for(int i=0;i<n;i++) {
            y -= nums[i];
            res[i] = Math.abs(y - x);
            x += nums[i];
        }
        return res;
    }
}