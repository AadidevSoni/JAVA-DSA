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

class Pair {
    TreeNode node;
    int index;
    public Pair(TreeNode node, int index) {
        this.node = node;
        this.index = index;
    }
}

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root,0));
        int width = 1;
        while(!queue.isEmpty()) {
            int sz = queue.size();
            int first = 0;
            int last = 0;
            for(int i=0;i<sz;i++) {
                Pair p = queue.poll();
                TreeNode node = p.node;
                int ind = p.index;
                if(i==0) {
                    first = ind;
                }
                if(i == sz-1) {
                    last = ind;
                }
                if(node.left != null) {
                    queue.offer(new Pair(node.left,(2*ind)+1));
                }
                if(node.right != null) {
                    queue.offer(new Pair(node.right, (2*ind) + 2));
                }
            }
            width = Math.max(width, (last-first+1));
        }
        return width;
    }
}