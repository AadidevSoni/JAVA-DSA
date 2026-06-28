class Solution {
  public int maximumSwap(int num) {
    char[] nums = String.valueOf(num).toCharArray();
    int n = nums.length;

    for (int i = 0; i < n; i++) {
      char max = nums[i];
      int ind = i;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] >= max) {
          max = nums[j];
          ind = j;
        }
      }
      if (max > nums[i]) {
        char temp = nums[i];
        nums[i] = nums[ind];
        nums[ind] = temp;
        return Integer.parseInt(new String(nums));
      }
    }

    return num;
  }
}