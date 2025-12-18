//Brute Force 
class Solution {
    public int longestOnes(int[] nums, int k) {
        int maxLen = 0;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            int len = 0;
            int c = 0;
            for(int j=i;j<n;j++) {
                if(nums[j] == 0) {
                    c++;
                }
                if(c <= k) {
                    len = j-i+1;
                    maxLen = Math.max(maxLen,len);
                }else {
                    break;
                }
            }
        }
        return maxLen;
    }
}

//Optimal 
class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int c = 0;
        while(r < n) {
            if(nums[r] == 0) {
                c++;
            }
            while(c > k) {
                if(nums[l] == 0) {
                    c--;
                }
                l++;
            }
            if(c <= k) {
                int length = r-l+1;
                maxLen = Math.max(length, maxLen);
            }
            r++;
        }
        return maxLen;
    }
}

//Best 
class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int l = 0;
        int zeros = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeros++;
            }

            // shrink window until valid
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            maxLen = Math.max(maxLen, r - l + 1);
        }

        return maxLen;
    }
}
