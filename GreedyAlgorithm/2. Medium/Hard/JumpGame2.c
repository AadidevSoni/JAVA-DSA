//Brute Force
class Solution {
    public int jump(int[] nums) {
        return minJumps(nums,0);
    }

    public static int minJumps(int[] nums, int position) {
        if(position >= nums.length - 1) {
            return 0;
        }

        if(nums[position] == 0) {
            return Integer.MAX_VALUE;
        }

        int minSteps = Integer.MAX_VALUE;

        for(int jump = 1;jump <= nums[position];jump++) {
            int subResult = minJumps(nums,position+jump);
            if(subResult != Integer.MAX_VALUE) {
                minSteps = Math.min(minSteps,subResult + 1);
            }
        }

        return minSteps;
    }
}

//DP
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];

        Arrays.fill(dp,Integer.MAX_VALUE);

        dp[0] = 0;

        for(int i=0;i<n;i++) {
            for(int j=1;j<=nums[i] && i+j < n;j++) {
                dp[i+j] = Math.min(dp[i+j],dp[i]+1);
            }
        }

        return dp[n-1];
    }
}

//Optimal
class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int jumps = 0;
        int l = 0;
        int r = 0;
        while(r < n-1) {
            int farthest = 0;
            for(int i=l;i<=r;i++) {
                farthest = Math.max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
}

