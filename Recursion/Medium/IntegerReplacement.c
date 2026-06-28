class Solution {
  public int integerReplacement(int n) {
    long ans = getMin((long)n);
    return (int)ans;
  }

  public static long getMin(long n) {
    if (n == 1) {
      return 0;
    }
    if (n % 2 == 0) {
      return 1 + getMin(n / 2);
    } else {
      return (1 + Math.min(getMin(n + 1), getMin(n - 1)));
    }
  }
}