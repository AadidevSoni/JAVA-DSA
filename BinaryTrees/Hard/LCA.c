/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> lst1 = new ArrayList<>();
        List<TreeNode> lst2 = new ArrayList<>();
        getPath(root,p,lst1);
        getPath(root,q,lst2);
        int n1 = lst1.size();
        int n2 = lst2.size();
        int i = 0;
        TreeNode node = null;
        while(i < n1 && i < n2) {
            if(lst1.get(i).val == lst2.get(i).val) {
                node = lst1.get(i);
            }else {
                break;
            }
            i++;
        }
        return node;
    }

    public boolean getPath(TreeNode root, TreeNode p, List<TreeNode> lst) {
        if(root == null) {
            return false;
        }
        lst.add(root);
        if(root.val == p.val) {
            return true;
        }
        if(getPath(root.left,p,lst) || getPath(root.right,p,lst)) {
            return true;
        }
        lst.remove(lst.size()-1);
        return false;
    } 
}