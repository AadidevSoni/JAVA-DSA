class Solution {
  public int numSquares(int n) {
    List<Integer> perfect = new ArrayList<>();
    int i = 1;
    while (i * i <= n) {
      perfect.add(i * i);
      i++;
    }
    int[] dp = new int[n + 1];
    Arrays.fill(dp, -1);
    int min = getMin(n, perfect, dp);
    return min;
  }

  public static int getMin(int n, List<Integer> perfect, int[] dp) {
    if (n == 0) {
      return 0;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    int ans = Integer.MAX_VALUE;
    for (int p : perfect) {
      if (p > n) {
        break;
      }
      ans = Math.min(ans, getMin(n - p, perfect, dp) + 1);
    }
    return dp[n] = ans;
  }
}