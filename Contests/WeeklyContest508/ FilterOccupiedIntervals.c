class Solution {
  public List<List<Integer>> filterOccupiedIntervals(
      int[][] occupiedIntervals, int freeStart, int freeEnd) {
    Arrays.sort(occupiedIntervals, (a, b)->a[0] - b[0]);
    List<List<Integer>> ans = new ArrayList<>();
    List<int[]> merged = new ArrayList<>();
    int st = occupiedIntervals[0][0];
    int en = occupiedIntervals[0][1];
    int n = occupiedIntervals.length;

    for (int i = 1; i < n; i++) {
      if (occupiedIntervals[i][0] <= en + 1) {
        en = Math.max(en, occupiedIntervals[i][1]);
      } else {
        merged.add(new int[]{st, en});
        st = occupiedIntervals[i][0];
        en = occupiedIntervals[i][1];
      }
    }

    merged.add(new int[]{st, en});

    for (int[] interval : merged) {
      int s = interval[0];
      int e = interval[1];

      if (e < freeStart || s > freeEnd) {
        ans.add(Arrays.asList(s, e));
        continue;
      }
      if (s < freeStart) {
        ans.add(Arrays.asList(s, freeStart - 1));
      }
      if (e > freeEnd) {
        ans.add(Arrays.asList(freeEnd + 1, e));
      }
    }
    return ans;
  }
}
©leetcode