class NumArray {

  int[] arr;

  public NumArray(int[] nums) { arr = nums; }

  public int sumRange(int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
      sum += arr[i];
    }
    return sum;
  }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */

// Optimal

class NumArray {

  int[] pre;

  public NumArray(int[] nums) {
    int n = nums.length;
    pre = new int[n + 1];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + nums[i];
    }
  }

  public int sumRange(int left, int right) {
    int sum = 0;
    return pre[right + 1] - pre[left];
  }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */