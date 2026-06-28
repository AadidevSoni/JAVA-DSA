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
  public int findSecondMinimumValue(TreeNode root) {
    List<Integer> lst = new ArrayList<>();
    dfs(root, lst);
    Collections.sort(lst);
    int s = lst.get(0);
    int s1 = -1;
    for (int i = 0; i < lst.size(); i++) {
      if (lst.get(i) != s) {
        s1 = lst.get(i);
        break;
      }
    }
    return s1;
  }

  public static void dfs(TreeNode root, List<Integer> lst) {
    if (root == null) {
      return;
    }
    lst.add(root.val);
    dfs(root.left, lst);
    dfs(root.right, lst);
  }
}