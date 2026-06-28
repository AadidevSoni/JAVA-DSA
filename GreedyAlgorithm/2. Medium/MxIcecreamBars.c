class Solution {
  public int maxIceCream(int[] costs, int coins) {
    int n = costs.length;
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (costs[i] > coins) {
        break;
      }
      coins -= costs[i];
      num++;
    }
    return num;
  }
}