/*
Q2. Number of Centered Subarrays
Solved
Medium
4 pt.
You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.

 

Example 1:

Input: nums = [-1,1,0]

Output: 5

Explanation:

All single-element subarrays ([-1], [1], [0]) are centered.
The subarray [1, 0] has a sum of 1, which is present in the subarray.
The subarray [-1, 1, 0] has a sum of 0, which is present in the subarray.
Thus, the answer is 5.

*/
//PREFIX SUM TO CLACULATE SUM OF SUBARRAYS
class Solution {
    public int centeredSubarrays(int[] nums) {
        int count = 0;
        int n = nums.length;
        int[] prefixSum = new int[n+1];
        for(int i=0;i<n;i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        for(int i=0;i<n;i++) {
            Set<Integer> set = new HashSet<>();
            for(int j=i;j<n;j++) {
                set.add(nums[j]);
                int sum = prefixSum[j+1] - prefixSum[i]; //sum of elements from i to j
                if(set.contains(sum)) {
                    count++;
                }
            }
        }
        return count;
    }
}