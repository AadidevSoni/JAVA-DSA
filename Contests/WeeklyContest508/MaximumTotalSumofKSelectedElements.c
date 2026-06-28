class Solution {
  public long maxSum(int[] nums, int k, int mul) {
    long sum = 0;
    Arrays.sort(nums);
    int n = nums.length;
    int count = 0;
    int ind = 0;
    int[] arr = new int[k];
    for (int i = n - 1; i >= 0; i--) {
      if (count < k) {
        arr[ind] = nums[i];
        ind++;
        count++;
      }
    }
    for (int i = 0; i < k; i++) {
      if (mul > 1) {
        sum += 1L * arr[i] * mul;
      } else {
        sum += arr[i];
      }
      mul--;
    }
    return sum;
  }
}
©leetcode