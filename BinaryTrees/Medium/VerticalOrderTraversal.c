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
class Tuple {
    TreeNode node;
    int row;
    int col;
    public Tuple(TreeNode node, int row, int col) {
        this.node = node;
        this.row = row;
        this.col = col;
    }
}
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        //col -> row -> sorted values
        //TreeMap and PriorityQueue keeps sorted order keys
        TreeMap<Integer, TreeMap<Integer,PriorityQueue<Integer>>> map = new TreeMap<>();
        Queue<Tuple> queue = new LinkedList<>();
        queue.offer(new Tuple(root,0,0));
        while(!queue.isEmpty()) {
            Tuple t = queue.poll();
            TreeNode node = t.node;
            int row = t.row;
            int col = t.col;

            map.putIfAbsent(col, new TreeMap<>());
            map.get(col).putIfAbsent(row, new PriorityQueue<>());
            map.get(col).get(row).offer(node.val);
            if(node.left != null) {
                queue.offer(new Tuple(node.left, row+1, col-1));
            }
            if(node.right != null) {
                queue.offer(new Tuple(node.right, row+1, col+1));
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(TreeMap<Integer, PriorityQueue<Integer>> rows: map.values()) {
            List<Integer> lst = new ArrayList<>();
            for(PriorityQueue<Integer> pq: rows.values()) {
                while(!pq.isEmpty()) {
                    lst.add(pq.poll());
                }
            }
            ans.add(lst);
        }
        return ans;
    }
}