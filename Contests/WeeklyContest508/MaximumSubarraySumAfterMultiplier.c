class Solution {
  public long maxSubarraySum(int[] nums, int k) {
    return Math.max(solveMul(nums, k), solveDiv(nums, k));
  }

  public static long solveMul(int[] nums, int k) {
    long case1 = Integer.MIN_VALUE;
    long case2 = Integer.MIN_VALUE;
    long case3 = Integer.MIN_VALUE;
    long res = Integer.MIN_VALUE;
    for (int n : nums) {
      long num = 1L * n * k;
      long case1new = Math.max(case1 + n, (long)n);
      long case2new = Math.max(Math.max(case1 + num, case2 + num), num);
      long case3new = Math.max(case3 + n, case1 + n);

      case1 = case1new;
      case2 = case2new;
      case3 = case3new;

      res = Math.max(res, Math.max(case1, Math.max(case2, case3)));
    }
    return res;
  }

  public static long solveDiv(int[] nums, int k) {
    long case1 = Integer.MIN_VALUE;
    long case2 = Integer.MIN_VALUE;
    long case3 = Integer.MIN_VALUE;
    long res = Integer.MIN_VALUE;

    for (int n : nums) {
      long y;
      if (n >= 0) {
        y = n / k;
      } else {
        y = -((-n) / k);
      }
      long case1new = Math.max(case1 + n, (long)n);
      long case2new = Math.max(Math.max(case1 + y, case2 + y), y);
      long case3new = Math.max(case3 + n, case2 + n);
      case1 = case1new;
      case2 = case2new;
      case3 = case3new;
      res = Math.max(res, Math.max(case1, Math.max(case2, case3)));
    }
    return res;
  }
}
©leetcode