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
		
		Node start = root.left;
		Map<Node,Node> parent = new HashMap<>();
		getParents(root,parent);
		Set<Node> visited = new HashSet<>();
		Queue<Node> queue = new LinkedList<>();
		queue.offer(start);
		visited.add(start);
		int time = 0;
		while(!queue.isEmpty()) {
			int sz = queue.size();
			boolean burned = false;
			for(int i=0;i<sz;i++) {
				Node curr = queue.poll();
				if(curr.left != null && !visited.contains(curr.left)) {
					visited.add(curr.left);
					burned = true;
					queue.offer(curr.left);
				}
				if(curr.right != null && !visited.contains(curr.right)) {
					visited.add(curr.right);
					burned = true;
					queue.offer(curr.right);
				}
				if(parent.get(curr) != null && !visited.contains(parent.get(curr))) {
					visited.add(parent.get(curr));
					queue.offer(parent.get(curr));
					burned = true;
				}
			}
			if(burned)time++;
		}
		System.out.println("Min time to burn the tree: " + time);
		
    }
	
	public static void getParents(Node root, Map<Node, Node> parent) {
		Queue<Node> queue = new LinkedList<>();
		queue.offer(root);
		while(!queue.isEmpty()) {
			Node curr = queue.poll();
			if(curr.left != null) {
				parent.put(curr.left, curr);
				queue.offer(curr.left);
			}
			if(curr.right != null) {
				parent.put(curr.right, curr);
				queue.offer(curr.right);
			}
		}
	}
	
}
	


