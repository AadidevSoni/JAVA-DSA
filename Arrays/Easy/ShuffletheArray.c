class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[2*n];
        int indx = 0;
        for(int i=0;i<n;i++) {
            ans[indx++] = nums[i];
            ans[indx++] = nums[n+i];
        }    
        return ans;
    }
}