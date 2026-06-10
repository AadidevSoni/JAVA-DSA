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
    public int getMinimumDifference(TreeNode root) {
        List<Integer> nums = new ArrayList<>();
        inorder(root,nums);
        int minDiff = Integer.MAX_VALUE;
        int n = nums.size();
        for(int i=0;i<n-1;i++) {
            minDiff = Math.min(minDiff,nums.get(i+1)-nums.get(i));
        }
        return minDiff;
    }

    public void inorder(TreeNode root, List<Integer> nums) {
        if(root == null) {
            return;
        }
        inorder(root.left,nums);
        nums.add(root.val);
        inorder(root.right,nums);
    }
}