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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> inMap = new HashMap<>();
        for(int i=0;i<inorder.length;i++) {
            inMap.put(inorder[i],i);
        }
        TreeNode root = buildTree(inorder,0,inorder.length-1,preorder,0,preorder.length-1,inMap);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int inStart, int inEnd, int[] preorder, int preStart, int preEnd, Map<Integer,Integer> inMap) {
        if(inStart > inEnd || preStart > preEnd) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preStart]);
        int inRoot = inMap.get(preorder[preStart]);
        int numsLeft = inRoot - inStart;
        root.left = buildTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,inMap);
        root.right = buildTree(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,inMap);
        return root;
    }
}