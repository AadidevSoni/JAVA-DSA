class Solution {
    public int[] countOppositeParity(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        for(int i=0;i<n;i++) {
            int parity = nums[i]%2;
            int count = 0;
            for(int j=i+1;j<n;j++) {
                if(nums[j] % 2 != parity) {
                    count++;
                }
            }
            res[i] = count;
        }
        return res;
    }
}