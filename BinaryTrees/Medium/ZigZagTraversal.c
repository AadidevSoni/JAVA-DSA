class Solution {

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> res = new LinkedList<>();
        if (root == null){
            return res;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int flag = 0;

        while (!queue.isEmpty()) {

            int n = queue.size();
            List<Integer> sub = new LinkedList<>();
            for (int i=0;i<n;i++) {
                TreeNode node = queue.poll();
                if (flag == 0) {
                    sub.add(node.val);
                } else {
                    sub.add(0, node.val);
                }
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            res.add(sub);
            if (flag == 0) {
                flag = 1;
            } else {
                flag = 0;
            }
        }

        return res;
    }
}