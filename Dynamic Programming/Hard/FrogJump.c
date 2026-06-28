class Solution {
  public boolean canCross(int[] stones) {
    if (stones.length < 2 || stones[1] != 1) {
      return false;
    }

    Set<Integer> set = new HashSet<>();
    for (int s : stones) {
      set.add(s);
    }

    Map<String, Boolean> dp = new HashMap<>();

    // First jump has already been made.
    return poss(1, stones[stones.length - 1], set, dp, 1);
  }

  public static boolean poss(int stone, int last, Set<Integer> set,
                             Map<String, Boolean> dp, int k) {
    if (stone == last) {
      return true;
    }
    String key = stone + "," + k;
    if (dp.containsKey(key)) {
      return dp.get(key);
    }
    boolean ans = false;
    for (int jump = k - 1; jump <= k + 1; jump++) {
      if (jump <= 0) {
        continue;
      }
      int next = stone + jump;
      if (set.contains(next) && poss(next, last, set, dp, jump)) {
        ans = true;
        break;
      }
    }
    dp.put(key, ans);
    return ans;
  }
}