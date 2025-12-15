class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        int first = -1;
        int last = -1;
        int n = nums.length;

        int left1 = 0;
        int right1 = n-1;
        while(left1 <= right1) {
            int mid = (left1 + right1)/2;
            if(nums[mid] == target) {
                first = mid;
                right1 = mid-1;
            }else if(nums[mid] < target) {
                left1 = mid+1;
            }else {
                right1 = mid-1;
            }
        }

        int left2 = 0;
        int right2 = n-1;
        while(left2 <= right2) {
            int mid = (left2 + right2)/2;
            if(nums[mid] == target) {
                last = mid;
                left2 = mid+1;
            }else if(nums[mid] < target) {
                left2 = mid+1;
            }else {
                right2 = mid-1;
            }
        }

        ans[0] = first;
        ans[1] = last;
        return ans;
    }
}