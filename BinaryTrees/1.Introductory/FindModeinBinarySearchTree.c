/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
  public int[] findMode(TreeNode root) {
    HashMap<Integer, Integer> map = new HashMap<>();
    dfs(root, map);
    List<Integer> ans = new ArrayList<>();
    int maxF = 0;
    for (int f : map.values()) {
      maxF = Math.max(f, maxF);
    }
    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
      if (entry.getValue() == maxF) {
        ans.add(entry.getKey());
      }
    }
    int[] res = new int[ans.size()];
    int i = 0;
    for (int val : ans) {
      res[i] = val;
      i++;
    }
    return res;
  }

  public static void dfs(TreeNode node, HashMap<Integer, Integer> map) {
    if (node == null) {
      return;
    }
    map.put(node.val, map.getOrDefault(node.val, 0) + 1);
    dfs(node.left, map);
    dfs(node.right, map);
  }
}