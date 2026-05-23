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

//Striver
class Solution {
    public int findMin(int[] nums) {
        int min = Integer.MAX_VALUE;
        int n = nums.length;
        int low = 0;
        int high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[low] <= nums[mid]) {
                min = Math.min(min, nums[low]);
                low = mid+1;
            }else {
                min = Math.min(nums[mid],min);
                high = mid;
            }
        }
        return min;
    }
}