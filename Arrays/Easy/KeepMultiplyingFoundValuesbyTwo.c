class Solution {
    public int findFinalValue(int[] nums, int original) {
        int n = nums.length;
        int found = 1;
        while(found == 1) {
            found = 0;
            for(int i=0;i<n;i++) {
                if(nums[i] == original) {
                    original *= 2;
                    found = 1;
                    break;
                }
            }
        }
        return original;
    }
}