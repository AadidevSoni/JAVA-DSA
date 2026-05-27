/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) {
            return "n";
        }
        StringBuilder st = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            if(curr == null) {
                st.append("n ");
                continue;
            }
            st.append(curr.val + " ");
            queue.offer(curr.left);
            queue.offer(curr.right);
        }
        return st.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data == null || data.equals("n")) return null;
        String[] serialized = data.split(" ");
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.parseInt(serialized[0]));
        queue.add(root);
        for(int i=1;i<serialized.length;i++) {
            TreeNode curr = queue.poll();
            if(!serialized[i].equals("n")) {
                TreeNode left = new TreeNode(Integer.parseInt(serialized[i]));
                curr.left = left;
                queue.add(left);
            }
            if(!serialized[++i].equals("n")) {
                TreeNode right = new TreeNode(Integer.parseInt(serialized[i]));
                curr.right = right;
                queue.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));