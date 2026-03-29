class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(prev,-1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        int maxVal = Integer.MIN_VALUE;
        int maxIndex = -1;
        for(int i=0;i<n;i++) {
            if(dp[i] > maxVal) {
                maxVal = dp[i];
                maxIndex = i;
            }
        }

        List<Integer> lst = new ArrayList<>();
        int idx = maxIndex;
        while(idx != -1) {
            lst.add(nums[idx]);
            idx = prev[idx];
        }
        Collections.sort(lst);
        return lst;
    }
}