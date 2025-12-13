package Arrays;

import java.util.*;

class Node {
	int data;
	Node left;
	Node right;
	
	public Node(int key) {
		data = key;
	}
}


public class Practice {
	
	public static void main(String[] args) {
		
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		
		System.out.println("Preorder: ");
		preorder(root);
		System.out.println();
		
		System.out.println("Inorder: ");
		inorder(root);
		System.out.println();
		
		System.out.println("Postorder: ");
		postorder(root);
		System.out.println();
		
		System.out.println("Level order: ");
		List<List<Integer>> levelList = levelorder(root);
		for(List<Integer> sub: levelList) {
			for(Integer num: sub) {
				System.out.print(num + " ");
			}
		}
		System.out.println();

	}
	
	static void preorder(Node root) {
		if(root == null) {
			return;
		}
		System.out.print(root.data + " ");
		preorder(root.left);
		preorder(root.right);
	}
	
	static void inorder(Node root) {
		if(root == null) {
			return;
		}
		inorder(root.left);
		System.out.print(root.data + " ");
		inorder(root.right);
	}
	
	static void postorder(Node root) {
		if(root == null) {
			return;
		}
		postorder(root.left);
		postorder(root.right);
		System.out.print(root.data + " ");
	}
	
	static List<List<Integer>> levelorder(Node root) {
		Queue<Node> queue = new LinkedList<Node>();
		List<List<Integer>> levelList = new LinkedList<List<Integer>>();
		if(root == null) return levelList;
		queue.offer(root);
		while(!queue.isEmpty()) {
			int levelNum = queue.size();
			List<Integer> subList = new LinkedList<Integer>();
			for(int i=0;i<levelNum;i++) {
				if(queue.peek().left != null) queue.offer(queue.peek().left);
				if(queue.peek().right != null) queue.offer(queue.peek().right);
				subList.add(queue.poll().data);
			}
			levelList.add(subList);
		}
		return levelList;
	}
	
	
}



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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> tree = new ArrayList<>();
        preorder(tree,root);
        return tree;
    }

    public void preorder(List<Integer> tree, TreeNode root) {
        if(root == null) {
            return;
        }
        tree.add(root.val);
        preorder(tree,root.left);
        preorder(tree,root.right);
    }
}

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        List<List<Integer>> lvlList = new LinkedList<List<Integer>>();
        if (root == null) return lvlList;
        queue.offer(root);
        while(!queue.isEmpty()) {
            int levelNum = queue.size();
            List<Integer> subList = new LinkedList<Integer>();
            for(int i=0;i<levelNum;i++) {
                if(queue.peek().left != null) queue.offer(queue.peek().left);
                if(queue.peek().right != null) queue.offer(queue.peek().right);
                subList.add(queue.poll().val);
            }
            lvlList.add(subList);
        }
        return lvlList;
    }
}