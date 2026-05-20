class Solution {

    public int calculateMaxRobAmount(int[] arr) {
        
        int n = arr.length;
        
        if(n == 1) {
            return arr[0];
        }
        
        int[] arr1 = new int[n - 1];
        int[] arr2 = new int[n - 1];
        
        int[] dp1 = new int[n];
        Arrays.fill(dp1,-1);
        int[] dp2 = new int[n];
        Arrays.fill(dp2,-1);
        
        for(int i = 0; i < n - 1; i++) {
            arr1[i] = arr[i];
        }
        
        for(int i = 1; i < n; i++) {
            arr2[i - 1] = arr[i];
        }
        
        int res1 = f(n - 2, arr1, dp1);
        int res2 = f(n - 2, arr2, dp2);
        
        return Math.max(res1, res2);
        
    }
    
    public static int f(int ind, int[] arr, int[] dp) {
        if(ind == 0) {
            return arr[ind];
        }
        if(ind < 0) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int pick = f(ind-2,arr,dp) + arr[ind];
        int notPick = f(ind-1,arr,dp) + 0;
        dp[ind] = Math.max(pick,notPick);
        return dp[ind];
    }
}
