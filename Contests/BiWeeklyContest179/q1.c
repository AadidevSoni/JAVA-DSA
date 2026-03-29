/*
Q1. Minimum Absolute Difference Between Two Values
Solved
Easy
3 pt.
You are given an integer array nums consisting only of 0, 1, and 2.

A pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2.

Return the minimum absolute difference between i and j among all valid pairs. If no valid pair exists, return -1.

The absolute difference between indices i and j is defined as abs(i - j).

 

Example 1:

Input: nums = [1,0,0,2,0,1]

Output: 2

Explanation:

The valid pairs are:

(0, 3) which has absolute difference of abs(0 - 3) = 3.
(5, 3) which has absolute difference of abs(5 - 3) = 2.
Thus, the answer is 2.©leetcode
*/

class Solution {
    public int minAbsoluteDifference(int[] nums) {
        int min = Integer.MAX_VALUE;
        int last1 = -1;
        int last2 = -1;
        int n = nums.length;
        for(int i=0;i<n;i++) {
            if(nums[i] == 1) {
                last1 = i;
                if(last2 != -1) {
                    min = Math.min(min, Math.abs(i-last2));
                }
            }else if(nums[i] == 2) {
                last2 = i;
                if(last1 != -1) {
                    min = Math.min(min, Math.abs(i-last1));
                }
            }
        }
        if(min == Integer.MAX_VALUE) {
            return -1;
        }else {
            return min;
        }
    }
}©leetcode