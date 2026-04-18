class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int tracker = 0;
        int lptr = 0;
        int rptr = 0;
        if(start == 0) {
            lptr = -1;
        }else {
            lptr = start-1;
        }
        if(start == n-1) {
            rptr = -1;
        }else {
            rptr = start+1;
        }
        int min = Integer.MAX_VALUE;
        if(nums[start] == target) {
            return 0;
        }
        while(tracker == 0) {
            if(lptr != -1) {
                if(nums[lptr] == target) {
                    min = Math.abs(lptr - start);
                    tracker++;
                }else {
                    lptr--;
                }
            }
            if(rptr <= n-1 && rptr != -1) {
                if(nums[rptr] == target) {
                    min = Math.abs(rptr - start);
                    tracker++;
                }else {
                    rptr++;
                }
            }
        }
        return min;
    }
}