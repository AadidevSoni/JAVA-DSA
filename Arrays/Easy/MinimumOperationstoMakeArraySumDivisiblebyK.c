class Solution {
    public int minOperations(int[] nums, int k) {
        int s = 0;
        for(int n: nums) {
            s += n;
        }
        return (s % k);
    }
}