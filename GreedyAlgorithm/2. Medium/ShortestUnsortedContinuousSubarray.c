class Solution {
  public int findUnsortedSubarray(int[] nums) {
    int n = nums.length;
    boolean flag = false;
    int min = Integer.MAX_VALUE;
    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[i - 1]) {
        flag = true;
      }
      if (flag) {
        min = Math.min(min, nums[i]);
      }
    }
    if (min == Integer.MAX_VALUE) {
      return 0;
    }
    int max = Integer.MIN_VALUE;
    flag = false;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] > nums[i + 1]) {
        flag = true;
      }
      if (flag) {
        max = Math.max(max, nums[i]);
      }
    }
    int l = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] > min) {
        l = i;
        break;
      }
    }
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (nums[i] < max) {
        r = i;
        break;
      }
    }
    return r - l + 1;
  }
}