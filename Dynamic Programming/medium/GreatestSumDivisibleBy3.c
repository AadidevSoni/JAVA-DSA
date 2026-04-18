//TLE
class Solution {
    public int maxSumDivThree(int[] nums) {
        int n = nums.length;
        int[] res = new int[1];
        res[0] = 0;
        checkSum(nums, 0, 0, n, res);
        return res[0];
    }

    public void checkSum(int[] nums, int sum, int index, int n, int[] res) {
        if(index == n) {
            if(sum % 3 == 0 && sum > res[0]) {
                res[0] = sum;
            } 
            return;
        }
        checkSum(nums,sum+nums[index],index+1,n,res);
        checkSum(nums,sum,index+1,n,res);
    }
}

//Optimal

class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[3];
        int n = nums.length;
        for(int i=0;i<n;i++) {
            int[] temp = dp.clone();
            for(int j=0;j<3;j++) {
                int newSum = temp[j] + nums[i];
                int r = newSum % 3; 
                dp[r] = Math.max(dp[r],newSum);
            }
        }
        return dp[0];
    }
}