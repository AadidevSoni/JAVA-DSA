class Solution {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
            sum += nums[i];
        }
        int low = max;
        int high = sum;
        int res = 0;
        while(low <= high) {
            int mid = (low+high)/2;
            if(isPossible(mid,nums,n,k)) {
                res = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return res;
    }

    public boolean isPossible(int mid, int[] arr, int n, int k) {
        int sum = 0;
        int part = 1;
        for(int i=0;i<n;i++) {
            if(sum + arr[i] > mid) {
                part++;
                sum = arr[i];
            }else {
                sum += arr[i];
            }
        }
        if(part <= k) {
            return true;
        }else {
            return false;
        }
    }
}