class Solution {
  public long finishTime(int n, int[][] edges, int[] baseTime) {
    List<List<Integer>> tree = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      tree.add(new ArrayList<>());
    }
    for (int[] edge : edges) {
      tree.get(edge[0]).add(edge[1]);
    }

    return dfs(0, tree, baseTime);
  }

  public long dfs(int node, List<List<Integer>> tree, int[] baseTime) {
    if (tree.get(node).isEmpty()) {
      return baseTime[node];
    }
    long early = Long.MAX_VALUE;
    long late = Long.MIN_VALUE;
    for (int c : tree.get(node)) {
      long time = dfs(c, tree, baseTime);
      early = Math.min(early, time);
      late = Math.max(late, time);
    }
    long ownDuration = (late - early) + baseTime[node];
    return late + ownDuration;
  }
}