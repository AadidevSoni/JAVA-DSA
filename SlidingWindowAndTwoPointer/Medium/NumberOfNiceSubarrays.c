class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int num1 = func(nums,k);
        int num2 = func(nums,k-1);
        return(num1-num2);
    }

    public static int func(int[] nums, int k) {
        if(k < 0) {
            return 0;
        }
        int count = 0;
        int l = 0;
        int r = 0;
        int n = nums.length;
        int max = 0;
        while(r<n) {
            count += nums[r] % 2;
            while(count > k) {
                count -= nums[l] % 2;
                l++;
            }
            max += r-l+1;
            r++;
        }
        return max;
    }
}