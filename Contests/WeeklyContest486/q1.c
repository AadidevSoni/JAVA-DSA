/*
Q1. Minimum Prefix Removal to Make Array Strictly Increasing
Solved
Medium
4 pt.
You are given an integer array nums.

You need to remove exactly one prefix (possibly empty) from nums.

Return an integer denoting the minimum length of the removed prefix such that the remaining array is strictly increasing.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

An array is said to be strictly increasing if each element is strictly greater than its previous one (if exists).©leetcode
*/

class Solution {
    public int minimumPrefixLength(int[] nums) {
        int n = nums.length;
        for(int i=n-1;i>0;i--) {
            if(nums[i] <= nums[i-1]) {
                return i;
            }
        }
        return 0;
    }
}