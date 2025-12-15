class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int left = 0;
        int right = n-1;
        int min = Integer.MAX_VALUE;
        while(left < right) {
            int mid = (left + right)/2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }

        return nums[left];
    }
}