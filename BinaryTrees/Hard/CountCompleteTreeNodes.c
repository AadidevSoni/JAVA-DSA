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
    public int countNodes(TreeNode root) {
        int res = getCount(root);
        return res;
    }
    
    public int getCount(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int lh = getHeightLeft(root);
        int rh = getHeightRight(root);
        if(lh == rh) {
            return ((1 << lh)-1);
        }else{
            return(1 + getCount(root.left) + getCount(root.right));
        }
    }

    public int getHeightLeft(TreeNode root) {
        int count = 0;
        while(root != null) {
            count++;
            root = root.left;
        }
        return count;
    }

    public int getHeightRight(TreeNode root) {
        int count = 0;
        while(root != null) {
            count++;
            root = root.right;
        }
        return count;
    }
}