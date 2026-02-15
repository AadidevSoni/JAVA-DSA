/*
Q1. Count Dominant Indices
Solved
Easy
3 pt.
You are given an integer array nums of length n.

An element at index i is called dominant if: nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])

Your task is to count the number of indices i that are dominant.

The average of a set of numbers is the value obtained by adding all the numbers together and dividing the sum by the total number of numbers.

Note: The rightmost element of any array is not dominant.

©leetcode
*/
class Solution {
    public int dominantIndices(int[] nums) {
        int count = 0;
        int n = nums.length;
        for(int i=0;i<n-1;i++) {
            float avg = average(i+1,nums);
            if(nums[i] > avg) {
                count++;
            }
        }
        return count;
    }

    public float average(int start, int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i=start;i<n;i++) {
            sum += nums[i];
        }
        float avg = (float) sum / (n - start);
        return avg;
    }
}©leetcode