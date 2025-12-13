//Bad version but works for any order of numbers
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] ans = new int[2];
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(nums[i] == nums[j]) {
                    ans[0] = nums[i];
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            int isThere = 0;
            for(int j=0;j<n;j++) {
                if(nums[j] == i) {
                    isThere = 1;
                }
            }
            if(isThere == 0) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
}

//Better
class Solution {
    public int[] findErrorNums(int[] nums) {
        int dup = -1;
        int miss = -1;

        for(int num: nums) {
            int indx = Math.abs(num) - 1;
            if(nums[indx] < 0) {
                dup = Math.abs(num);
            }else {
                nums[indx] *= -1;
            }
        }

        for(int i=0;i<nums.length;i++) {
            if(nums[i] > 0) {
                miss = i+1;
            }
        }

        int[] ans = new int[2];
        ans[0] = dup;
        ans[1] = miss;
        return ans;
    }
}