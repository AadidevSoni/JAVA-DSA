class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i+1] < nums[i])) {
                return i;
            }
        }
        return -1;
    }
}

//Binary Seacrh Approach
class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0;
        int n = nums.length;
        int right = n-1;

        while(left <= right) {
            int mid = (left + right)/2;

            if(isPeak(mid,nums)) {
                return mid;
            }else {
                if(mid==0 || nums[mid-1] < nums[mid]) {
                    left = mid+1;
                }else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
    
    public boolean isPeak(int mid, int[] nums) {
        int n = nums.length;
        if((mid==0 || nums[mid-1] < nums[mid]) && (mid==n-1 || nums[mid+1] < nums[mid])) {
            return true;
        }else {
            return false;
        }
    }
}