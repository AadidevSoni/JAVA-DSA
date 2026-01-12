//Brute Force
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int num = 0;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=i;j<n;j++) {
                sum += nums[j];
                if(sum == goal) {
                    num++;
                }
            }
        }
        return num;
    }
}

//Optimal
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int num1 = func(nums,goal);
        int num2 = func(nums,goal-1);
        return (num1 - num2);
    }

    public static int func(int[] nums, int goal) {
        if(goal < 0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;
        int n = nums.length;
        while(r < n) {
            sum += nums[r];
            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r-l+1); //You must add the length of the subarray till rth element to get all subarrays possible
            r++;
        }
        return count;
    }
}