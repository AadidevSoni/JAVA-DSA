class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int dp0 = arr[0]; //no deletions
        int dp1 = 0;
        int ans = arr[0];
        for(int i=1;i<n;i++) {
            dp1 = Math.max(dp0,dp1+arr[i]);
            dp0 = Math.max(arr[i],dp0+arr[i]);
            ans = Math.max(ans, Math.max(dp0,dp1));
        }
        return ans;
    }
}