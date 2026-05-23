class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0;
        int n = nums.length;
        int right = n-1;
        while(left < right) {
            int mid = (left + right)/2;
            if(mid%2 == 1) {
                mid--;
            }

            if(nums[mid] == nums[mid+1]) {
                left = mid+2;
            }else {
                right = mid;
            }
        }
        return nums[left];
    }
}

//Striver 
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n == 1) {
            return nums[0];
        }
        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }
        int low = 1;
        int high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) {
                return nums[mid];
            }
            if(mid%2 == 1 && nums[mid-1] == nums[mid] || mid%2 == 0 && nums[mid+1] == nums[mid]) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return -1;
    }
}