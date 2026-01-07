
class Solution {
    public int longestSubarray(int[] arr, int k) {

        Map<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.length; i++) {
            prefixSum += arr[i];

            // Case 1: subarray from 0 to i
            if (prefixSum == k) {
                maxLen = i + 1;
            }

            // Case 2: subarray from map index+1 to i
            if (map.containsKey(prefixSum - k)) {
                maxLen = Math.max(maxLen, i - map.get(prefixSum - k));
            }

            // Store FIRST occurrence only
            if (!map.containsKey(prefixSum)) {
                map.put(prefixSum, i);
            }
        }

        return maxLen;
    }
}
