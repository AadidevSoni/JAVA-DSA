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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        List<Double> avg = new ArrayList<>();
        if(root == null) {
            return avg;
        }
        while(!queue.isEmpty()) {
            int lvl = queue.size();
            long sum = 0;
            for(int i=0;i<lvl;i++) {
                if(queue.peek().left != null) {
                    queue.offer(queue.peek().left);
                }
                if(queue.peek().right != null) {
                    queue.offer(queue.peek().right);
                }
                sum += queue.poll().val;
            }
            double average = (double) sum/lvl;
            avg.add(average);
        }
        return avg;
    }
}