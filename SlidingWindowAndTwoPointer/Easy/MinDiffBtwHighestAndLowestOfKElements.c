class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        if(n == 1) {
            return 0;
        }
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<=n-k;i++) {
            ans = Math.min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
}