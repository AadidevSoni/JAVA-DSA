class Solution {
    public int minimumOperations(int[] nums) {
        int[] arr = new int[3];
        for(int n: nums) {
            int rem = n % 3;
            arr[rem]++;
        }
        int res = arr[1] + arr[2];
        return res;
    }
}