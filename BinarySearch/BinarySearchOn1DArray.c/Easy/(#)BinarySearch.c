class Solution {
    public int search(int[] nums, int target) {
        int low = 0;
        int n = nums.length;
        int high = n-1;
        while(low <= high) {
            int mid = (high + low)/2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid]) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return -1;
    }
}