class Solution {
  public int largestSumAfterKNegations(int[] nums, int k) {
    int n = nums.length;
    Arrays.sort(nums);
    int i = 0;
    while (i < n && nums[i] < 0 && k > 0) {
      nums[i] = -nums[i];
      i++;
      k--;
    }
    int sum = 0;
    int minAbs = Integer.MAX_VALUE;
    for (int j = 0; j < n; j++) {
      sum += nums[j];
      minAbs = Math.min(minAbs, Math.abs(nums[j]));
    }
    if (k % 2 == 1) {
      sum -= 2 * minAbs;
    }
    return sum;
  }
}