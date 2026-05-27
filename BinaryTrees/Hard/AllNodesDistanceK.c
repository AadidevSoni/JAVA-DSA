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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parents = new HashMap<>();
        markParents(parents,root);
        Map<TreeNode, Boolean> visited = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(target);
        visited.put(target, true);
        int level = 0;
        while(!queue.isEmpty()) {
            int sz = queue.size();
            if(level == k) {
                break;
            }
            level++;
            for(int i=0;i<sz;i++) {
                TreeNode curr = queue.poll();
                if(curr.left != null && visited.get(curr.left) == null) {
                    visited.put(curr.left, true);
                    queue.offer(curr.left);
                }
                if(curr.right != null && visited.get(curr.right) == null) {
                    visited.put(curr.right, true);
                    queue.offer(curr.right);
                }
                if(parents.get(curr) != null && visited.get(parents.get(curr)) == null) {
                    visited.put(parents.get(curr), true);
                    queue.offer(parents.get(curr));
                }
            }
        }
        List<Integer> res = new LinkedList<>();
        while(!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            res.add(curr.val);
        }
        return res;
    }

    public static void markParents(Map<TreeNode, TreeNode> parents, TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            if(curr.left != null) {
                parents.put(curr.left, curr);
                queue.offer(curr.left);
            }
            if(curr.right != null) {
                parents.put(curr.right, curr);
                queue.offer(curr.right);
            }
        }
    }
}