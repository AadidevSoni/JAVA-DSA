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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaf1 = new ArrayList<>();
        List<Integer> leaf2 = new ArrayList<>();
        inorder(root1,leaf1);
        inorder(root2,leaf2);
        int n = leaf1.size();
        int m = leaf2.size();
        if(n != m) {
            return false;
        }else {
            for(int i=0;i<n;i++) {
                if(!leaf1.get(i).equals(leaf2.get(i))) {
                    return false;
                }
            }
        }
        return true;
    }

    public void inorder(TreeNode root, List<Integer> leaves) {
        if(root == null) {
            return;
        }
        inorder(root.left,leaves);
        if(root.left == null && root.right == null) {
            leaves.add(root.val);
        }
        inorder(root.right,leaves);
    }
}