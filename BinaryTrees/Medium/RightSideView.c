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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null) {
            return res;
        }
        rightV(root,0,res);
        return res;
    }

    public void rightV(TreeNode root, int level, List<Integer> res) {
        if(root == null) {
            return;
        }
        if(level == res.size()) {
            res.add(root.val);
        }
        rightV(root.right,level+1,res);
        rightV(root.left,level+1,res);
    }
}